#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bracketEval.h"
#include "stack.h"
#include "main.h"
#include "bracket.h"
#include "errorHandle.h"

bracketError_t* eval(char *str){

    // init stack, and error
    stack* stackB = stack_init();
    bracketError_t* error = (bracketError_t*) malloc(sizeof(bracketError_t));
    error->errorCode = OK;
    
    int i;
    
    //loop and push brackets
    for (i = 0; i < MAXSTRSIZE && str[i] != '\0'; ++i) {
        
        brackets_t currentElem = charToBracket(str[i]);

#ifdef VERBOSE
        printf("curr for %c :: %d.\n", str[i], currentElem);
#endif
        //debug_print(currentElem, 0);
        
        if(currentElem == NOTBRACKET){
            continue;
        }
        
        if(isOpeningBracket(currentElem)){
            
            stack_push(stackB, currentElem);
        } 
        else {
            
            assert(isClosingBracket(currentElem));

            // Error: too many closing brackets
            if (stack_is_empty(stackB)){
                error->errorCode = MISMATCH;
                error->expectingChar = bracketToChar(getMatchingBracket(currentElem));
                error->position = 0;
                return error;
            }
            
            int top = stack_pop(stackB);

            // Error: bracket mismatch
            if(!isMatchingBracket(top, currentElem)){
                error->errorCode = MISMATCH;
                error->position = i;
                error->expectingChar = bracketToChar(getMatchingBracket(top));
                return error;
            }
        }
    }

    // Error: too many openning brackets
    if(!stack_is_empty(stackB)){
        error->errorCode = MISMATCH;
        error->position = i;
        error->expectingChar = bracketToChar(getMatchingBracket(stack_getTop(stackB)));
    }
   
    // free resources
    stack_empty(stackB);
    free(stackB);

    return error;
}
