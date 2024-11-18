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
    if(pos < -1)
    {
        printf("pos is invalid\n");
        return NULL;
    }
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

int list_delete(linklist H,int pos)
{
    linklist p;
    linklist q;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    } 
    //找到结点的前一个结点
    p = list_get(H,pos-1);
    if(p == NULL)
        return -1;
    if(p->next == NULL)
    {
        printf("delete pos is invalid\n");
        return -1;
    }
    //修改结点
    q = p->next;
    p->next = q->next; 
    //释放要删除的节点
    printf("free:%d\n",q->data);
    free(q);
    q = NULL;
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

linklist list_free(linklist H)
{
    linklist p;
    if(H == NULL)
        return NULL;
    p = H;
    printf("free:");
    while(H != NULL)
    {
        p = H;
        printf("%d ",p->data);
        H = H->next;
        free(p);
    }
    puts(" ");
    H = NULL;//需要将该释放的指针传到main函数中去，该函数中的H为形式参数，只释放它无效，所以该函数需要一个返回值，返回该释放的指针，或者创建一个二级指针作为参数，进行释放
    return H;
}

int list_reverse(linklist H)
{
    linklist p;
    linklist q;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    if(H->next == NULL)
    {
        printf("H is empty\n");
        return 0;
    }
    if(H->next->next == NULL)
    {
        printf("H only has one node\n");
        return 0;
    }
    p = H->next->next;
    H->next->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
    return 0;
}
linklist list_adjmax(linklist H)
{
    linklist p,q,r;
    data_t sum = 0;
    if(H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }
    if(H->next ==NULL || H->next->next == NULL || H->next->next->next == NULL)
    {
        printf("H is empty or only has one or two node\n");
        return H;
    }
    q = H->next;
    p = q->next;
    r = q;
    sum = q->data + p->data;
    while(p->next != NULL)
    {
        q = q->next;
        p = p->next;
        
        if((q->data + p->data) > sum)
        {
            sum = q->data + p->data;
            r = q;
        }
    }
    return r;
}