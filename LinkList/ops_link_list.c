#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "create_link_list.h"

/**
 * 获取链表指定元素
 * inputs：链表头节点指针，指定元素序号，返回元素指针
 */
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
    if (j != i)
        return ERROR;

    *e = p->data;
    return OK;
}

/**
 * 插入元素到指定位置
 * inputs：链表头节点指针，指定插入位置，待插入节点数据
 */
Status InsertElem(LinkList L, int i, ElemType e){
    // 工作指针
    LinkList p;
    p = L;

    // 查找第i-1个位置
    int j = 0;
    while(p->next && j<i-1){
        j++;
        p = p->next;
    }

    // 判断是否找到
    if (j != i-1)
        return ERROR;
    
    // 新建节点
    Node * q = (Node *)malloc(sizeof(Node));
    q->data = e;

    // 插入第i个节点
    q->next = p->next;
    p->next = q;

    return OK;
}

/**
 * 删除指定位置元素
 * inputs：链表头节点指针，指定删除位置，删除数据返回指针
 */
Status DeleteElem(LinkList L, int i, ElemType *e){
    // 创建工作指针
    LinkList p;
    p = L;

    // 查找第i-1个位置
    int j=0;
    while (p->next && j<i-1)
    {
        j++;
        p = p->next;
    }

    // 判断是否找到第i-1个位置
    if (j != i-1)
        return ERROR;
    
    // 删除第i个节点
    LinkList q = p->next;    
    *e = q->data;
    p->next = q->next;

    // 别忘了释放删除掉的节点
    free(q);

    return OK;
}

int main(){
    // 整表创建
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    CreateLinkListHead(L, 10);

    // 链表读取
    int i = 8;
    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    Status s = GetElem(*L, i, e);

    if (s){
        printf("get %dth Elem:%d\n", i, *e);
    }else{
        printf("get %dth Elem failed.\n", i);
    }

    // 链表插入
    s = InsertElem(*L, i, 666);

    // 链表删除
    ElemType *d = (ElemType *)malloc(sizeof(ElemType));
    s = DeleteElem(*L, i, d);

    if (d){
        printf("delete %dth Elem:%d\n", i, *d);
    }else{
        printf("delete %dth Elem failed.\n", i);
    } 

    // 整表删除
    DeleteList(*L);
    return 1;
}