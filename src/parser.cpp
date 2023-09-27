#include "error/Errors.h"
#include "lexical_analyser.h"
#include "symbols.h"
#include <iostream>


int main(int argc, char *argv[]) {
    Lexical* lexical = new Lexical();

    lexical->open_file(argv);
    // Token* token;

    //rotulo := 1
    lexical->next_token();

    std::cout << lexical->get_current_token().lexem << std::endl;

    if (lexical->get_current_token().symbol == Symbols::SPROGRAMA) {

        lexical->next_token();
        if (lexical->get_current_token().symbol == Symbols::SIDENTIFICADOR) {

            //insere_tabela(token->lexema,"nomedeprograma", "", "")
            
            lexical->next_token();
            if (lexical->get_current_token().symbol == Symbols::SPONTO_VIRGULA) {

                //analisa_bloco
                // snippet_analyser();
                lexical->next_token();

                if (lexical->get_current_token().symbol == Symbols::SPONTO) {
                    lexical->next_token();
                    if (lexical->get_current_token().symbol != Symbols::END_OF_FILE) raiseError(Error::EXPECTED_EOF);
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

    lexical->close_file();
    
    return 0;
}

// void snippet_analyser(){
//     Lexical::next_token();
//     et_variable_analyser();

//     //subroutine_analyser
//     //commands_analyser
    
// }

// void et_variable_analyser(){
    
//     if(Lexical::get_current_token().symbol == Symbols::SVAR){
//         Lexical::next_token();

//         if(Lexical::get_current_token().symbol == Symbols::SIDENTIFICADOR){
//             while(Lexical::get_current_token().symbol == Symbols::SIDENTIFICADOR){
//                 //variable_analyser

//                 std::cout << "aaa: " + Lexical::get_current_token().lexem << std::endl;
//                 variables_analyser();
//                 std::cout << "bbb: " + Lexical::get_current_token().lexem << std::endl;

//                 // Lexical::next_token();
//                 if(Lexical::get_current_token().symbol == Symbols::SPONTO_VIRGULA){
//                     Lexical::next_token();

//                 }else{

//                     raiseError(Error::EXPECTED_SEMICOLON);
//                 }
//             }
//         }else{
//             raiseError(Error::EXPECTED_IDENTIFIER);
//         }
//     }
// }

// void variables_analyser(){
//     do{
//         if(Lexical::get_current_token().symbol == Symbols::SIDENTIFICADOR){
//             //pesquisa_duplicvar_tabela(token->lexema)
//             //se não encontrou duplicidade
//             //então inicio
//                 //insere_tabela(token->lexema, "variavel", ",")
//                 Lexical::next_token();
//                 if(Lexical::get_current_token().symbol == Symbols::SVIRGULA || Lexical::current_token->symbol == Symbols::SDOISPONTOS){
//                     if(Lexical::get_current_token().symbol == Symbols::SVIRGULA){
//                         Lexical::next_token();

//                         if(Lexical::get_current_token().symbol == Symbols::SDOISPONTOS){
//                             raiseError(Error::NOT_EXPECTED_COLON);
//                         }
//                     }
//                 }else{
//                     raiseError(Error::EXPECTED_COMMA_OR_COLON);
//                 }
//         }else{
//             raiseError(Error::EXPECTED_IDENTIFIER);
//         }

//     }while(Lexical::get_current_token().symbol != Symbols::SDOISPONTOS);

//     Lexical::next_token();
//     type_analyser();
//     //lexic(token)
//     //type_analyser
// }

// void type_analyser(){
//     if(Lexical::get_current_token().symbol != Symbols::SINTEIRO && Lexical::current_token->symbol != Symbols::SBOOLEANO){
//         raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
//     }else{
//         //coloca_tipo_tabela(Lexical::get_current_token().lexem);
//         //lexic(token);
        
//         Lexical::next_token();
//         std::cout << "ccc: " + Lexical::get_current_token().lexem << std::endl;

//     }
// }
