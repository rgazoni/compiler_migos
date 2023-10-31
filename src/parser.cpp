#include <iostream>
#include "expression_builder.h"
#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "expr_token.h"
#include "semantic_analyzer.h"

std::string enum_to_string(Type token){
    switch(token){
        case Type::Bool: return "bool";
        case Type::Int: return "int";
        case Type::Arit_unary: return "unary";
        case Type::Logical_unary: return "l_unary";
        default: return "Unknown";
    }
}

int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();
    Expr_builder expr_builder = Expr_builder();
    // Record record;
    // Symbol_table symbol_table = Symbol_table();
    lexical.open_file(argv);

    std::vector<Expr_token> array;


    // // Token* token;
    expr_builder.add_to_array(Expr_token("(", Type::Int));
    expr_builder.add_to_array(Expr_token("x", Type::Int));
    expr_builder.add_to_array(Expr_token("+", Type::Int));
    expr_builder.add_to_array(Expr_token("7", Type::Int));
    expr_builder.add_to_array(Expr_token("*", Type::Int));
    expr_builder.add_to_array(Expr_token("5", Type::Int));
    expr_builder.add_to_array(Expr_token("div", Type::Int));
    expr_builder.add_to_array(Expr_token("(", Type::Int));
    expr_builder.add_to_array(Expr_token("30", Type::Int));
    expr_builder.add_to_array(Expr_token("+", Type::Int));
    expr_builder.add_to_array(Expr_token("y", Type::Int));
    expr_builder.add_to_array(Expr_token(")", Type::Int));
    expr_builder.add_to_array(Expr_token("<=", Type::Int));
    expr_builder.add_to_array(Expr_token("(", Type::Int));
    expr_builder.add_to_array(Expr_token("x", Type::Int));
    expr_builder.add_to_array(Expr_token("*", Type::Int));
    expr_builder.add_to_array(Expr_token("a", Type::Int));
    expr_builder.add_to_array(Expr_token("+", Type::Int));
    expr_builder.add_to_array(Expr_token("2", Type::Int));
    expr_builder.add_to_array(Expr_token(")", Type::Int));
    expr_builder.add_to_array(Expr_token(")", Type::Int));
    expr_builder.add_to_array(Expr_token("e", Type::Int));
    expr_builder.add_to_array(Expr_token("(", Type::Int));
    expr_builder.add_to_array(Expr_token("z", Type::Int));
    expr_builder.add_to_array(Expr_token(">", Type::Int));
    expr_builder.add_to_array(Expr_token("0", Type::Int));
    expr_builder.add_to_array(Expr_token(")", Type::Int));
    
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));


    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token("<", Type::Bool));
    // // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));

    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));

   
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Int));
    // expr_builder.add_to_array(Expr_token("c", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("d", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("t", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Int));
    // expr_builder.add_to_array(Expr_token("f", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("g", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("h", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("i", Type::Int));

    std::cout << "--------------------------" << std::endl;

    array = expr_builder.infix_to_postfix();

    std::cout << "--------------------------" << std::endl;

    for(Expr_token element : array){
        std::cout << "lexem: " << element.lexem << "  " << enum_to_string(element.type) << std::endl;
    }
        std::cout << std::endl;


    Type resultado = Semantic_analyzer().validateExpression(array);
    if (resultado != Type::Unknown) {
        std::cout << "O tipo resultante da expressão é: ";
        if (resultado == Type::Int) {
            std::cout << "int";
        } else if (resultado == Type::Bool) {
            std::cout << "bool";
        }
        std::cout << std::endl;
    }
    

    // rotulo := 1
    lexical.next_token();
    
    if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
        lexical.next_token();
        
        if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {            
            // insere_tabela(token->lexema,"nomedeprograma", "", "")
            lexical.next_token();
            if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                // analisa_bloco
                Parser::snippet_analyzer();
                // lexical.next_token();

                if (lexical.get_current_token().symbol == Symbols::SPONTO) {
                    lexical.next_token();
                    std::cout << lexical.get_current_token().lexem << std::endl;
                    if (lexical.get_current_token().symbol !=
                        Symbols::END_OF_FILE)
                        raiseError(Error::EXPECTED_EOF);
                } else {
                    raiseError(Error::EXPECTED_DOT);
                }
            } else {
                raiseError(Error::EXPECTED_SEMICOLON);
            }
        } else {
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
    } else {
        raiseError(Error::EXPECTED_RESERVED_WORD_PROGRAMA);
    }

    lexical.close_file();

    return 0;
}
