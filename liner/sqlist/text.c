#include <stdio.h>
#include "sqlist.h"
int test_insert();
int test_delete();
int test_merge();
int test_purge();
int main()
{
    //test_insert();
    //test_delete();
    //test_merge();
    test_purge();
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
    list_free(L);
    return 0;
}
int test_delete()
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
    list_insert(L,60,0);
    list_show(L);

    list_delete(L,0);
    list_show(L);
    list_free(L);
    return 0;
}


int test_merge()
{
    sqlink L1,L2;
    L1 = list_create();
    if(L1 == NULL)
        return -1;   
    list_insert(L1,10,0);
    list_insert(L1,20,0);
    list_insert(L1,30,0);
    list_show(L1);

    L2 = list_create();
    if(L2 == NULL)
        return -1;   
    list_insert(L2,30,0);
    list_insert(L2,40,0);
    list_insert(L2,50,0);
    list_show(L2);
    list_merge(L2,L1);
    list_show(L2);
    return 0;
}

int test_purge()
{
    sqlink L;
    L = list_create();
    if(L == NULL)
        return -1;   
    list_insert(L,10,0);
    list_insert(L,10,0);
    list_insert(L,20,0);
    list_insert(L,30,0);
    list_insert(L,50,0);
    list_insert(L,20,0);
    list_show(L);
    list_purge(L);
    list_show(L);
    return 0;
}
