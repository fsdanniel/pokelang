%code requires {
    #include <stdio.h>
    #include <stdlib.h>
    
    /* ESTRUTURAS DA AST */

    typedef enum {
        NODE_PROGRAMA, NODE_BLOCO, NODE_DECLARACAO, NODE_ATRIBUICAO,
        NODE_CAPTURA, NODE_ARREMESSE, NODE_IF, NODE_WHILE, NODE_FOR,
        NODE_CONST_INT, NODE_VAR, NODE_VETOR_ACESSO, NODE_STRING,
        NODE_OP_SOMA, NODE_OP_SUB, NODE_OP_MULT, NODE_OP_DIV, NODE_OP_MOD,
        NODE_OP_MAIOR, NODE_OP_MENOR, NODE_OP_MAIOR_IGUAL, NODE_OP_MENOR_IGUAL,
        NODE_OP_IGUAL, NODE_OP_DIFERENTE, NODE_OP_E, NODE_OP_OU, NODE_OP_NAO
    } NodeType;

    typedef struct ASTNode {
        NodeType type;
        char *value;
        struct ASTNode *left;
        struct ASTNode *right;
        struct ASTNode *extra;
        struct ASTNode *next;
    } ASTNode;

    /* PROTÓTIPOS */

    ASTNode* new_node(NodeType type, ASTNode *left, ASTNode *right);
    ASTNode* new_leaf(NodeType type, char *value);
    ASTNode* new_triple_node(NodeType type, ASTNode *c1, ASTNode *c2, ASTNode *c3);
    
    char* gera_codigo(ASTNode *node);
    
    void sym_insert(char *name, int type, int size);
    struct Symbol* sym_check_usage(char *name);
}

%{
#include <string.h>

extern int yylex(); 
void yyerror(const char *s);
extern char *yytext;
extern int yyline;

/* TABELA DE SÍMBOLOS */

#define TYPE_UNDEFINED 0
#define TYPE_INTEGER   1
#define TYPE_VECTOR    2

typedef struct Symbol {
    char *name;
    int type;
    int size;
    int addr; 
} Symbol;

#define MAX_SYMBOLS 100
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
int varCount = 0; 
%}

%union {
    char *stringValue;
    struct ASTNode *node;
}

/* Tokens */
%token <stringValue> TOKEN_IDENTIFICADOR
%token <stringValue> TOKEN_NUMERO
%token <stringValue> TOKEN_STRING

%token TOKEN_KW_POKEBALL TOKEN_KW_PC TOKEN_KW_CAPTURAR TOKEN_KW_ARREMESSE
%token TOKEN_KW_IF TOKEN_KW_ELSE TOKEN_KW_WHILE TOKEN_KW_FOR

%token TOKEN_ABRE_PARENTESE TOKEN_FECHA_PARENTESE TOKEN_ABRE_CHAVE TOKEN_FECHA_CHAVE
%token TOKEN_ABRE_COLCHETE TOKEN_FECHA_COLCHETE TOKEN_PONTO_VIRGULA TOKEN_VIRGULA
%token TOKEN_OP_ATRIBUICAO

/* Tipos AST */

%type <node> programa lista_comandos comando
%type <node> declaracao comando_captura comando_atribuicao comando_selecao comando_jornada comando_ginasio comando_arremesse
%type <node> expressao acesso_variavel lista_argumentos bloco_comandos else_opcional atribuicao_opcional expressao_opcional
%type <node> erro_sintatico 

/* Precedência Padrão */
%right TOKEN_OP_NAO
%left  TOKEN_OP_E TOKEN_OP_OU
%left  TOKEN_OP_IGUAL TOKEN_OP_DIFERENTE
%left  TOKEN_OP_MENOR TOKEN_OP_MAIOR TOKEN_OP_MENOR_IGUAL TOKEN_OP_MAIOR_IGUAL
%left  TOKEN_OP_SOMA TOKEN_OP_SUB
%left  TOKEN_OP_MULT TOKEN_OP_DIV TOKEN_OP_MOD

