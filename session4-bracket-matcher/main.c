#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "bracketEval.h"
#include "main.h"

int main(int argc, char **argv){
    char *knownLenStr = malloc(sizeof(char) * MAXSTRSIZE);

    memset(knownLenStr, 0, MAXSTRSIZE);
    strcpy(knownLenStr, "((3+4)))");

    int error = eval(knownLenStr);
    int top = returnTop();
    //printf("\nsize = %d, top = %d\n", error, top);
    //printf("%d", error);
    
    if(error != 0){
        //printf("Error code: %d \n",error);
        int index = top - OPENBRACKET;
        
        if(index <= 0){
            index = index + (int)strlen(knownLenStr);
        }
        
        
        printf("\nSomething was wrong @ index: %d of %s \n", index, knownLenStr);
        return 0;
    } else{
        printf("\nEverything was good with your brackets");
    }
    printf("\n");
    return 0;
}

