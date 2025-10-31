#include <stdio.h>

/*
 * This file shows example of using function pointers in a struct. 
 * This can be used for abstracting library code like motor control
 */

typedef struct {
    void (*init)(void);
    void (*run)(void);
} Module;

void init(void) {
    printf("..init..");
}

void myCustomRunFunction(void) {
    printf("..run!\n");
}

int main() {

    // initialize directly 
    Module motor = { &init, NULL };
    // alternativly 
    motor.run = myCustomRunFunction; 

    printf("Starting motor..");

    motor.init();

    motor.run();

    return 0;
}