%token TOKEN_OP_MAIOR TOKEN_OP_MENOR TOKEN_OP_MAIOR_IGUAL TOKEN_OP_MENOR_IGUAL
%token TOKEN_OP_IGUAL TOKEN_OP_DIFERENTE TOKEN_OP_E TOKEN_OP_OU TOKEN_OP_NAO
%token TOKEN_OP_SOMA TOKEN_OP_SUB TOKEN_OP_MULT TOKEN_OP_DIV TOKEN_OP_MOD
%token TOKEN_ERRO_LEXICO

%%
/*  REGRAS GRAMATICAIS */

programa: lista_comandos
    {
        $$ = new_node(NODE_PROGRAMA, $1, NULL);
        printf("; --- Inicio do Codigo Assembly Raposeitor ---\n");
        gera_codigo($$);
        printf("; --- Fim do Codigo ---\n");
    }
    ;

lista_comandos: /* Vazia */ 
    { $$ = NULL; }
    | lista_comandos comando
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            ASTNode *p = $1;
            while (p->next != NULL) p = p->next;
            p->next = $2;
            $$ = $1;
        }
    }
    ;

comando: declaracao { $$ = $1; }
    | comando_captura { $$ = $1; }
    | comando_atribuicao { $$ = $1; }
    | comando_selecao { $$ = $1; }
    | comando_arremesse { $$ = $1; }
    | comando_jornada { $$ = $1; }
    | comando_ginasio { $$ = $1; }
    | erro_sintatico { yyerrok; $$ = NULL; }
    ;

declaracao: TOKEN_KW_POKEBALL TOKEN_IDENTIFICADOR TOKEN_PONTO_VIRGULA
    {
        sym_insert($2, TYPE_INTEGER, 0);
        $$ = NULL; 
    }
    | TOKEN_KW_PC TOKEN_IDENTIFICADOR TOKEN_ABRE_COLCHETE TOKEN_NUMERO TOKEN_FECHA_COLCHETE TOKEN_PONTO_VIRGULA
    {
        sym_insert($2, TYPE_VECTOR, atoi($4));
        $$ = NULL;
    }
    ;

acesso_variavel: TOKEN_IDENTIFICADOR
    {
        Symbol *s = sym_check_usage($1);
        if (s->type != TYPE_INTEGER) { fprintf(stderr, "Erro tipo: %s e vetor.\n", s->name); exit(1); }
        $$ = new_leaf(NODE_VAR, $1);
    }
    | TOKEN_IDENTIFICADOR TOKEN_ABRE_COLCHETE expressao TOKEN_FECHA_COLCHETE
    {
        Symbol *s = sym_check_usage($1);
        if (s->type != TYPE_VECTOR) { fprintf(stderr, "Erro tipo: %s e int.\n", s->name); exit(1); }
        $$ = new_node(NODE_VETOR_ACESSO, new_leaf(NODE_VAR, $1), $3); 
    }
    ;

comando_atribuicao: acesso_variavel TOKEN_OP_ATRIBUICAO expressao TOKEN_PONTO_VIRGULA
    {
        $$ = new_node(NODE_ATRIBUICAO, $1, $3);
    }
    ;

comando_selecao: TOKEN_KW_IF TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE bloco_comandos else_opcional
    {
        $$ = new_triple_node(NODE_IF, $3, $5, $6);
    }
    ;

else_opcional: /* Vazio */ 
    { $$ = NULL; }
    | TOKEN_KW_ELSE bloco_comandos 
    { $$ = $2; }
    ;

comando_jornada: TOKEN_KW_WHILE TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE bloco_comandos
    {
        $$ = new_node(NODE_WHILE, $3, $5);
    }
    ;

