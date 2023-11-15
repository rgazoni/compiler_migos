#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"
#include "generate.h"
#include "address.h"

namespace Parser{
    void variables_analyzer(){
        Lexical lexical = Lexical();
        int var_count = 0;

        do{
            if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                //pesquisa_duplicvar_tabela(token.lexema)
                //se não encontrou duplicidade
                //então inicio
                    //insere_tabela(token.lexema, "variavel", ",")
                    var_count++;
                    any_variables.push_back(lexical.get_current_token().lexem);
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

        generate("", "ALLOC", Address::getAddress(), to_string(var_count));

        lexical.next_token();
        Parser::type_analyzer();
    }

}
