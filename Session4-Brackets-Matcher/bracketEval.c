#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bracketEval.h"
#include "stack.h"
#include "main.h"
#include "bracket.h"
#include "errorHandle.h"


//loop and push brackets
//pop brackets if closing bracket found
bracketError_t* eval(char *str){

    //init stack
    stack* stackB = stack_init();
    bracketError_t* error = (bracketError_t*) malloc(sizeof(bracketError_t));
    error->errorCode = OK;
    
    int i;
    
    //loop and push brackets
    for (i = 0; i < MAXSTRSIZE; ++i) {
        
        brackets_t currentElem = charToBracket(str[i]);
        
        
        if(currentElem == NOTBRACKET){
            continue;
        }
        
        if(isOpeningBracket(currentElem)){
            
            stack_push(stackB, currentElem);
            
        } else{
            
            assert(isClosingBracket(currentElem));
            if (stack_size(stackB) == 0){
                error->errorCode = MISMATCH;
                error->expectingChar = getMatchingBracket(currentElem);
                error->position = 0;
            }
            
            int top = stack_pop(stackB);
            if(!isMatchingBracket(top, currentElem)){
                //We have an issue
                error->errorCode = MISMATCH;
                error->position = i;
                error->expectingChar = getMatchingBracket(currentElem);
            }
        }
    }
    if(stack_size(stackB) > 0){
        error->errorCode = MISMATCH;
        error->position = i;
        error->expectingChar = getMatchingBracket(stack_getTop(stackB));
    }
    
    return error;
}
