# Tree Project Structure

## Compiler

### SRC
- main.cpp<br>
- parser.cpp<br>
- parser.h<br>

#### Checker
- symbol_table.cpp: Contém as classes Symbol_table e Record que possuem métodos de inserção, remoção e busca de funções, procedimentos e variáveis  
- symbol_table.h: Contém os atributos e protótipos dos métodos que serão usados pelas classes Symbol_table e Record

#### Code Generator
- address.cpp: variáveis globais que são usadas para alocar e desalocar espaço na memória<br>
- address.h: cabeçalho de address.cpp que permite as variáveis sejam usadas em outros arquivos<br>
- generate.cpp: gera o código de máquina (assembly) e faz um pós processamento que muda os valores dos rótulos para as linhas atuais<br>
- generate.h: cabeçalho de generate.cpp que permite as variáveis e funções sejam usadas em outros arquivos<br>
- label.cpp: variável global que recebe os rótulos<br>
- label.h: cabeçalho de label.cpp que permite as variáveis e funções sejam usadas em outros arquivos<br>

#### Dev Environment
- tests.cpp<br>
- tests.h<br>

#### Error
- Errors.cpp<br>
- Errors.h<br>


#### Expression Builder
Expr_token.h: cabeçalho de Expr_token.cpp que permite o uso do token criado (campos: lexema, endereço e símbolo)<br>
expression_builder.cpp: realiza a conversão de infixa para pós-fixa<br>
expression_builder.h: cabeçalho do expression_builder.cpp que permite montar e converter expressão em outros arquivos<br>
semantic_analyzer.cpp: realiza a análise semântica da expressão convertida<br>
semantic_analyzer.h: cabeçalho do expression_builder.cpp que permite a análise semantica<br>
types_table.h<br>

#### Lexical
lexical_analyzer.cpp<br>
lexical_analyzer.h<br>

#### Parser Components  (Contém o Sintático)
- assignment_analyzer.cpp: Contém o algoritmo para análise de atribuição<br> 
- atrib_call_procedure.cpp: Analise de chamada de procedimento<br>
- command_analyzer.cpp: Analisa comando utilizado<br>
- conditional_analyzer.cpp: Analise de comandos condicionais (Se, enquanto)<br>
- et_variable_analyzer.cpp: Analisa a parte de declaração de variavéis do programa<br>
- expression_analyzer.cpp: Analise de expressões em certos comandos<br>
- factor_analyzer.cpp: Analisa fator (Função, Procedimento, Variavél)<br>
- function_caller_analyzer.cpp: Analise de chamada de função<br>
- function_declaration_analyzer: Analise de declaração de funçãocpp<br>
- parser_components.h: Header file para reutilização de elementos do código pelo parser_components.cpp<br>
- procedure_caller_analyzer.cpp: Analise de chamada de procedimento<br>
- procedure_declaration_analyser.cpp: Analise de declaração de procedimento<br>
- read_analyzer.cpp: Analise do comando "leia"<br>
- simple_command_analyzer.cpp: Analise de comandos simples ("se","enquanto")<br>
- simple_expression_analyzer.cpp: Analise de expressões simples<br>
- snippet_analyzer.cpp: Algoritmo para análise de bloco de código<br>
- subroutine_analyzer.cpp: Analise de subrotinas do programa<br>
- term_analyzer.cpp: Analise de termo<br>
- type_analyzer.cpp: Analise de tipo (Inteiro ou Booleano)<br>
- variables_analyzer.cpp: Análise de variavéis do programa<br>
- while_analyzer.cpp: Algoritmo para análise do comando "quanto"<br>
- write_analyzer.cpp: Algoritmo para análise do comando "escreva"<br>

#### Token
- Token.cpp<br>
- Token.h<br>
symbols.cpp<br>
symbols.h<br>

#### UI
application.cpp<br>
application.h<br>
fileexplorer.cpp<br>
fileexplorer.h<br>
mainwindow.cpp<br>
mainwindow.h<br>


## Virtual Machine
CMakeLists.txt  -> <br>

### SRC
main.cpp<br>

#### UI
application.cpp<br>
application.h<br>
fileexplorer.cpp<br>
fileexplorer.h<br>
mainwindow.cpp<br>
mainwindow.h<br>

#### Virtual Machine
DVM.cpp<br>
DVM.h<br>
