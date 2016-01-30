#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "bracketEval.h"
#include "main.h"
#include "errorHandle.h"

int main(int argc, char **argv){
    char *knownLenStr = malloc(sizeof(char) * MAXSTRSIZE);

    memset(knownLenStr, 0, MAXSTRSIZE);
    strcpy(knownLenStr, "{((3+4))");

    bracketError_t* error = eval(knownLenStr);

    
    if(error->errorCode != OK){
        
        printf("\nSomething was wrong @ index: %d of %s. Expected %c\n", error->position, knownLenStr, error->expectingChar);
        return 0;
    } else{
        printf("\nEverything was good with your brackets");
    }
    
    free(error);
    printf("\n");
    return 0;
}

