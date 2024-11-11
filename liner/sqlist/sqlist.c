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
*list_clear: ����������Ա�(list_clear: clear a list)
*para L: ���Ա�(list)
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
*list_free: �����������Ա�(list_free: free a list)
*para L: ���Ա�(list)
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
/*
*list_locate: ���ڲ���value��list�е�λ��(list_locate: find value in list)
*list_locate: ���ڲ������Ա���Ԫ�ص�һ�γ��ֵ�λ��(list_locate: find the first position of the element in list)
*para L: ���Ա�(list)
*para value: Ҫ���ҵ�Ԫ��(find element)
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
/*
*delete: ����ɾ��posλ�õ�Ԫ��(delete: delete element at pos)
*para L: ���Ա�(list)
*para pos: ɾ����λ��(delete position)
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
    //pos��[0,last]
    if(pos<0 || pos>L->last)
    {
        printf("delete pos is invalide\n");
        return -1;
    }
    //move  [pos+1,last]��Ҫ��ǰ�ƶ�
    for(i=pos+1;i<=L->last;i++)
    {
        L->data[i-1] = L->data[i];
    }
    //update
    L->last--;
    return 0;
}
/*
*list_merge: ���ںϲ��������Ա�(list_merge: merge two list)
*para L1: ���Ա�1(list1)
*para L2: ���Ա�2(list2)
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