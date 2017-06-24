#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include "function.h"
#include <unistd.h>


int fl=1;

void menu()
{
    system("cls");
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
    int a, b, c, d;
    switch(punkt)
	{
        case 1:
            system("cls");
            bcrandom(&a, &b, &c, &d);
            bulls_cows(&a, &b, &c, &d);
            break;
	}
            

}

int safe_input(char *str)
{
    int test, number;

    test = atoi(str);

    printf("\n");
    if(fl!=1){
    if(test > 10000 || test < 100)
    {
        printf("Incorrect input! Please check rules\n");
        printf("Enter the four-digit celery: = ");
        return 0;
    }

    if(str[0] == str[1] || str[0] == str[2] || str[0] == str[3] || str[1] == str[2] || str[1] == str[3] || str[2] == str[3])
    {
        printf("Incorrect input! Please check rules\n");
        printf("Enter the four-digit celery: = ");
        return 0;
    }

    if(isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]))
    {
        number = atoi(str);
        return number;
    } else
      {
        printf("Incorrect input! Please check rules\n");
        printf("Enter the four-digit celery: = ");
        return 0;
      }
	}
}

int bcrandom(int *a, int *b, int *c, int *d)
{
    srand(time(NULL));
    do
    {
        *a = 0 + rand() % 9;
        *b = 0 + rand() % 9;
        *c = 0 + rand() % 9;
        *d = 0 + rand() % 9;
    } while (*d == *a || *d == *b || *d == *c || *c == *a || *c == *b || *b == *a);

    printf("Rand number %d%d%d%d\n", *a, *b, *c, *d);

    return 0;
}

int bulls_cows(int *a, int *b, int *c, int *d)
{
    int sc = 0;
    int number = 0, fst, scnd, thrd, frth;
    int bulls, cows;
    char str[100];

    while (number != (*a * 1000 + *b * 100 + *c * 10 + *d))
    {
        fgets(str, sizeof(str), stdin);
        number = safe_input(str);
        if((number > 0) && (fl!=1))
        {
            printf("\n");
            fst = number / 1000;
            scnd = number / 100 % 10;
            thrd = number / 10 % 10;
            frth = number % 10;

            bulls = bulls_func(a, b, c, d, &fst, &scnd, &thrd, &frth);
            cows = cows_func(a, b, c, d, &fst, &scnd, &thrd, &frth);
            sc++;

            printf("%d bulls\n", bulls);
            printf("%d cows\n", cows);
            printf("\n");
            printf("\n");

            if(bulls == 4)
                break;
            printf("Enter the four-digit celery: = ");
        }
        fl=0;
    }
    
    printf("Поздравляем, вы выиграли!\nКоличество попыток: %d!\n\nВозвращение в меню...\n\n", sc);
    sleep(2);
    menu();

    return 0;

}

int bulls_func(int *a, int *b, int *c, int *d, int *fst, int *scnd, int *thrd, int *frth)
{
    int bulls = 0;

    if (*fst == *a)
        bulls++;
    if (*scnd == *b)
        bulls++;
    if (*thrd == *c)
        bulls++;
    if (*frth == *d)
        bulls++;

    return bulls;
}

int cows_func(int *a, int *b, int *c, int *d, int *fst, int *scnd, int *thrd, int *frth)
{
    int cows = 0;

    if (*fst == *b || *fst == *c || *fst == *d)
        cows++;
    if (*scnd == *a || *scnd == *c || *scnd == *d)
        cows++;
    if (*thrd == *b || *thrd == *a || *thrd == *d)
        cows++;
    if (*frth == *b || *frth == *c || *frth == *a)
        cows++;

    return cows;
}