comando_ginasio: TOKEN_KW_FOR TOKEN_ABRE_PARENTESE atribuicao_opcional TOKEN_PONTO_VIRGULA expressao_opcional TOKEN_PONTO_VIRGULA atribuicao_opcional TOKEN_FECHA_PARENTESE bloco_comandos
    {
        $$ = new_triple_node(NODE_FOR, $3, $5, $9);
        if ($7 != NULL && $$->extra != NULL) {
             ASTNode *body = $$->extra;
             ASTNode *cmds = body->left;
             if (cmds == NULL) body->left = $7;
             else {
                 while (cmds->next != NULL) cmds = cmds->next;
                 cmds->next = $7;
             }
        }
    }
    ;

atribuicao_opcional: /* Vazio */ { $$ = NULL; }
    | acesso_variavel TOKEN_OP_ATRIBUICAO expressao { $$ = new_node(NODE_ATRIBUICAO, $1, $3); }
    ;

expressao_opcional: /* Vazio */ { $$ = NULL; }
    | expressao { $$ = $1; }
    ;

comando_captura: TOKEN_KW_CAPTURAR TOKEN_ABRE_PARENTESE acesso_variavel TOKEN_FECHA_PARENTESE TOKEN_PONTO_VIRGULA
    {
        $$ = new_node(NODE_CAPTURA, $3, NULL);
    }
    ;

comando_arremesse: TOKEN_KW_ARREMESSE TOKEN_ABRE_PARENTESE lista_argumentos TOKEN_FECHA_PARENTESE TOKEN_PONTO_VIRGULA
    {
        $$ = new_node(NODE_ARREMESSE, $3, NULL);
    }
    ;

lista_argumentos: expressao
    {
        $$ = $1;
    }
    | lista_argumentos TOKEN_VIRGULA expressao
    {
        ASTNode *p = $1;
        while (p->next != NULL) p = p->next;
        p->next = $3;
        $$ = $1;
    }
    ;

bloco_comandos: TOKEN_ABRE_CHAVE lista_comandos TOKEN_FECHA_CHAVE
    {
        $$ = new_node(NODE_BLOCO, $2, NULL);
    }
    ;

expressao: TOKEN_NUMERO { $$ = new_leaf(NODE_CONST_INT, $1); }
    | acesso_variavel   { $$ = $1; }
    | TOKEN_STRING      { $$ = new_leaf(NODE_STRING, $1); }
    | expressao TOKEN_OP_SOMA expressao { $$ = new_node(NODE_OP_SOMA, $1, $3); }
    | expressao TOKEN_OP_SUB expressao  { $$ = new_node(NODE_OP_SUB, $1, $3); }
    | expressao TOKEN_OP_MULT expressao { $$ = new_node(NODE_OP_MULT, $1, $3); }
    | expressao TOKEN_OP_DIV expressao  { $$ = new_node(NODE_OP_DIV, $1, $3); }
    | expressao TOKEN_OP_MOD expressao  { $$ = new_node(NODE_OP_MOD, $1, $3); }
    | expressao TOKEN_OP_MAIOR expressao { $$ = new_node(NODE_OP_MAIOR, $1, $3); }
    | expressao TOKEN_OP_MENOR expressao { $$ = new_node(NODE_OP_MENOR, $1, $3); }
    | expressao TOKEN_OP_MAIOR_IGUAL expressao { $$ = new_node(NODE_OP_MAIOR_IGUAL, $1, $3); }
    | expressao TOKEN_OP_MENOR_IGUAL expressao { $$ = new_node(NODE_OP_MENOR_IGUAL, $1, $3); }
    | expressao TOKEN_OP_IGUAL expressao { $$ = new_node(NODE_OP_IGUAL, $1, $3); }
    | expressao TOKEN_OP_DIFERENTE expressao { $$ = new_node(NODE_OP_DIFERENTE, $1, $3); }
    | expressao TOKEN_OP_E expressao { $$ = new_node(NODE_OP_E, $1, $3); }
    | expressao TOKEN_OP_OU expressao { $$ = new_node(NODE_OP_OU, $1, $3); }
    | TOKEN_OP_NAO expressao { $$ = new_node(NODE_OP_NAO, $2, NULL); }
    | TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE { $$ = $2; }
    ;

