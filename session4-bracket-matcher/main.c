#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "bracketEval.h"
#include "main.h"
#include "errorHandle.h"

int main(int argc, char **argv){
    
    if(argc != 2) {
        printf("Usage: %s <expression>", argv[0]);
        exit(EXIT_FAILURE);
    }
  
    char *knownLenStr = malloc(sizeof(char) * MAXSTRSIZE);
    memset(knownLenStr, '\0', MAXSTRSIZE);
    strncpy(knownLenStr, argv[1], MAXSTRSIZE);

    bracketError_t* error = eval(knownLenStr);
    
    if(error->errorCode != OK){
        printf("\nMismatch in %s. Expected \'%c\' at %d.\n", 
            knownLenStr, error->expectingChar, error->position);
    } 
    else {
        printf("\nEverything was good with your brackets!\n");
    }
    
    free(error);
    free(knownLenStr);
    exit(EXIT_SUCCESS);
}

