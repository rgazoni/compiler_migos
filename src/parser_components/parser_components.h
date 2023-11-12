#ifndef general_parser_h
#define general_parser_h

extern int label;

namespace Parser {
    void et_variable_analyzer();
    void factor_analyzer();
    void snippet_analyzer();
    void type_analyzer();
    void variables_analyzer();
    void procedure_declaration_analyzer();
    void subroutine_analyzer();
    void procedure_declaration_analyzer();
    void function_declaration_analyzer();
    void term_analyzer();
    void expression_analyzer();
    void simple_expression_analyzer();
    void command_analyzer();
    void simple_command_analyzer();
    void while_analyzer();
    void atribution_and_call_procedure();
    void write_analyzer();
    void read_analyzer();
    void conditional_analyzer();
    void assignment_analyzer();
    void procedure_caller_analyzer();
    void function_caller_analyzer();
}  
#endif

