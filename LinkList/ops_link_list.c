#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "create_link_list.h"

Status GetElem(LinkList L, int i, ElemType *e){
    // 工作指针
    LinkList p;
    p = L;

    // 查找第i个元素
    int j = 0;
    while(p->next && j<i){
        j+=1;
        p = p->next;
    }
    
    // 未找到第i个元素
    if (j!=i)
        return ERROR;

    *e = p->data;
    return OK;
}

int main(){
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    CreateLinkListHead(L, 10);

    int i = 8;
    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    Status s = GetElem(*L, i, e);

    DeleteList(*L);

    if (s){
        printf("get %dth Elem:%d\n", i, *e);
    }else{
        printf("get %dth Elem failed.\n", i);
    }
    return 1;
}