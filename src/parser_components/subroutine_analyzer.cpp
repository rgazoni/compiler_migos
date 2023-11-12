#include "lexical_analyzer.h"
#include "parser_components.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "label.h"
#include "generate.h"

namespace Parser{
    void subroutine_analyzer(){
        Lexical lexical = Lexical();
        // Def. auxrot, flag inteiro
        // Início
        // flag = 0
        // if (token.simbolo = sprocedimento) ou
        //                 (token.simbolo = sfunção)
        //     então início
        //         auxrot:= rotulo
        //         GERA( ́  ́,JMP,rotulo, ́  ́) {Salta sub-rotinas}
        //         rotulo:= rotulo + 1
        //         flag = 1
        //     fim

        std::string auxrot;
        int flag;

        flag = 0;
        if(lexical.get_current_token().symbol == Symbols::SPROCEDIMENTO || lexical.get_current_token().symbol == Symbols::SFUNCAO){
            auxrot = Label::getLabel();
            generate("", "JMP", Label::getLabel(), "");
            Label::incrementLabel();
            flag = 1;
        }

        while (lexical.get_current_token().symbol == Symbols::SPROCEDIMENTO || 
            lexical.get_current_token().symbol == Symbols::SFUNCAO) {
            if(lexical.get_current_token().symbol == Symbols::SPROCEDIMENTO){
                //procedure_declaration_analyzer
                Parser::procedure_declaration_analyzer();
            }else{
                // fucntion_declaration_analyzer
                Parser::function_declaration_analyzer();
            }

            if(lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA){
                lexical.next_token();
            }else{
                //erro
                raiseError(Error::EXPECTED_SEMICOLON);
            }
        }
        // if flag = 1
        //     então Gera(auxrot,NULL, ́  ́, ́  ́) {início do principal}
        // fim

        if(flag == 1){
            generate(auxrot, "NULL", "", "");
        }
    }
}