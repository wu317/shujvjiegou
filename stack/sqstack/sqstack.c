#include "sqstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

sqstack * stack_create(int len)
{
    sqstack * s;
    if(s = (sqstack *)malloc(sizeof(sqstack)) == NULL)
    {
        printf("malloc sqstack failed\n");
        return NULL;
    }
    if(s->data = (data_t *)malloc(len * sizeof(data_t)) == NULL)
    {
        printf("malloc data falied\n");
        return NULL;
    }
    memrset(s->data,0,len*sizeof(data_t));
    s->maxlen = len;
    s->top = -1;
    return s;
}
int stack_push(sqstack *s, data_t value)
{
    return 0;
}
int stack_empty(sqstack *s)
{
    return 0;
}
int stack_full(sqstack *s)
{
    return 0;
}
data_t stack_pop(sqstack *s)
{
    return 0;
}
data_t stack_top(sqstack *s)
{
    return 0;
}
int stack_clear(sqstack *s)
{
    return 0;
}
int stack_free(sqstack *s)
{
    return 0;
}



