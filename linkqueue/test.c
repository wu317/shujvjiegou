#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

int main()
{
    linkqueue *lq;
    lq = queue_create();
    if(lq == NULL)
    {
        printf("lq create failed\n");
        return -1;
    }
    queue_enqueue(lq,10);
    queue_enqueue(lq,20);
    queue_enqueue(lq,30);
    /*
    while(!queue_empty(lq))
    {
        printf("dequeue:%d\n",queue_dequeue(lq));
    }
    */
   queue_clear(lq);
   
    lq = queue_free(lq);
    return 0;
}