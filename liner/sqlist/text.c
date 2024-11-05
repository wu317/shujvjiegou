#include <stdio.h>
#include "sqlist.h"

int main()
{
    sqlink L;
    L = list_create();
    if (L == NULL) {
        printf("创建线性表失败！\n");
        return -1;
    }
    printf("创建线性表成功！\n");
    return 0;
}

