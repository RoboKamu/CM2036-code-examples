#include <stdio.h>

#ifdef DBG
#include <assert.h>
#else 
#define assert(x) /* nothing */
#endif

/** 
 * TEST function pointer, and assertions to assure correct function passed 
 * Compile with DBG via gcc -DDBG 
 * running via ./a.out should give an assert error because of string being null
 * or becuase the wrong function is passed. 
 * Note: parameters can easily be defined by setting (*f)() to (*f)(void)
 * Note: dont have to lock to specific funtion, can also assert f != NULL 
 */ 

void foo(const char* s) {
#ifdef DBG
    assert(s != NULL && "string must not be null, in foo()");
#endif
    printf("from param foo : %s", s);
}

void bar(void (*f)(), const char* s) {
#ifdef DBG
    assert((*f) == foo && "wrong function passed, only foo allowed, in bar(func, string)");
#endif
    (*f)(s);
}

void noParamFoo() {
    printf("from no param foo: hello! \n");
}

void noParamBar(void (*f)()) {
#ifdef DBG
    assert(f == noParamFoo && "wrong function passed, only noParamFoo allowed, in noParamBar(func)");
#endif
    (*f)();
}

int main() { 

    printf("Function pointers 101 test start..\n");

//    bar(foo, NULL); // NOT OK! assertion throws error
    bar(foo, "hello\n"); // GOOD ! 

//    noParamBar(foo); // NOT OK! assertion throws error
    noParamBar(noParamFoo); // GOOD ! 

    printf("..Funtion pointer 101 test ended!\n");

    return 0;
}