erro_sintatico: TOKEN_PONTO_VIRGULA { $$ = NULL; }
              | TOKEN_FECHA_CHAVE   { $$ = NULL; }
              ;

%%
/* IMPLEMENTAÇÃO EM C */

Symbol* sym_lookup(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) return &symbolTable[i];
    }
    return NULL;
}

void sym_insert(char *name, int type, int size) {
    if (sym_lookup(name) == NULL) {
        symbolTable[symbolCount].name = strdup(name);
        symbolTable[symbolCount].type = type;
        symbolTable[symbolCount].size = size;
        symbolTable[symbolCount].addr = varCount;
        if (type == TYPE_VECTOR) varCount += size;
        else varCount++;
        symbolCount++;
    }
}

struct Symbol* sym_check_usage(char *name) {
    Symbol *s = sym_lookup(name);
    if (s == NULL) {
        fprintf(stderr, "[ERRO SEMANTICO] Linha %d: Variavel '%s' nao declarada.\n", yyline, name);
        exit(1);
    }
    return s;
}

ASTNode* new_node(NodeType type, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = NULL;
    node->left = left;
    node->right = right;
    node->extra = NULL;
    node->next = NULL;
    return node;
}

ASTNode* new_leaf(NodeType type, char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    node->extra = NULL;
    node->next = NULL;
    return node;
}

ASTNode* new_triple_node(NodeType type, ASTNode *c1, ASTNode *c2, ASTNode *c3) {
    ASTNode *node = new_node(type, c1, c2);
    node->extra = c3;
    return node;
}

int tempCount = 0;
int labelCount = 0;

char* new_temp() {
    char* temp = (char*)malloc(20);
    sprintf(temp, "%%t%d", tempCount++);
    return temp;
}

char* new_label() {
    char* lbl = (char*)malloc(20);
    sprintf(lbl, "R%d", labelCount++);
    return lbl;
}

