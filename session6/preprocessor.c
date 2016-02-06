#include <stdio.h>

#define process_type(TYPE, IDENT) \
      do { TYPE var; scanf(IDENT, &var); printf(IDENT"\n", var); } while(0)

int main(void) {

#ifdef VERBOSE
    printf("Program is running...\n");
#endif

    process_type(int, "%d");
    process_type(long, "%ld");
    process_type(long long, "%lld");
    process_type(float, "%f");
    process_type(double, "%lf");
    
#ifdef VERBOSE
    printf("Done.\n");
#endif

    return 0;
}

