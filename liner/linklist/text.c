#include <stdio.h>
#include "linklist.h"

int test_get(void);
int test_insert(void);
int test_delete_free(void);
int test_reverse(void);
int test_adjmax(void);
int main()
{
    linklist H1,H2;
    int a[] = {1,4,6,8,9};
    int b[] = {2,6,7};
    int i;
    
    H1 = list_create();
    if(H1 == NULL)
        return -1;
    H2 = list_create();
    if(H2 == NULL)
        return -1;

    for(i = 0;i<sizeof(a)/sizeof(a[0]);i++)
        list_tali_insert(H1,a[i]);

    for(i = 0;i<sizeof(b)/sizeof(b[0]);i++)
        list_tali_insert(H2,b[i]);

    list_show(H1);
    list_show(H2);

    list_merge(H1,H2);
    list_show(H1);

    list_free(H1);
    list_free(H2);

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

int test_insert(void)
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

int test_delete_free(void)
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
    H = list_free(H);
    list_delete(H,0);

    list_show(H);

    H = list_free(H);
    return 0; 
}
int test_reverse(void)
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
    list_reverse(H);

    list_show(H);

    H = list_free(H);
    return 0;
}
int test_adjmax(void)
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
    p = list_adjmax(H);
    if(p != NULL && p != H)
    {
        printf("max:%d\n",p->data+p->next->data);
    }

    H = list_free(H);
    return 0;
}