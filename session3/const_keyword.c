int main(void) {

    int val = 1, val2 = 2;
    
    const int *ptr1 = &val;       /* ptr1 can be modified, val cannot */
    ptr1 = &val2;
    // *ptr1 = 10;    // error: read-only variable is not assignable
    
    int *const ptr2 = &val;       /* val can be modified, ptr2 cannot */
    // ptr2 = &val2;  // error: read-only variable is not assignable 
    *ptr2 = 10; 
    
    const int *const ptr3 = &val; /* neither val nor ptr3 can be modified */
    // ptr3 = &val2;  // error: read-only variable is not assignable  
    // *ptr3 = 10;    // error: read-only variable is not assignable    

    return 0;
}
