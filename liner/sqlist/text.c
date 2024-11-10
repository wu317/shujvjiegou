#include <stdio.h>
#include "sqlist.h"
int test_insert();
int main()
{
    test_insert();
    return 0;
}

int test_insert()
{
    sqlink L;
    int length;
    L = list_create();
    if(L == NULL)
        return -1;   
    list_insert(L,10,0);
    list_insert(L,20,0);
    list_insert(L,30,0);
    list_insert(L,40,0);
    list_insert(L,50,0);
    list_insert(L,60,0);

    list_show(L);

    list_insert(L,80,2);
    length = list_length(L);
    list_insert(L,90,length);
    list_show(L);
    list_delete(L);
    return 0;
}



