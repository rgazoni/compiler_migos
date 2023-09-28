#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser{
    void variables_analyser(){
        Lexical lexical = Lexical();

        do{
            if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                //pesquisa_duplicvar_tabela(token.lexema)
                //se não encontrou duplicidade
                //então inicio
                    //insere_tabela(token.lexema, "variavel", ",")
                    lexical.next_token();
                    if(lexical.get_current_token().symbol == Symbols::SVIRGULA || lexical.get_current_token().symbol == Symbols::SDOISPONTOS){
                        if(lexical.get_current_token().symbol == Symbols::SVIRGULA){
                            lexical.next_token();

                            if(lexical.get_current_token().symbol == Symbols::SDOISPONTOS){
                                raiseError(Error::NOT_EXPECTED_COLON);
                            }
                        }
                    }else{
                        raiseError(Error::EXPECTED_COMMA_OR_COLON);
                    }
            }else{
                raiseError(Error::EXPECTED_IDENTIFIER);
            }

        }while(lexical.get_current_token().symbol != Symbols::SDOISPONTOS);

        lexical.next_token();
        Parser::type_analyser();
    }

}
