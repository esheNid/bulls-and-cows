#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 
#include <time.h> 
#define CTEST_COLOR_OK
#include <ctest.h>
#include "function.h"

CTEST(validation, test1) 
{    
    char str[100] = {1};
    
    int const result = safe_input(str);
    
    ASSERT_EQUAL(0, result);
}

CTEST(validation, test2) 
{    
    char str[100] = {'v'};
    
    int const result = safe_input(str);
    
    ASSERT_EQUAL(0, result);
}

CTEST(validation, test3) 
{    
    char str[100] = {1, 'a', '3', '4'};
    
    int const result = safe_input(str);
    
    ASSERT_EQUAL(0, result);
}
