#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"

namespace Parser{
    void type_analyser(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol != Symbols::SINTEIRO && lexical.get_current_token().symbol != Symbols::SBOOLEANO){
            raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
        }else{
            //coloca_tipo_tabela(token->lexem);
            lexical.next_token();
        }
    }
}
