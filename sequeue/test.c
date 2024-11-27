#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"

int main()
{
    sequeue *sq;
    if((sq = queue_create()) == NULL)
    {
        printf("queue is failed\n");
        return -1;
    }
    enqueue(sq,10);
    enqueue(sq,20);
    enqueue(sq,30);

    while(!queue_empty(sq))
    {
        printf("%d\n",dequeue(sq));
    }
    queue_free(sq);
    return 0;
}