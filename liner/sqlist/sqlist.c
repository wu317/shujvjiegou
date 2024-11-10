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
        return NULL;
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
int list_delete(sqlink L)
{
    if(L == NULL)
        return -1;
    free(L);
    L = NULL;
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
        return (L->last+1);
}
int list_locate(sqlink L,data_t value)
{
    return 0;
}
/*
*insert: ������posλ�ò���value(insert: insert value at pos)
*para L: ���Ա�(list)
*para value: Ҫ�����Ԫ��(insert element)
*para pos: �����λ��(insert position)
*@ret 0-succeed -1-failed
*/
int list_insert(sqlink L,data_t value,int pos)
{
    int i;
    //full
    if(L->last == N-1)
    {
        printf("list is full\n");
        return -1;
    }
    //check pos ,pos����[0,last+1]
    if(pos < 0 || pos > (L->last+1))
    {
        printf("pos is invalisd\n");
        return -1;
    }
    //move
    for(i=L->last;i>=pos;i--)
    {
        L->data[i+1] = L->data[i];
    }
    //update
    L->data[pos] = value;
    L->last++;
    return 0;
}
/*
*delete: ����ɾ��posλ�õ�Ԫ��(delete: delete element at pos)
*para L: ���Ա�(list)
*para pos: ɾ����λ��(delete position)
*@ret 0-succeed -1-failed
*/
int list_show(sqlink L)
{
    int i;
    if(L == NULL)
        return -1;
    if(L->last == -1)
    {
        printf("list is empty\n");
        return -1;
    }

    for(i = 0;i<=L->last;i++)
    {
        printf("%d ",L->data[i]);
    }
    puts("");
    return 0;
}