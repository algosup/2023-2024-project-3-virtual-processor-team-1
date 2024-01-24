#ifndef C_VERSION_H
#define C_VERSION_H
#include <stdio.h>
#include <stdlib.h>
void C_version()
{
    printf("C version: %ld\n", __STDC_VERSION__);
}

#endif // VERSION_H
