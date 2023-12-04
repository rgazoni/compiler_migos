#include "parser.h"
#include <iostream>
#include "lexical/lexical_analyzer.h"
#include "expression_builder.h"
#include "dev_env/tests.h"
#include "parser.h"

#include "ui/mainwindow.h"
#include "ui/application.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
    // Lexical lexical = Lexical();
    // Expr_builder expr_builder = Expr_builder();
    auto application = Application::create();

    // bool is_file_provided = false;
    // char* file_path;

    // for(int i = 0 ; i < argc ; i++){
    //     std::string arg = argv[i];

    //     if(arg == "--dev"|| arg == "-D"){
    //         //Call tests functions from dev_env directory
    //         expression();
    //     }

    //     if((arg == "--file" || arg == "-f" ) && i+1 <= argc){
    //         is_file_provided = true;
    //         file_path = argv[i+1];
    //     }
    // }

    // if(is_file_provided)
    //     parser(file_path);
    // else
    //     std::cout << "To run parser, a file must be provided with --file or -f." << std::endl;

    // for(Expr_token token : expr_builder.expr_array){
    //     std::cout << "lexem: " << token.lexem << std::endl;
    // }

    const int status = application->run(argc, argv);
    return status;
}
