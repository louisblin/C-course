#ifndef errorHandle_h
#define errorHandle_h

#define OK 0
#define MISMATCH 1

#define DEBUG 0

#define debug_print(fmt, ...) \
    do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, \
     __FILE__, __LINE__, __func__, ##__VA_ARGS__); } while (0)

typedef struct bracketError_t {
    
    int position;
    char expectingChar;
    int errorCode;
    
    
} bracketError_t;

#endif /* errorHandle_h */
