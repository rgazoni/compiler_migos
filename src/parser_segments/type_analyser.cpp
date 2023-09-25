#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

int type_analyser(){
    if(token->symbol != Symbols::SINTEIRO && token->symbol != Symbols::SBOOLEANO){
        raiseError(Error::IS_NOT_BOOLEAN_OR_INT);
    }else{
        //coloca_tipo_tabela(token->lexem);
    }
    //lexic(token);
}