char* gera_codigo(ASTNode *node) {
    if (node == NULL) return NULL;

    char *v1, *v2, *temp, *lbl_true, *lbl_false, *lbl_end;
    Symbol *sym;

    switch(node->type) {
        case NODE_PROGRAMA:
        case NODE_BLOCO:
            {
                ASTNode *aux = node->left;
                while (aux != NULL) {
                    gera_codigo(aux);
                    aux = aux->next;
                }
            }
            return NULL;

        case NODE_ATRIBUICAO:
            v2 = gera_codigo(node->right);
            if (node->left->type == NODE_VAR) {
                sym = sym_lookup(node->left->value);
                printf("  mov %%r%d, %s\n", sym->addr, v2);
            } else if (node->left->type == NODE_VETOR_ACESSO) {
                sym = sym_lookup(node->left->left->value);
                v1 = gera_codigo(node->left->right);
                /* CORREÇÃO: Usar literal (%d) não registrador (%%r%d) para a base */
                printf("  store %s, %s(%d)\n", v2, v1, sym->addr);
            }
            return NULL;

        case NODE_VAR:
            sym = sym_lookup(node->value);
            temp = (char*)malloc(20);
            sprintf(temp, "%%r%d", sym->addr);
            return temp;

        case NODE_CONST_INT:
            return node->value;

        case NODE_VETOR_ACESSO:
            sym = sym_lookup(node->left->value);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            /* CORREÇÃO: Usar literal (%d) não registrador (%%r%d) para a base */
            printf("  load %s, %s(%d)\n", temp, v2, sym->addr);
            return temp;

        case NODE_OP_SOMA:
        case NODE_OP_SUB:
        case NODE_OP_MULT:
        case NODE_OP_DIV:
        case NODE_OP_MOD:
            v1 = gera_codigo(node->left);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            char *op = "add";
            if (node->type == NODE_OP_SUB) op = "sub";
            if (node->type == NODE_OP_MULT) op = "mult";
            if (node->type == NODE_OP_DIV) op = "div";
            if (node->type == NODE_OP_MOD) op = "mod";
            printf("  %s %s, %s, %s\n", op, temp, v1, v2);
            return temp;

        case NODE_OP_MAIOR:
        case NODE_OP_MENOR:
        case NODE_OP_IGUAL:
        case NODE_OP_DIFERENTE:
        case NODE_OP_E:
        case NODE_OP_OU:
        case NODE_OP_MAIOR_IGUAL:
        case NODE_OP_MENOR_IGUAL:
            v1 = gera_codigo(node->left);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            char *cmd = "equal";
            if (node->type == NODE_OP_MAIOR) cmd = "greater";
            if (node->type == NODE_OP_MENOR) cmd = "less";
            if (node->type == NODE_OP_DIFERENTE) cmd = "diff";
            if (node->type == NODE_OP_E) cmd = "and";
            if (node->type == NODE_OP_OU) cmd = "or";
            if (node->type == NODE_OP_MAIOR_IGUAL) cmd = "greatereq";
            if (node->type == NODE_OP_MENOR_IGUAL) cmd = "lesseq";
            printf("  %s %s, %s, %s\n", cmd, temp, v1, v2);
            return temp;

        case NODE_IF:
            lbl_false = new_label();
            lbl_end = new_label();
            v1 = gera_codigo(node->left);
            printf("  jf %s, %s\n", v1, lbl_false);
            gera_codigo(node->right);
            if (node->extra != NULL) printf("  jump %s\n", lbl_end);
            printf("  label %s\n", lbl_false);
            if (node->extra != NULL) {
                gera_codigo(node->extra);
                printf("  label %s\n", lbl_end);
            }
            return NULL;

        case NODE_WHILE:
            lbl_true = new_label();
            lbl_end = new_label();
            printf("  label %s\n", lbl_true);
            v1 = gera_codigo(node->left);
            printf("  jf %s, %s\n", v1, lbl_end);
            gera_codigo(node->right);
            printf("  jump %s\n", lbl_true);
            printf("  label %s\n", lbl_end);
            return NULL;
            
        case NODE_FOR:
            lbl_true = new_label();
            lbl_end = new_label();
            if (node->left != NULL) gera_codigo(node->left);
            printf("  label %s\n", lbl_true);
            if (node->right != NULL) {
                v1 = gera_codigo(node->right);
                printf("  jf %s, %s\n", v1, lbl_end);
            }
            gera_codigo(node->extra);
            printf("  jump %s\n", lbl_true);
            printf("  label %s\n", lbl_end);
            return NULL;

        case NODE_CAPTURA:
            if (node->left->type == NODE_VAR) {
                sym = sym_lookup(node->left->value);
                printf("  read %%r%d\n", sym->addr);
            }
            else if (node->left->type == NODE_VETOR_ACESSO) {
                temp = new_temp();
                printf("  read %s\n", temp);
                sym = sym_lookup(node->left->left->value); /* Nome */
                v1 = gera_codigo(node->left->right);       /* Indice */
                printf("  store %s, %s(%d)\n", temp, v1, sym->addr);
            }
            return NULL;

        case NODE_ARREMESSE:
            {
                ASTNode *arg = node->left;
                while (arg != NULL) {
                    if (arg->type == NODE_STRING) {
                        printf("  printf %s\n", arg->value);
                    } else {
                        v1 = gera_codigo(arg);
                        printf("  printv %s\n", v1);
                    }
                    arg = arg->next;
                }
            }
            return NULL;
            
        case NODE_STRING:
            return node->value;

        default:
            return NULL;
    }
}

int main(int argc, char **argv) {
    if (yyparse() == 0) {
        /* Sucesso */
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s\n", yyline, s);
}
