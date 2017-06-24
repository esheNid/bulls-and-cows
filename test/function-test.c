#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 
#include <time.h> 
#define CTEST_COLOR_OK
#include <ctest.h>
#include "function.h"

CTEST(bulls, test1) 
{    
    int a = 1, b = 2, c = 3, d = 4, fst = 1, scnd = 2, thrd = 3, frth = 4;
    
    int const result = bulls_func(&a, &b, &c, &d, &fst, &scnd, &thrd, &frth);
    
    ASSERT_EQUAL(4, result);
}

CTEST(cows, test1) 
{    

    int a = 1, b = 2, c = 3, d = 4, fst = 1, scnd = 2, thrd = 3, frth = 4;
    
    int const result = cows_func(&a, &b, &c, &d, &fst, &scnd, &thrd, &frth);
    
    ASSERT_EQUAL(0, result);
}

CTEST(bulls, test2) 
{    
    int a = 1, b = 2, c = 3, d = 4, fst = 1, scnd = 2, thrd = 3, frth = 4;
    
    int const result = bulls_func(&a, &b, &c, &d, &fst, &scnd, &thrd, &frth);
    
    ASSERT_EQUAL(4, result);
}

CTEST(cows, test2) 
{    

    int a = 6, b = 7, c = 8, d = 9, fst = 9, scnd = 6, thrd = 3, frth = 7;
    
    int const result = cows_func(&a, &b, &c, &d, &fst, &scnd, &thrd, &frth);
    
    ASSERT_EQUAL(3, result);
}
