typedef int datatype;

typedef struct node{
    datatype data;
    struct node *next; 
}list_node, *linklist;

typedef struct{
    linklist front;
    linklist rear;
}linkqueue;

linkqueue *queue_create(void);
int queue_enqueue(linkqueue *lq,datatype x);
datatype queue_dequeue(linkqueue *lq);
int queue_empty(linkqueue *lq);
int queue_clear(linkqueue *lq);
linkqueue * queue_free(linkqueue *lq);