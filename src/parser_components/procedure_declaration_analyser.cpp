#include "lexical_analyser.h"
#include "general_parser.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

namespace Parser{
    void procedure_declaration_analyser(){
        Lexical lexical = Lexical();

        lexical.next_token();
        // nível := “L” (marca ou novo galho)
        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            // pesquisa_declproc_tabela(token.lexema)
            // se não encontrou
            // então início
                //     Insere_tabela(token.lexema,”procedimento”,nível, rótulo)
                //                 {guarda na TabSimb}
                //     Gera(rotulo,NULL, ́  ́, ́  ́)
                //             {CALL irá buscar este rótulo na TabSimb}
                //     rotulo:= rotulo+1
                        lexical.next_token();
                        if(lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA){
                            Parser::snippet_analyser();
                        } else{
                            // error
                            raiseError(Error::EXPECTED_SEMICOLON);
                        }
                //     fim
                // senão ERRO
        }else{
            // error
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
        // DESEMPILHA OU VOLTA NÍVEL
    }
}