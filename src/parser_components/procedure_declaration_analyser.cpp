#include "lexical_analyzer.h"
#include "parser_components.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "symbol_table.h"
#include "label.h"
#include "generate.h"

namespace Parser{
    void procedure_declaration_analyzer(){
        Lexical lexical = Lexical();
        Symbol_table symbol_table;
        lexical.next_token();
        // nível := “L” (marca ou novo galho)
        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            Record record(lexical.get_current_token().lexem, "SPROCEDIMENTO", true, std::stoi(Label::getLabel()));
            symbol_table.insert_record_procedure(&record);
            // pesquisa_declproc_tabela(token.lexema)
            // se não encontrou
            // então início
                //     Insere_tabela(token.lexema,”procedimento”,nível, rótulo)
                //                 {guarda na TabSimb}
                //     Gera(rotulo,NULL, ́  ́, ́  ́)
                //             {CALL irá buscar este rótulo na TabSimb}
                //     rotulo:= rotulo+1
            generate(Label::getLabel(), "NULL", "", "");
            Label::incrementLabel();

            lexical.next_token();
            if(lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA){
                Parser::snippet_analyzer();
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
        symbol_table.pop_scope();
        // DESEMPILHA OU VOLTA NÍVEL
    }
}