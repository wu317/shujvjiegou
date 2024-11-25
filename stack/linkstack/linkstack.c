#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

linkstack stack_create()
{
    linkstack s;
    s = (linkstack)malloc(sizeof(list_node));
    if(s == NULL)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    s->data = 0;
    s->next = NULL;

    return s;
}
int stack_push(linkstack s,data_t value)
{
    linkstack p;
    if(s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }
    p = (linkstack)malloc(sizeof(list_node));
    if(p == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    p->data = value;
    //p->next = NULL;

    p->next = s->next;
    s->next = p;
    return 0;
}
data_t stack_pop(linkstack s)
{
    if(s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }
    linkstack p;
    data_t value;
    p = s->next;
    s->next = p->next;
    value = p->data;
    free(p);
    p = NULL;
    return value;
}
int stack_empty(linkstack s)
{
    if(s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }
    return (s->next == NULL ? 1 :0);
}
data_t stack_top(linkstack s)
{
    return (s->next->data);
}
linkstack stack_free(linkstack s)
{
    if(s == NULL)
    {
        printf("s is NULL\n");
        return NULL;
    }
    linkstack p;
    while(s != NULL)
    {
        p = s;
        s = s->next;
        printf("free:%d\n",p->data);
        free(p);
    }

    return NULL;
}