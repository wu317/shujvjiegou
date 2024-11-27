typedef int datatype;
#define N 128

typedef struct{
    datatype data[N];
    int front;
    int rear;
}sequeue;

sequeue * queue_create(void);
int enqueue(sequeue *sq,datatype x);
datatype dequeue(sequeue *sq);
int queue_empty(sequeue *sq);
int queue_full(sequeue *sq);
int queue_clear(sequeue *sq);
sequeue *queue_free(sequeue *sq);
