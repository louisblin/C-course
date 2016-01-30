#ifndef bracket_h
#define bracket_h

#include <stdbool.h>
#include <stdio.h>

typedef enum {

    OPENBRACKET,
    CLOSEBRACKET,
    OPENCURLY,
    CLOSECURLY,
    OPENSQUARE,
    CLOSESQUARE,
    
    NOTBRACKET

} brackets_t;

brackets_t charToBracket(const char bracketC);
char bracketToChar(const brackets_t bracket);

brackets_t getMatchingBracket(const brackets_t bracket);
bool isOpeningBracket(const brackets_t bracket);
bool isClosingBracket(const brackets_t bracket);
bool isMatchingBracket(const brackets_t top, const brackets_t compare);


#endif /* bracket_h */
