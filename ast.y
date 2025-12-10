%code requires {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
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

    /* Protótipos */
    ASTNode* new_node(NodeType type, ASTNode *left, ASTNode *right);
    ASTNode* new_leaf(NodeType type, char *value);
    ASTNode* new_triple_node(NodeType type, ASTNode *c1, ASTNode *c2, ASTNode *c3);
    void print_ast(ASTNode *node, int level);
    
    void sym_insert(char *name, int type, int size);
    struct Symbol* sym_check_usage(char *name);
}

%{
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
} Symbol;

#define MAX_SYMBOLS 100
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
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
/* REGRAS GRAMATICAIS */

programa: lista_comandos
    {
        $$ = $1;
        printf("--- Arvore Sintatica Construida com Sucesso! ---\n");
        print_ast($$, 0);
    }
    ;

lista_comandos: /* Vazia */ 
    { $$ = NULL; }
    | lista_comandos comando
    {
        /* Recursão à esquerda. Ajuste dos ponteiros next */
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
        $$ = NULL; /* Declaração não gera nó executável */
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
        if (s->type != TYPE_INTEGER) { fprintf(stderr, "Erro: %s e vetor.\n", s->name); exit(1); }
        $$ = new_leaf(NODE_VAR, $1);
    }
    | TOKEN_IDENTIFICADOR TOKEN_ABRE_COLCHETE expressao TOKEN_FECHA_COLCHETE
    {
        Symbol *s = sym_check_usage($1);
        if (s->type != TYPE_VECTOR) { fprintf(stderr, "Erro: %s e int.\n", s->name); exit(1); }
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
        /* $6 aqui é o resultado do else_opcional (nó do else ou NULL) */
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
        /* Simplificação: Ignorando init e step na árvore por enquanto para focar no funcionamento */
        $$ = new_node(NODE_FOR, NULL, $9); 
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

/* FUNÇÕES C */

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

void print_ast(ASTNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    
    switch(node->type) {
        case NODE_PROGRAMA: printf("[PROGRAMA]\n"); break;
        case NODE_BLOCO:    printf("[BLOCO]\n"); break;
        case NODE_ATRIBUICAO: printf("[=]\n"); break;
        case NODE_OP_SOMA:     printf("[+]\n"); break;
        case NODE_OP_SUB:      printf("[-]\n"); break;
        case NODE_OP_MULT:     printf("[*]\n"); break;
        case NODE_OP_DIV:      printf("[/]\n"); break;
        case NODE_OP_MAIOR:    printf("[>]\n"); break;
        case NODE_OP_MENOR:    printf("[<]\n"); break;
        
        case NODE_CONST_INT: printf("[INT: %s]\n", node->value); break;
        case NODE_VAR:      printf("[VAR: %s]\n", node->value); break;
        case NODE_IF:       printf("[BATALHA]\n"); break;
        case NODE_WHILE:    printf("[JORNADA]\n"); break;
        case NODE_FOR:      printf("[GINASIO]\n"); break;
        case NODE_STRING:   printf("[STRING: %s]\n", node->value); break;
        case NODE_ARREMESSE: printf("[ARREMESSE]\n"); break;
        case NODE_CAPTURA:  printf("[CAPTURA]\n"); break;
        default:            printf("[NODE Tipo: %d]\n", node->type);
    }

    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
    print_ast(node->extra, level + 1);
    if (node->next != NULL) print_ast(node->next, level);
}

int main(int argc, char **argv) {
    if (yyparse() == 0) {
        printf("--- Compilacao Finalizada com Sucesso ---\n");
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s\n", yyline, s);
}
