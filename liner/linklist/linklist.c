#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist list_create(void)
{
    linklist H;
    //申请内存
    H = (linklist)malloc(sizeof(list_node));
    if(H == NULL)
    {
        printf("malloc falied\n");
        return H;
    }
    //赋初值
    H->data = 0;
    H->next = NULL;
    //返回头指针
    return H;
}

int list_tali_insert(linklist H,data_t value)
{
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }    
    linklist p;
    linklist q;
    //1.new node
    if((p = (linklist)malloc(sizeof(list_node))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    //2.tail node
    q = H;
    while(q->next != NULL)
    {
        q = q->next;
    }
    //3.insert
    q->next = p;
    return 0;
}
linklist list_get(linklist H,int pos)
{
    int i = 0;
    linklist p;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }
    if(pos == -1)
        return H;
    p = H;
    i = -1;
    while(i<pos)
    {
        p = p->next;
        if(p == NULL)
        {
            printf("pos is out of range\n");
            return NULL;
        }
        i++;
    }
    return p;
}

int list_insert(linklist H,data_t value,int pos)
{
    linklist p;
    linklist q;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    //1.locate node p(pos-1)
    p = list_get(H,pos-1);
    if(p == NULL)
    {
        printf("pos is out of range\n");
        return -1;
    } 
    //2.new node q
    if((q = (linklist)malloc(sizeof(list_node))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    q->data = value;
    q->next = NULL;
    //3.insert
    q->next = p->next;
    p->next = q;
    return 0;   
}
int list_show(linklist H)
{
    linklist p;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    p = H;
    while(p->next != NULL)
    {
        printf("%d ",p->next->data);
        p = p->next;
    }
    puts(" ");
    return 0;
}
