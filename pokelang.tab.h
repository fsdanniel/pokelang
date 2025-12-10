/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_POKELANG_TAB_H_INCLUDED
# define YY_YY_POKELANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "pokelang.y"

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

#line 85 "pokelang.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_IDENTIFICADOR = 258,     /* TOKEN_IDENTIFICADOR  */
    TOKEN_NUMERO = 259,            /* TOKEN_NUMERO  */
    TOKEN_STRING = 260,            /* TOKEN_STRING  */
    TOKEN_KW_POKEBALL = 261,       /* TOKEN_KW_POKEBALL  */
    TOKEN_KW_PC = 262,             /* TOKEN_KW_PC  */
    TOKEN_KW_CAPTURAR = 263,       /* TOKEN_KW_CAPTURAR  */
    TOKEN_KW_ARREMESSE = 264,      /* TOKEN_KW_ARREMESSE  */
    TOKEN_KW_IF = 265,             /* TOKEN_KW_IF  */
    TOKEN_KW_ELSE = 266,           /* TOKEN_KW_ELSE  */
    TOKEN_KW_WHILE = 267,          /* TOKEN_KW_WHILE  */
    TOKEN_KW_FOR = 268,            /* TOKEN_KW_FOR  */
    TOKEN_ABRE_PARENTESE = 269,    /* TOKEN_ABRE_PARENTESE  */
    TOKEN_FECHA_PARENTESE = 270,   /* TOKEN_FECHA_PARENTESE  */
    TOKEN_ABRE_CHAVE = 271,        /* TOKEN_ABRE_CHAVE  */
    TOKEN_FECHA_CHAVE = 272,       /* TOKEN_FECHA_CHAVE  */
    TOKEN_ABRE_COLCHETE = 273,     /* TOKEN_ABRE_COLCHETE  */
    TOKEN_FECHA_COLCHETE = 274,    /* TOKEN_FECHA_COLCHETE  */
    TOKEN_PONTO_VIRGULA = 275,     /* TOKEN_PONTO_VIRGULA  */
    TOKEN_VIRGULA = 276,           /* TOKEN_VIRGULA  */
    TOKEN_OP_ATRIBUICAO = 277,     /* TOKEN_OP_ATRIBUICAO  */
    TOKEN_OP_MAIOR = 278,          /* TOKEN_OP_MAIOR  */
    TOKEN_OP_MENOR = 279,          /* TOKEN_OP_MENOR  */
    TOKEN_OP_MAIOR_IGUAL = 280,    /* TOKEN_OP_MAIOR_IGUAL  */
    TOKEN_OP_MENOR_IGUAL = 281,    /* TOKEN_OP_MENOR_IGUAL  */
    TOKEN_OP_IGUAL = 282,          /* TOKEN_OP_IGUAL  */
    TOKEN_OP_DIFERENTE = 283,      /* TOKEN_OP_DIFERENTE  */
    TOKEN_OP_E = 284,              /* TOKEN_OP_E  */
    TOKEN_OP_OU = 285,             /* TOKEN_OP_OU  */
    TOKEN_OP_NAO = 286,            /* TOKEN_OP_NAO  */
    TOKEN_OP_SOMA = 287,           /* TOKEN_OP_SOMA  */
    TOKEN_OP_SUB = 288,            /* TOKEN_OP_SUB  */
    TOKEN_OP_MULT = 289,           /* TOKEN_OP_MULT  */
    TOKEN_OP_DIV = 290,            /* TOKEN_OP_DIV  */
    TOKEN_OP_MOD = 291,            /* TOKEN_OP_MOD  */
    TOKEN_ERRO_LEXICO = 292        /* TOKEN_ERRO_LEXICO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "pokelang.y"

    char *stringValue;
    struct ASTNode *node;

#line 144 "pokelang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_POKELANG_TAB_H_INCLUDED  */
