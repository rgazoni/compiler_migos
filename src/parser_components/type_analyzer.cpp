#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "symbol_table.h"

namespace Parser{
    void type_analyzer(){
        Lexical lexical = Lexical();
        Symbol_table symbol_table;

        if(lexical.get_current_token().symbol != Symbols::SINTEIRO && lexical.get_current_token().symbol != Symbols::SBOOLEANO){
            raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
        }else{
            symbol_table.update_variable_type(lexical.get_current_token().lexem);
            //coloca_tipo_tabela(token->lexem);
            lexical.next_token();
        }
    }
}
