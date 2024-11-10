#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*list_create: ���ڴ������Ա�(list_create: create a list)
*para L: ���Ա�(list)
*@ret NULL-failed L-succeed
*/
sqlink list_create(void)
{
    //malloc
    sqlink L;
    L =(sqlink) malloc(sizeof(sqlist));
    if(L == NULL)
    {
        printf("list malloc failed\n");
        return L;
    }
    //initialize
    memset(L,0,sizeof(sqlist));
    L -> last = -1;
    //return
    return L;
}
/*
*@ret 0-succeed -1-failed
*/
int list_clear(sqlink L)
{
    if(L == NULL)
        return -1;
    memset(L,0,sizeof(sqlist));
    L -> last = -1;
    return 0;
}
/*
*list_empty: �����ж��Ƿ�Ϊ�յ����Ա�(list_empty: is list empty ??)
*para L: ���Ա�(list)
*@ret 1-empty 0-not empty
*/
int list_empty(sqlink L)
{
    if(L -> last == -1)
        return 1;
    else
        return 0;
}
/*
*list_length: ���ڷ������Ա�ĳ���(list_length: how many elements in list ??)
*para L: ���Ա�(list)
*@ret -1-failed length 
*/
int list_length(sqlink L)
{
    if(L == NULL)
        return -1;
    else
        return (L->last +1);
}
int list_locate(sqlink L,data_t value)
{
    return 0;
}
int insert(sqlink L,data_t value,int pos)
{
    return 0;
}

