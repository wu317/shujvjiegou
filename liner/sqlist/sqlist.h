/*
typedef int data_t;
#define N 128

struct sqlis_t {
    data_t data[N];
    int last;
};
typedef struct sqlist_t sqlist;  //sqlist L;struct sqlist_t L;
typedef struct sqlist_t * sqlink;//sqlink p;struct sqlist_t *p;
*/

typedef int data_t;
#define N 128

typedef struct {
    data_t data[N];
    int last;
}sqlist,*sqlink;

sqlink list_create(void);
int list_clear(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink L);
int list_locate(sqlink L,data_t value);
int list_insert(sqlink L,data_t value,int pos);
int list_show(sqlink L);


