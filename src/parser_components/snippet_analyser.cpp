#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser
{
        void snippet_analyser()
        {
                Lexical lexical = Lexical();

                // lexical.next_token();
                lexical.next_token();
                // std::cout << lexical.get_current_token().lexem << std::endl;
                Parser::et_variable_analyser();
                // std::cout << lexical.get_current_token().lexem << std::endl;

                Parser::subroutine_analyser();
                // commands_analyser
                // Parser::command_analyser();
        }
}
