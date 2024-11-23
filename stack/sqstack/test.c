#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
int main()
{
    sqstack *s;

    s = stack_create(100);
    if(s == NULL)
    {
        printf("stack create failed\n");
        return -1;
    }
    stack_push(s,10);
    stack_push(s,20);
    stack_push(s,30);
    while(!stack_empty(s))
    {
        printf("pop:%d\n",stack_pop(s));
    }
    stack_free(s);
    return 0;
}