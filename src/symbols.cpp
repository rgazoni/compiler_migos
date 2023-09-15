#include "symbols.h"


std::ostream& operator<<(std::ostream& os, const Symbols Token)
{
  switch(Token)
  {
    case Symbols::SPROGRAMA:
        os << "SPROGRAMA";
        break;
    case Symbols::SSE:
        os << "SSE";
        break;
   case Symbols::SENTAO:
        os << "SENTAO";
        break;
   case Symbols::SSENAO:
        os << "SSENAO";
        break;
   case Symbols::SENQUANTO:
        os << "SENQUANTO";
        break;
   case Symbols::SFACA:
        os << "SFACA";
        break;
   case Symbols::SINICIO:
        os << "SINICIO";
        break;
   case Symbols::SFIM:
        os << "SFIM";
        break;
   case Symbols::SESCREVA:
        os << "SESCREVA";
        break;
   case Symbols::SLEIA:
        os << "SLEIA";
        break;
   case Symbols::SVAR:
        os << "SVAR";
        break;
   case Symbols::SINTEIRO:
        os << "SINTEIRO";
        break;
   case Symbols::SBOOLEANO:
        os << "SBOOLEANO";
        break;
   case Symbols::SVERDADEIRO:
        os << "SVERDADEIRO";
        break;
   case Symbols::SFALSO:
        os << "SFALSO";
        break;
   case Symbols::SPROCEDIMENTO:
        os << "SPROCEDIMENTO";
        break;
   case Symbols::SFUNCAO:
        os << "SFUNCAO";
        break;
   case Symbols::SDIV:
        os << "SDIV";
        break;
   case Symbols::SE:
        os << "SE";
        break;
   case Symbols::SOU:
        os << "SOU";
        break;
   case Symbols::SNAO:
        os << "SNAO";
        break;
   case Symbols::SIDENTIFICADOR:
        os << "SIDENTIFICADOR";
        break;
   case Symbols::SNUMERO:
        os << "SNUMERO";
        break;
   case Symbols::SMENOS:
        os << "SMENOS";
        break;
   case Symbols::SMULT:
        os << "SMULT";
        break;
   case Symbols::SMAIORIG:
        os << "SMAIORIG";
        break;
   case Symbols::SMAIOR:
        os << "SMAIOR";
        break;
   case Symbols::SMENORIG:
        os << "SMENORIG";
        break;
   case Symbols::SMENOR:
        os << "SMENOR";
        break;
   case Symbols::SDIF:
        os << "SDIF";
        break;
   case Symbols::SIG:
        os << "SIG";
        break;
   case Symbols::SPONTO_VIRGULA:
        os << "SPONTO_VIRGULA";
        break;
   case Symbols::SVIRGULA:
        os << "SVIRGULA";
        break;
   case Symbols::SABRE_PARENTESES:
        os << "SABRE_PARENTESES";
        break;
   case Symbols::SFECHA_PARENTESES:
        os << "SFECHA_PARENTESES";
        break;
   case Symbols::SPONTO:
        os << "SPONTO";
        break;
   case Symbols::SATRIBUICAO:
        os << "SATRIBUICAO";
        break;
   case Symbols::SDOISPONTOS:
        os << "SDOISPONTOS";
        break;
   case Symbols::SERRO:
        os << "SERRO";
        break;
    default: 
        os << "EMPTY";
        break;
  }
  return os;
}
