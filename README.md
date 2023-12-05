# Tree project structure

compiler_migos
├── compiler
│   └── src
│       ├── checker
│       │   ├── symbol_table.cpp
│       │   └── symbol_table.h
│       ├── code_generator
│       │   ├── address.cpp
│       │   ├── address.h
│       │   ├── generate.cpp
│       │   ├── generate.h
│       │   ├── label.cpp
│       │   └── label.h
│       ├── dev_env
│       │   ├── tests.cpp
│       │   └── tests.h
│       ├── error
│       │   ├── Errors.cpp
│       │   └── Errors.h
│       ├── expression_builder
│       │   ├── Expr_token.h
│       │   ├── expression_builder.cpp
│       │   ├── expression_builder.h
│       │   ├── semantic_analyzer.cpp
│       │   ├── semantic_analyzer.h
│       │   └── types_table.h
│       ├── lexical
│       │   ├── lexical_analyzer.cpp
│       │   └── lexical_analyzer.h
│       ├── main.cpp
│       ├── parser.cpp
│       ├── parser.h
│       ├── parser_components
│       │   ├── assignment_analyzer.cpp
│       │   ├── atrib_call_procedure.cpp
│       │   ├── command_analyzer.cpp
│       │   ├── conditional_analyzer.cpp
│       │   ├── et_variable_analyzer.cpp
│       │   ├── expression_analyzer.cpp
│       │   ├── factor_analyzer.cpp
│       │   ├── function_caller_analyzer.cpp
│       │   ├── function_declaration_analyzer.cpp
│       │   ├── parser_components.h
│       │   ├── procedure_caller_analyzer.cpp
│       │   ├── procedure_declaration_analyser.cpp
│       │   ├── read_analyzer.cpp
│       │   ├── simple_command_analyzer.cpp
│       │   ├── simple_expression_analyzer.cpp
│       │   ├── snippet_analyzer.cpp
│       │   ├── subroutine_analyzer.cpp
│       │   ├── term_analyzer.cpp
│       │   ├── type_analyzer.cpp
│       │   ├── variables_analyzer.cpp
│       │   ├── while_analyzer.cpp
│       │   └── write_analyzer.cpp
│       ├── token
│       │   ├── Token.cpp
│       │   ├── Token.h
│       │   ├── symbols.cpp
│       │   └── symbols.h
│       └── ui
│           ├── application.cpp
│           ├── application.h
│           ├── fileexplorer.cpp
│           ├── fileexplorer.h
│           ├── mainwindow.cpp
│           └── mainwindow.h
└── virtual_machine
    ├── CMakeLists.txt
    ├── src
    │   ├── main.cpp
    │   ├── ui
    │   │   ├── application.cpp
    │   │   ├── application.h
    │   │   ├── fileexplorer.cpp
    │   │   ├── fileexplorer.h
    │   │   ├── mainwindow.cpp
    │   │   └── mainwindow.h
    │   └── virtual_machine
    │       ├── DVM.cpp
    │       └── DVM.h
    └── target
        └── VM