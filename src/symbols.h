#ifndef symbols_h
#define symbols_h

#include <iostream>

enum class Symbols
{
    //Reserved symbols
    SPROGRAMA,
    SSE,
    SENTAO,
    SSENAO,
    SENQUANTO,
    SFACA,
    SINICIO,
    SFIM,
    SESCREVA,
    SLEIA,
    SVAR,
    SINTEIRO,
    SBOOLEANO,
    SVERDADEIRO,
    SFALSO,
    SPROCEDIMENTO,
    SFUNCAO,
    SDIV,
    SE,
    SOU,
    SNAO,
    SIDENTIFICADOR,

    // Digit Symbol
    SNUMERO,

    // Arithmetic Symbols SMAIS,
    SMENOS,
    SMULT,

    // Relational Symbols
    SMAIORIG,
    SMAIOR,
    SMENORIG,
    SMENOR,
    SDIF,
    SIG,

    // Ponctuation Symbols
    SPONTO_VIRGULA,
    SVIRGULA,
    SABRE_PARENTESES,
    SFECHA_PARENTESES,
    SPONTO,
    SATRIBUICAO,
    SDOISPONTOS,

    // Error Symbols
    SERRO,

    EMPTY
};

std::ostream& operator<<(std::ostream& os, const Symbols Token);

#endif

