// #include "symbols.h"
// #include "./error/Errors.h"
// #include <fstream>
// #include <iostream>
// #include "lexical_analyser.h"
// #include "general_parser.h"

// namespace Parser{
//     void variables_analyser(Token *token){

//         do{
//             if(token->symbol == Symbols::SIDENTIFICADOR){
//                 //pesquisa_duplicvar_tabela(token.lexema)
//                 //se não encontrou duplicidade
//                 //então inicio
//                     //insere_tabela(token.lexema, "variavel", ",")
//                     token = Lexical::get_token();
//                     if(token->symbol == Symbols::SVIRGULA || token->symbol == Symbols::SDOISPONTOS){
//                         if(token->symbol == Symbols::SVIRGULA){
//                             token = Lexical::get_token();

//                             if(token->symbol == Symbols::SDOISPONTOS){
//                                 raiseError(Error::NOT_EXPECTED_COLON);
//                             }
//                         }
//                     }else{
//                         raiseError(Error::EXPECTED_COMMA_OR_COLON);
//                     }
//             }else{
//                 raiseError(Error::EXPECTED_IDENTIFIER);
//             }

//         }while(token->symbol != Symbols::SDOISPONTOS);

//         token = Lexical::get_token(token);
//         Parser::type_analyser(token);
//         //lexic(token)
//         //type_analyser
//     }

// }
