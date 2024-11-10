#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*list_create: 用于创建线性表(list_create: create a list)
*para L: 线性表(list)
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
*list_empty: 用于判断是否为空的线性表(list_empty: is list empty ??)
*para L: 线性表(list)
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
*list_length: 用于返回线性表的长度(list_length: how many elements in list ??)
*para L: 线性表(list)
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
*insert: 用于在pos位置插入value(insert: insert value at pos)
*para L: 线性表(list)
*para value: 要插入的元素(insert element)
*para pos: 插入的位置(insert position)
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
    //check pos ,pos属于[0,last+1]
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
*delete: 用于删除pos位置的元素(delete: delete element at pos)
*para L: 线性表(list)
*para pos: 删除的位置(delete position)
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