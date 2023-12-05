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
- address.cpp<br>
- address.h<br>
- generate.cpp<br>
- generate.h<br>
- label.cpp<br>
- label.h<br>

#### Dev Environment
tests.cpp<br>
tests.h<br>

#### Error
Errors.cpp<br>
Errors.h<br>


#### Expression Builder
Expr_token.h<br>
expression_builder.cpp<br>
expression_builder.h<br>
semantic_analyzer.cpp<br>
semantic_analyzer.h<br>
types_table.h<br>

#### Lexical
lexical_analyzer.cpp<br>
lexical_analyzer.h<br>

#### Parser Components
assignment_analyzer.cpp<br>
atrib_call_procedure.cpp<br>
command_analyzer.cpp<br>
conditional_analyzer.cpp<br>
et_variable_analyzer.cpp<br>
expression_analyzer.cpp<br>
factor_analyzer.cpp<br>
function_caller_analyzer.cpp<br>
function_declaration_analyzer.cpp<br>
parser_components.h<br>
procedure_caller_analyzer.cpp<br>
procedure_declaration_analyser.cpp<br>
read_analyzer.cpp<br>
simple_command_analyzer.cpp<br>
simple_expression_analyzer.cpp<br>
snippet_analyzer.cpp<br>
subroutine_analyzer.cpp<br>
term_analyzer.cpp<br>
type_analyzer.cpp<br>
variables_analyzer.cpp<br>
while_analyzer.cpp<br>
write_analyzer.cpp<br>

#### Token
Token.cpp<br>
Token.h<br>
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
