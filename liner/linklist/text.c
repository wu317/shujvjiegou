#include <stdio.h>
#include "linklist.h"

int test_get(void);

int main()
{
    int value;
    linklist H;
    H = list_create();
    if(H == NULL)
        return -1;
    printf("input:");
    while(1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        list_tali_insert(H,value);
        printf("input:");
    }
    list_show(H);

    list_insert(H,1,4);
    list_show(H);
    return 0;
}

int test_get(void)
{
    int value;
    linklist H;
    linklist p;
    H = list_create();
    if(H == NULL)
        return -1;
    printf("input:");
    while(1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        list_tali_insert(H,value);
        printf("input:");
    }
    list_show(H);

    p = list_get(H,4);
    if(p != NULL)
        printf("value=%d\n",p->data);
    return 0;
}
