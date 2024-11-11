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
*list_clear: 用于清空线性表(list_clear: clear a list)
*para L: 线性表(list)
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
*list_free: 用于销毁线性表(list_free: free a list)
*para L: 线性表(list)
*@ret 0-succeed -1-failed
*/
int list_free(sqlink L)
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
/*
*list_locate: 用于查找value在list中的位置(list_locate: find value in list)
*list_locate: 用于查找线性表中元素第一次出现的位置(list_locate: find the first position of the element in list)
*para L: 线性表(list)
*para value: 要查找的元素(find element)
*@ret -1-failed pos
*/
int list_locate(sqlink L,data_t value)
{
    int i;
    for(i=0;i<=L->last;i++)
    {
        if(value == L->data[i])
            return i;
    }
    return -1;
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
/*
*delete: 用于删除pos位置的元素(delete: delete element at pos)
*para L: 线性表(list)
*para pos: 删除的位置(delete position)
*@ret 0-succeed -1-failed
*/
int list_delete(sqlink L,int pos)
{
    int i;
    if(L->last == -1)
    {
        printf("list is empty\n");
        return -1;
    }
    //pos∈[0,last]
    if(pos<0 || pos>L->last)
    {
        printf("delete pos is invalide\n");
        return -1;
    }
    //move  [pos+1,last]需要向前移动
    for(i=pos+1;i<=L->last;i++)
    {
        L->data[i-1] = L->data[i];
    }
    //update
    L->last--;
    return 0;
}
/*
*list_merge: 用于合并两个线性表(list_merge: merge two list)
*para L1: 线性表1(list1)
*para L2: 线性表2(list2)
*@ret 0-succeed -1-failed
*/
int list_merge(sqlink L1,sqlink L2)
{
    int i = 0;
    int ret;
    while(i <= L2->last)
    {
        ret = list_locate(L1,L2->data[i]); 
        if(ret == -1)
        {
            if(list_insert(L1,L2->data[i],L1->last+1) == -1)
            {
                printf("list1 haven't spase\n");
                return -1;
            }
        }
        i++;
    }
    return 0;
}
int list_purge(sqlink L)
{
    int i;
    int j;
    if(L->last == 0)
        return 0;
    i = 1;
    while(i <= L->last)
    {
        j = i-1;
        while(j>=0)
        {
            if(L->data[i] == L->data[j])
            {
                list_delete(L,i);
                break;
            }
            else
                j--;    
        }
        if(j < 0)
            i++;
    }
    return 0;
}