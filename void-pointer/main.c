
/*
 * This file demostrates some examples using void pointers. 
 *
 * A void pointer is a reference to ANYTIHNG. This can be used for functions with 
 * generic purposes, like an alogrithm or generic initialization. [1] 
 *
 * void pointer is limited that it cannot be used for pointer arithmetic and also
 * can not be dereferenced, for those purposes you would have to cast it. [2]
 */

#include <stdio.h>

typedef enum {
    INPUT, 
    OUTPUT,
    SLEEP
} GPIO_state;

// declare function for declaring some GPIO pin
void gpio_init(GPIO_state state, void *arg);

int main() {
    
    // [1] 
    int arr[] = {1, 2};
    printf("normal pointer arithmetic with {%d, %d}\n", arr[0], arr[1]);
    int *pArr = arr;
    printf("pArr at: %d\n", *pArr);
    pArr = pArr + 1; // increment to arr[1]
    printf("pArr + 1 increment: %d\n", *(pArr));

    // Limitations and casting 
    void *pvArr = arr;
//    printf("pvArr at: %d\n", *pvArr); // NOT OK! 
//    pvArr + 1; // NOT OK! 
    printf("pvArr at: %d\n\n", *( (int *)(pvArr) )); // OK! (derefernce after cast)

    // [2]
    int pin = 2;
    gpio_init(OUTPUT, &pin); // pin 2 as output 

    gpio_init(SLEEP, "going to sleep....z.zz\n");

    return 0;
}

// define the init function, and cast the void pointer to expected value 
// This just shows that you can cast the void pointer based on a case..
// ...obviously this example is not for displaying best practice for a init function 
// for that; check malloc and qsort implementatoin in the standard library 
void gpio_init(GPIO_state state, void *arg){

    switch(state) {
        case INPUT: 
            int *input_pin = (int *)arg;
            // do some fancy code to setup input... 
            printf("setting up pin { %d } as INPUT\n", *input_pin);
            break;
        case OUTPUT:
            int *output_pin = (int *)arg;
            // do some fancy code to setup output... 
            printf("setting up pin { %d } as OUTPUT\n", *output_pin);
            break;
        case SLEEP: 
            const char *msg = (const char*) arg;
            // do some fancy code to put in sleep mode...
            printf("TX: %s", msg);
            break;
        default:
            printf("something wrong happned here...\n");
    }

}
