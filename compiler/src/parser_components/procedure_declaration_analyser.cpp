#include "lexical_analyzer.h"
#include "parser_components.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "symbol_table.h"
#include "label.h"
#include "generate.h"
#include "address.h"

namespace Parser{
    void procedure_declaration_analyzer(){
        Lexical lexical = Lexical();
        Symbol_table symbol_table;
        lexical.next_token();
        // nível := “L” (marca ou novo galho)
        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            Record record(lexical.get_current_token().lexem, "SPROCEDIMENTO", true, std::stoi(Label::getLabel()));
            // cout << "label: " << std::stoi(Label::getLabel()) << endl;
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
        
        string var_count = to_string(Symbol_table::dalloc_var);
        int current_address = stoi(Address::getAddress()) - stoi(var_count);
        generate("", "DALLOC", to_string(current_address), var_count);

        Address::setAddress(stoi(Address::getAddress()) - stoi(var_count));
        // cout << "rrrrr: " << Address::getVarCount() - stoi(var_count) << endl;
        Address::setVarCount(Address::getVarCount() - stoi(var_count));

        generate("", "RETURN", "", "");

        // DESEMPILHA OU VOLTA NÍVEL
    }
}