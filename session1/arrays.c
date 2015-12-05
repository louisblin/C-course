#include <stdio.h>  // IO
#include <stdlib.h> // Dynamic memory management 

// Good practice: put this in a arrays.h header file
void testArray(unsigned int *arr);

int main (void) {

    // Array allocated on the heap.
    // heapArr is a pointer on the stack to its location on the heap
    unsigned int* heapArr  = malloc(1024 * sizeof(int));
    
    printf("==== HEAP ARR ====\n");
    testArray(heapArr);

    // Array allocated on the stack.
    // stackArr is a pointer on the stack to the stack array
    unsigned int stackArr[1024];
    
    printf("==== STACK ARR ====\n");
    testArray(heapArr);

    // Nested array
    unsigned int *(nested[]) = {heapArr, stackArr};

    printf("==== NESTED ARR ====\n");
    nested[0][3] = 123;
    printf("nested[0][3] = %d\n", nested[0][3]);
    printf("heapArr[3] = %d\n", heapArr[3]);

    // Don't forget this!
    free(heapArr);

    // And only free heap allocated memory
    //free(stackArr); 
    
    return 0;
}

void testArray(unsigned int *arr) {

    // applying '*' is called 'dereferencing a pointer'
    *arr = 4;
    printf("*arr = %d\n", *arr);

    arr[0] = 8;
    printf("arr[0] = %d\n", *arr);
    
    *(arr + 1) = 12;
    printf("*(arr + 1) = %d\n", arr[1]);
    
    *(arr + arr[1]) = 16;
    printf("*(arr + arr[1]) = %d\n", arr[12]);

    // And a nasty one? Aka. "not a shortcut for arr[11]"
    *(&((arr + arr[1])[0]) - 1) = 20;
    printf("*(&((arr + arr[1])[0]) - 1) = %d\n", arr[11]);
}
