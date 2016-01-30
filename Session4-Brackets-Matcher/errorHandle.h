//
//  errorHandle.h
//  Session5
//
//  Created by David Jay on 30/01/2016.
//  Copyright © 2016 David Jay. All rights reserved.
//

#ifndef errorHandle_h
#define errorHandle_h

#define OK 0
#define MISMATCH 1


typedef struct bracketError_t {
    
    int position;
    char expectingChar;
    int errorCode;
    
    
} bracketError_t;

#endif /* errorHandle_h */
