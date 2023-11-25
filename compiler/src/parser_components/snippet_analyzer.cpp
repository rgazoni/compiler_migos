#include "lexical_analyzer.h"
#include "parser_components.h"

namespace Parser
{
        void snippet_analyzer()
        {
                Lexical lexical = Lexical();

                // lexical.next_token();
                lexical.next_token();
                // std::cout << lexical.get_current_token().lexem << std::endl;
                Parser::et_variable_analyzer();
                // std::cout << lexical.get_current_token().lexem << std::endl;
                Parser::subroutine_analyzer();
                // commands_analyzer
                Parser::command_analyzer();
        }
}
