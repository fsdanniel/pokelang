# **Especificações da Linguagem: PokéLang**

## 

## **Alfabeto**

Letras: a-z, A-Z (usadas em palavras-chave e identificadores)



Dígitos: 0-9 (usados em números inteiros)



Símbolos de Operação: +, -, \*, /, %, =



Símbolos de Pontuação: (, ), {, }, \[, ], ;, ,



Símbolos de Comentário: # (inicia um comentário de linha)



Símbolos de String: " (delimita o início e o fim de uma string)



Caracteres Ignorados (Whitespace): Espaço, Tab (\\t), Nova Linha (\\n)



## **Palavras-Chave (Tokens Reservados)**



Tipos de Dados:



pokeball: Declara uma variável do tipo inteiro.



pc: Declara um vetor (array) de inteiros.



Entrada/Saída (I/O):



captura: Lê um valor do usuário e armazena em uma variável.



arremesse: Imprime um ou mais valores/strings para o usuário.



Estruturas de Controle (Lógica):



batalha: Inicia um bloco condicional (equivalente a if).



fugir: Bloco opcional para a condição falsa (equivalente a else).



jornada: Inicia um laço de repetição condicional (equivalente a while).



ginasio: Inicia um laço de repetição iterativo (equivalente a for).



## **Operadores**



Operadores Aritméticos:



\+ (Soma)



\- (Subtração)



\* (Multiplicação)



/ (Divisão inteira)



% (Resto da divisão)



Operador de Atribuição:



= (Armazena o valor da direita na variável da esquerda)



Operadores Lógicos (baseados em palavras-chave):



dupla: E lógico (equivalente a \&\&)



troca: OU lógico (equivalente a ||)



desconhecido: NÃO lógico (equivalente a !)



Operadores de Comparação (baseados em palavras-chave):



maisForteQue: Maior que (>)



maisFracoQue: Menor que (<)



forteOuIgual: Maior ou igual (>=)



fracoOuIgual: Menor ou igual (<=)



identico: Igual a (==)



diferente: Diferente de (!=)



## **Comandos para Apresentação**



**ls -l**



**bison -d pokelang.y (Cria pokelang.tab.c e pokelang.tab.h)**



**flex pokelang.l (Cria lex.yy.c)**



**gcc pokelang.tab.c lex.yy.c -o meu\_compilador -lfl (Cria o arquivo binário meu\_compilador)**



**./meu\_compilador < teste\_completo.pokelang**



**./meu\_compilador < teste\_completo.pokelang > saida.rap**



**./raposeitor saida.rap**

