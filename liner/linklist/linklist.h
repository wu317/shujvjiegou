typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}list_node,*linklist;

linklist list_create(void);//创建空链表
int list_tali_insert(linklist H,data_t value);//尾部插入
linklist list_get(linklist H,int pos);//按序号(位置)查找
int list_insert(linklist H,data_t value,int pos);//按序号(位置)插入
int list_delete(linklist H,int pos);//按序号(位置)删除
int list_show(linklist H);//链表的遍历
linklist list_free(linklist H);//释放链表
int list_reverse(linklist H);//链表反转
linklist list_adjmax(linklist H);//链表相邻元素最大值