#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"
#include "create_link_list.h"

/**
 * 创建链表，头插法
 * inputs：头节点指针的指针
 *         链表长度
 */
void CreateLinkListHead(LinkList *L, int n){
    // 初始化随机数种子
    srand(time(0));
    
    // 创建头节点    
    *L = (LinkList)malloc(sizeof(Node));  // L是Node指针的指针
    (*L)->next = NULL;

    // 定义工作指针，函数内部指针可以先不分配空间；
    LinkList p;
    for(int i=0; i<n; i++){
        // 生成新节点
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;  // 随机生成100以内的数字

        // 插入节点
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

/**
 * 创建链表，尾插法
 * inputs：头节点指针的指针
 *         链表长度
 */
void CreateLinkListTail(LinkList *L, int n){
    srand(time(0));

    // 创建头节点 
    *L = (LinkList)malloc(sizeof(Node));
    //(*L)->next = NULL;

    // 创建工作指针, 并指向头节点
    LinkList p;
    p = (*L);

    for(int i=0; i<n; i++){
        LinkList q = (LinkList)malloc(sizeof(Node));
        q->data = rand() % 100 + 1;
        //q->next = NULL;

        p->next = q;
        p = q;
    }

    p->next = NULL;  // 之前新建的节点都可不指定 ->next = NULL，当链表创建完成指定一次 NULL 就可以；
}


/**
 * 删除链表
 * inputs：头节点指针
 */
void DeleteList(LinkList head){
    LinkList p, q;
    p = head;
    while (p->next)
    {
        q = p;
        p = p->next;
        printf("del %d\n", p->data);
        free(q);
    }
}


// int main(){

//     // 创建头节点指针的指针
//     // LinkList *L = NULL; // 错误（Segmentation fault: 11），Mac中指针需先分配空间再传入函数使用，修改如下：
//     LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    
//     // 创建单链线性表
//     //CreateLinkListHead(L, 5);
//     CreateLinkListTail(L, 5);

//     // 删除线性表
//     DeleteList(*L);
//     return 1;
// }
