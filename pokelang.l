%{
#include <stdio.h>
#include <string.h>
#include "pokelang.tab.h"

int yyline = 1;
%}

%%

[ \t\r]+        { /* Ignora */ }
"\n"            { yyline++; }
"#".*		{ /* Ignora */ }

"pokeball"      { return TOKEN_KW_POKEBALL; }
"pc"            { return TOKEN_KW_PC; }
"captura"       { return TOKEN_KW_CAPTURAR; }
"arremesse"     { return TOKEN_KW_ARREMESSE; }
"batalha"       { return TOKEN_KW_IF; }
"fugir"         { return TOKEN_KW_ELSE; }
"jornada"       { return TOKEN_KW_WHILE; }
"ginasio"       { return TOKEN_KW_FOR; }

"maisForteQue"  { return TOKEN_OP_MAIOR; }
"maisFracoQue"  { return TOKEN_OP_MENOR; }
"forteOuIgual"  { return TOKEN_OP_MAIOR_IGUAL; }
"fracoOuIgual"  { return TOKEN_OP_MENOR_IGUAL; }
"identico"      { return TOKEN_OP_IGUAL; }
"diferente"     { return TOKEN_OP_DIFERENTE; }
"dupla"         { return TOKEN_OP_E; }
"troca"         { return TOKEN_OP_OU; }
"desconhecido"  { return TOKEN_OP_NAO; }

[0-9]+          { 
                    yylval.stringValue = strdup(yytext); 
                    return TOKEN_NUMERO; 
                }

\"(\\.|[^"\\])*\" { 
                    yylval.stringValue = strdup(yytext);
                    return TOKEN_STRING; 
                }

[a-zA-Z_][a-zA-Z0-9_]* { 
                    yylval.stringValue = strdup(yytext);
                    return TOKEN_IDENTIFICADOR; 
                }

"("             { return TOKEN_ABRE_PARENTESE; }
")"             { return TOKEN_FECHA_PARENTESE; }
"{"             { return TOKEN_ABRE_CHAVE; }
"}"             { return TOKEN_FECHA_CHAVE; }
"["             { return TOKEN_ABRE_COLCHETE; }
"]"             { return TOKEN_FECHA_COLCHETE; }
";"             { return TOKEN_PONTO_VIRGULA; }
","             { return TOKEN_VIRGULA; }
"="             { return TOKEN_OP_ATRIBUICAO; }
"+"             { return TOKEN_OP_SOMA; }
"-"             { return TOKEN_OP_SUB; }
"*"             { return TOKEN_OP_MULT; }
"/"             { return TOKEN_OP_DIV; }
"%"             { return TOKEN_OP_MOD; }

.               { 
                    fprintf(stderr, "[ERRO LEXICO] Linha %d: Caractere inesperado '%s'\n", yyline, yytext); 
                    return TOKEN_ERRO_LEXICO;
                }

%%
int yywrap() { return 1; }
