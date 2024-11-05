#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>

sqlink list_create(void)
{
    sqlink L = (sqlink)malloc(sizeof(sqlist));
    if (L != NULL) {
        L->last = -1;
    }
    return L;
}




