#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"
#include "node.h"


/**
 * 头插法创建链表
 * inputs：头节点指针的指针
 *         链表长度
 */
void CreateListHead(LinkList L, int n){
    // 初始化随机数种子
    srand(time(0));
    
    // 创建头节点    
    // L = (LinkList)malloc(sizeof(Node));  // L是Node指针的指针
    // L->next = NULL;

    // 定义工作指针，函数内部指针可以先不分配空间；
    LinkList p;
    for(int i=0; i<n; i++){
        // 生成新节点
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;  // 随机生成100以内的数字

        // 插入节点
        p->next = L->next;
        L->next = p;
    }
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

int main(){

    // 创建头节点指针的指针
    // LinkList *L = NULL; // 错误（Segmentation fault: 11），Mac中指针需先分配空间再传入函数使用，修改如下：
    //LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    
    // 创建单链线性表
    CreateListHead(L, 5);

    // 删除线性表
    DeleteList(L);
    return 1;
}


/**
 *CreateList2，在函数外先创建头节点，然后让函数完成其余节点的创建；
 #CreateList1，在函数内完成全部操作（包括头节点的创建）然后将头节点（地址）放到指定位置即可； 
 */