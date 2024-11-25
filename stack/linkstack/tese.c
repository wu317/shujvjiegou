#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int main()
{
    linkstack s;
    s = stack_create();
    if(s == NULL)
    {
        printf("s is NULL");
        return -1;
    }
    stack_push(s,10);
    stack_push(s,20);
    stack_push(s,30);

    /*while(!stack_empty(s))
    {
        printf("pop:%d\n",stack_pop(s));  
    }
    */
    s = stack_free(s);
    return 0;
}