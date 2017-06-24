#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include "function.h"
#include <unistd.h>





void menu()

{
    system("clear");
    printf("Dobro pogalovatb v igru biki i korovi\n\n");
    printf("1. Naiti igru\n");
    printf("2. Pravila igri\n");
    printf("3. Vihod\n");
    int punkt2;
    int punkt;
    scanf("%d", &punkt);
    if(punkt != 1 && punkt != 2 && punkt != 3)
    {
        printf("Takogo punkta v menu net!\n");
        scanf("%d", &punkt);
    }

}
