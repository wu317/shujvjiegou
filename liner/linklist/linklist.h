typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}list_node,*linklist;

linklist list_create(void);//����������
int list_tali_insert(linklist H,data_t value);//β������
linklist list_get(linklist H,int pos);//�����(λ��)����
int list_insert(linklist H,data_t value,int pos);//�����(λ��)����
int list_delete(linklist H,int pos);//�����(λ��)ɾ��
int list_show(linklist H);//����ı���
linklist list_free(linklist H);//�ͷ�����
int list_reverse(linklist H);//����ת
linklist list_adjmax(linklist H);//��������Ԫ�����ֵ