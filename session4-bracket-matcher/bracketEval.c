#include <stdlib.h>
#include "bracketEval.h"
#include "stack.h"
#include "main.h"
#include <stdio.h>

int top;
int stringProcessing(char *str, stack* stackB){
    
    int currentTopNum = 0;
    //loop and push brackets
    for (int i = 0; i < MAXSTRSIZE; ++i) {

        char currentElem = str[i];
        if(currentElem == '('){
            stack_push(stackB, OPENBRACKET + i);
            currentTopNum = i;
            

        } else if(currentElem == ')'){

            top = stack_pop(stackB);
            //printf("%d", top);
            if(top == -1){
                stackB->size -= 1;
                
            }
            if(top - (top-currentTopNum) != OPENBRACKET){
                return -1;
            }
        }
    }
    return 0;
}

int eval(char *str){

    //init stack
    stack *stackB;
    stackB = (stack *) malloc(sizeof(stack));
    stack_init(stackB);

    //loop and push brackets
    //pop brackets if closing bracket found

    stringProcessing(str, stackB);
    return stack_size(stackB);
}

int returnTop(){
    return top;
}
