#include <stdio.h>
#include "sqlist.h"

int main()
{
    sqlink L;
    L = list_create();
    if(L == NULL)
        return -1;   
    list_insert(L,10,0);
    list_insert(L,20,0);
    list_insert(L,30,0);
    list_insert(L,40,0);
    list_insert(L,50,0);
    list_show(L);
    return 0;
}

