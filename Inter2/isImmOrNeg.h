#ifndef ISIMMORNEG_H
#define ISIMMORNEG_H
#include <stdio.h>
#include "token.h"

int isImmatiateOrNegative(char *str)
{
    if (str[0] == IMMEDIATE)

        return 1;
    else if (str[0] == NEG)
        return 2;
    else
        return 0;
}

char* removeToken(char *str)
{
    if(isImmatiateOrNegative(str) == 1 || isImmatiateOrNegative(str) == 2)
    {
        str++;
    }
    else
    {
        printf("Error in removeToken function\n");
    }
        
    return str;
}

#endif
