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
    return 0;
}