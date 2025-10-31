#include <stdio.h> 


/** 
 * The purpose of this file is to demonstrate how to create an array of function pointers.
 * Also for usage as a state machine with typedefs for readability. 
 * Lastly, the function pointers can be initialized as null
 *
 * There are 2 main ways of doing this 
 *
 * -> first: using typedef
 * -> second: normal direct declaration
 *
 *  Lastly this code concludes with showing usage of ENUM for indexing, this can be used for
 *  application like state machines. 
 *
 * Source: https://web.archive.org/web/20230604170005/http://www.newty.de/fpt/fpt.html
 * further reading on the final example: Making Embedded Systems,  Elicia White
 *
 */

enum exampleStateEnum {
    IDLE,
    READY
};


// first
// typedef for readability, Note: on POSIX system avoid name ending "_t" since its reserved.
// In real production code and libraries; great care should be taken for naming convensions
typedef int (*ptr2Function)(const char *);

int foo(const char *s) {
    printf("%s \n", s);
    return 0;
}

int bar(const char *s) {
    printf("%s \n", s);
    return 0;
}

int main() {
    
    // first: use the typedef to init 2 elem to null 
    ptr2Function funcArr1[2] = {NULL};

    // second:
    // for a function like " int foo(char *s) ": create 2 elements initialized to null 
    int (*funcArr2[2])(const char *) = {NULL};

    // add foo and bar to both
    funcArr1[0] = funcArr2[0] = &foo;
    funcArr1[1] = funcArr2[1] = &bar;

    int retVal = funcArr1[0]("storing the return value of function");

    printf("---> expect 0, got: %d\n", retVal);
    funcArr1[0]("im in foo 1 from array 1!!"); 
    funcArr2[0]("im in foo 1 from array 2!!"); 
    funcArr1[1]("im in bar 2 from array 1!!");
    funcArr2[1]("im in bar 2 from array 2!!");

    // Finally, using an enum and a function pointer array you can create a state machine 
    enum exampleStateEnum state = IDLE;
    funcArr1[state]("\n..im sleeping in this function..\n");  // same as foo("\n..im sleeping in this function..\n")
    state = READY; // something happened in the interrupt service routine 
    funcArr1[state]("..time for action!\n");

    return 0;
}
