#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"

namespace Parser{
    void type_analyser(Token* token){
        if(token->symbol != Symbols::SINTEIRO && token->symbol != Symbols::SBOOLEANO){
            raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
        }else{
            //coloca_tipo_tabela(token->lexem);
            //lexic(token);
            
            token = Lexical::get_token();
        }
    }
}
