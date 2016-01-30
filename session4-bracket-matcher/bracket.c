#include <stdbool.h>
#include "bracket.h"

brackets_t charToBracket(const char bracketC){
    switch (bracketC) {
        case '(':
            return OPENBRACKET;
        case ')':
            return CLOSEBRACKET;
        case '{':
            return OPENCURLY;
        case '}':
            return CLOSECURLY;
        case '[':
            return OPENSQUARE;
        case ']':
            return CLOSESQUARE;
        default:
            return NOTBRACKET;
    }
}


bool isOpeningBracket(const brackets_t bracket){
    switch(bracket){
        case OPENBRACKET:
        case OPENSQUARE:
        case OPENCURLY:
            return true;
        default:
            return false;
    }
}

//Precondition: it is going to be a bracket
bool isClosingBracket(const brackets_t bracket){
    return !isOpeningBracket(bracket);
}

bool isMatchingBracket(const brackets_t top, const brackets_t compare){
    return getMatchingBracket(top) == compare;
}

char bracketToChar(const brackets_t bracket){
    
    switch (bracket) {
        case OPENBRACKET:
            return '(';
        case CLOSEBRACKET:
            return ')';
        case OPENCURLY:
            return '{';
        case CLOSECURLY:
            return '}';
        case OPENSQUARE:
            return '[';
        case CLOSESQUARE:
            return ']';
        default:
            return '\0';
    }
}

brackets_t getMatchingBracket(const brackets_t bracket){
    
    switch(bracket){
        case OPENBRACKET:
            return  CLOSEBRACKET;
        case OPENCURLY:
            return CLOSECURLY;
        case OPENSQUARE:
            return CLOSESQUARE;
        case CLOSEBRACKET:
            return  OPENBRACKET;
        case CLOSECURLY:
            return OPENCURLY;
        case CLOSESQUARE:
            return OPENSQUARE;
        default:
            return NOTBRACKET;
    }
}

