#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

int variables_analyser(){
    do{
        if(token->symbol == Symbols::SIDENTIFICADOR){
            //pesquisa_duplicvar_tabela(token.lexema)
            //se não encontrou duplicidade
            //então inicio
                //insere_tabela(token.lexema, "variavel", ",")
                //lexic(token)
                if(token->symbol == Symbols::SVIRGULA || token->symbol == Symbols::SDOISPONTOS){
                    if(token->symbol == Symbols::SVIRGULA){
                        //lexic(token)
                        if(token->symbol == Symbols::SDOISPONTOS){
                            raiseError(Error::SYMBOL_EQUALS_COLON);
                        }
                    }
                }else{
                    raiseError(Error::IS_NOT_COMMA_OR_COLON);

                }
        }else{
            raiseError(Error::IS_NOT_IDENTIFIER);
        }

    }while(token->symbol != Symbols::SDOISPONTOS);

    //lexic(token)
    //type_analyser
    return 0;
}
