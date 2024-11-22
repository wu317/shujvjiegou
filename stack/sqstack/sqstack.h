typedef int data_t;

typedef struct {
    data_t *data;
    int maxlen;
    int top;
}sqstack;

sqstack * stack_create(int len);// 创建栈
int stack_push(sqstack *s, data_t value); // 入栈
int stack_empty(sqstack *s);// 栈是否为空
int stack_full(sqstack *s);// 栈是否已满
data_t stack_pop(sqstack *s);//出栈
data_t stack_top(sqstack *s);//栈顶元素
int stack_clear(sqstack *s);//清空栈
int stack_free(sqstack *s);//释放栈
