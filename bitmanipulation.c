#include <stdio.h>
#include <malloc.h>

/* Bit Manipulation */

/*

Binary:  01101001

1   *  1   = 1   ->   1 + 1  = 2
2   *  0   = 0   ->   2 * 2  = 4  
4   *  0   = 0   ->   4 * 2  = 8
8   *  1   = 8   ->   8 * 2  = 16
16  *  0   = 0   ->   16 * 2 = 32
32  *  1   = 32  ->   32 * 2 = 64
64  *  1   = 64  ->   64 * 2 = 128
128 *  0   = 0  

1 + 0 + 0 + 8 + 0 + 32 + 64 + 0 = 105

Decimal = 105

*/

int main(){ 
    int array[8];
    int hold[8];
    size_t arraysize;
    int value = 0;
    int decrypt = 0;
    int start;
    arraysize = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < arraysize; i++){ // Grab Binary Number from User Input
        printf("Decrypt Binary: ");
        scanf("%d", &array[i]);
    }
    
    start = (1 * array[arraysize-1]) + 1; // Start
    
    // Start of Binary to Decimal Algorithm
    
    for(size_t i = arraysize-2; i >= 0; i--){
        hold[i] = (start * array[i]); // Hold result of calc
        start = start * 2; // Continue to next calc | start(2) = start(2) * start(2)
        if(i == 0){ break; };
    }
    
    for(int i = 0; i < arraysize-1; i++){ // Sum of all Calculations
        decrypt = decrypt + hold[i];
    }
    
    printf("Decrypted Binary = %d  size = %d\n", decrypt+1, arraysize);
    
    return 0;
}