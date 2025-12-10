# **PokeLang Compiler: Compilador para a Máquina Virtual Raposeitor**

**Este projeto consiste no desenvolvimento de um compilador completo para a linguagem PokéLang, uma linguagem de programação temática baseada no universo Pokémon. O compilador traduz o código-fonte de alto nível da PokéLang para o código Assembly de 3 endereços da arquitetura Raposeitor.**

**O projeto aborda todas as etapas clássicas de compilação: Análise Léxica, Sintática, Semântica e Geração de Código, utilizando as ferramentas Flex e Bison.**



## **Panorama Geral do Trabalho**

**O objetivo principal foi criar uma nova linguagem do zero e implementar um tradutor capaz de convertê-la para uma linguagem de máquina simplificada.**

**Linguagem Fonte:** PokéLang (C-like, tipagem estática, temática Pokémon).

**Linguagem Alvo:** Assembly Raposeitor (Código de 3 endereços).

**Implementação:** C/C++ via WSL (Linux).

**Ferramentas:** Flex (Scanner) e Bison (Parser).



### **Funcionalidades da Linguagem**

**A PokéLang suporta:**

**Variáveis Inteiras: pokeball (int).**

**Vetores: pc (arrays).**

**Controle de Fluxo: batalha (if), fugir (else), jornada (while), ginasio (for).**

**Entrada/Saída: captura (read), arremesse (print).**

**Operações: Aritmética completa, lógica booleana e comparações relacionais (maisForteQue, identico, etc.).**



## **Arquitetura do Compilador**

O compilador opera em quatro fases distintas e sequenciais. Abaixo, um resumo da funcionalidade e do papel de cada uma:



### **Análise Léxica (O Scanner)**

Sua função é ler o fluxo bruto de caracteres do código-fonte e agrupá-los em unidades significativas chamadas Tokens.

Funcionalidade: Remove espaços em branco, comentários e identifica se uma sequência de caracteres é uma palavra-chave (batalha), um identificador (pikachu), um número (150) ou um símbolo ({, +).

Implementação: Feita no arquivo pokelang.l usando expressões regulares.



### **Análise Sintática (O Parser)**

Verifica a estrutura gramatical. Ele recebe a sequência de tokens do analisador léxico e valida se eles estão organizados em uma ordem que faz sentido na linguagem (Gramática Livre de Contexto).

Funcionalidade: Constrói a estrutura hierárquica do programa. É aqui que se define que um if deve ter parênteses, uma condição e um bloco de comandos. Se a ordem estiver errada (ex: if { condicao }), ele rejeita o código.

Conceito de Parser: Um Parser (Analisador Sintático) é um componente de software que interpreta a estrutura de dados de entrada (neste caso, tokens) e constrói uma estrutura de dados na memória (frequentemente uma árvore) conforme uma gramática formal. No nosso caso, usamos um parser LALR(1) gerado pelo Bison.



### **Análise Semântica**

Verifica o significado e a coerência do código. Mesmo que a frase esteja gramaticalmente correta, ela pode não fazer sentido lógico.

Funcionalidade:

Verifica se variáveis foram declaradas antes do uso.

Impede redeclaração de variáveis.

Checa compatibilidade de tipos (ex: impede usar um vetor inteiro como se fosse uma variável simples).

Implementação: Utiliza uma Tabela de Símbolos (hash ou vetor de structs) integrada ao arquivo pokelang.y para rastrear o escopo e atributos de cada identificador.



### **Geração de Código e AST**

Traduz a representação interna do programa para a linguagem da máquina alvo.

Funcionalidade (AST): Durante a análise sintática, construímos uma Árvore Sintática Abstrata (AST). A AST é uma representação em árvore onde cada nó é uma operação (Soma, Atribuição, If) e os filhos são os operandos.

Geração: Uma função recursiva percorre a AST e emite instruções equivalentes em Assembly Raposeitor (ex: add, mov, jump, jf) para cada nó visitado.



## **Ferramentas Utilizadas**



#### **Flex (Fast Lexical Analyzer Generator)**

O Flex é uma ferramenta que gera analisadores léxicos.

Nós escrevemos regras no formato Expressão Regular -> Ação em C.

O Flex compila essas regras em um arquivo C (lex.yy.c) que contém uma máquina de estados finitos capaz de reconhecer os padrões definidos de forma extremamente eficiente.



#### **Bison (GNU Parser Generator)**

O Bison é um gerador de analisadores sintáticos de propósito geral (compatível com Yacc).

Nós descrevemos a gramática da PokéLang usando a notação BNF (Backus-Naur Form).

O Bison converte essa gramática em um programa C (pokelang.tab.c) que usa um autômato de pilha para processar os tokens enviados pelo Flex.

O Bison também gerencia a precedência de operadores (para resolver conflitos como o "Dangling Else").



## **Análise da Implementação**



##### **Arquivo pokelang.l (Scanner)**

Define o vocabulário. A parte crucial é o gerenciamento do valor dos tokens (yylval).

Para tokens simples (palavras-chave), apenas retorna o "Tipo" (ex: TOKEN\_KW\_IF).

Para tokens com conteúdo (Identificadores e Números), ele duplica a string encontrada (strdup(yytext)) e a armazena em yylval.stringValue para que o Bison possa acessar esse valor posteriormente.



##### **Arquivo pokelang.y (Parser + Semântica + Gerador)**

Este é a parte central do compilador. Ele está dividido em três partes lógicas:

###### **Definições (Cabeçalho):**

Define a struct ASTNode: A estrutura da árvore (tipo do nó, valor, filhos).

Define a struct Symbol e a Tabela de Símbolos: Para guardar nomes e endereços de memória (%r0, %r1) das variáveis.

###### **Gramática (Regras):**

Define como os tokens formam comandos.

Ações Semânticas: Ao encontrar uma declaração, insere na tabela. Ao encontrar um uso, verifica na tabela.

Construção da AST: Em vez de executar o código imediatamente, cada regra cria um novo nó na árvore (new\_node), conectando-o aos nós filhos.

###### **Geração de Código (Rodapé):**

Função gera\_codigo(ASTNode \*node): Percorre a árvore completa recursivamente.

Gerencia temporários (new\_temp -> %t0) e rótulos (new\_label -> R0) para traduzir estruturas de alto nível (como while) em saltos condicionais de baixo nível (jf, jump).



## **Como Compilar e Executar**

#### **Pré-requisitos**

**GCC (Compilador C)**

**Flex**

**Bison**



#### **Passo a Passo**

**Gerar o Parser (Bison):**

bison -d pokelang.y

Gera pokelang.tab.c e pokelang.tab.h.



**Gerar o Scanner (Flex):**

flex pokelang.l

Gera lex.yy.c.



**Compilar o Executável:**

gcc pokelang.tab.c lex.yy.c -o meu\_compilador -lfl



**Executar (Compilar um arquivo PokéLang):**

./meu\_compilador < programa\_exemplo.pokelang > saida.rap



**Rodar no Raposeitor:**

./raposeitor saida.rap







