# Tree Project Structure

## Compiler

### SRC
- main.cpp<br>
- parser.cpp<br>
- parser.h<br>

#### Checker
- symbol_table.cpp<br>
- symbol_table.h<br>

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
- assignment_analyzer.cpp<br>
- atrib_call_procedure.cpp<br>
- command_analyzer.cpp<br>
- conditional_analyzer.cpp<br>
- et_variable_analyzer.cpp<br>
- expression_analyzer.cpp<br>
- factor_analyzer.cpp<br>
- function_caller_analyzer.cpp<br>
- function_declaration_analyzer.cpp<br>
- parser_components.h<br>
- procedure_caller_analyzer.cpp<br>
- procedure_declaration_analyser.cpp<br>
- read_analyzer.cpp<br>
- simple_command_analyzer.cpp<br>
- simple_expression_analyzer.cpp<br>
- snippet_analyzer.cpp<br>
- subroutine_analyzer.cpp<br>
- term_analyzer.cpp<br>
- type_analyzer.cpp<br>
- variables_analyzer.cpp<br>
- while_analyzer.cpp<br>
- write_analyzer.cpp<br>

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
