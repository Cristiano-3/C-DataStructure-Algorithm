#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 定义 NULL
#ifndef NULL
    #ifdef _cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif

// 定义 结点/元素 数据域类型 ElemType
typedef int ElemType;

// 定义结构体 struct Node
struct Node
{
    ElemType data;
    struct Node *next;
};

// 结构体 struct Node 重命名为 Node
typedef struct Node Node;

// 定义链表 LinkList 为 Node 指针 
typedef Node *LinkList;


/*
头插法创建链表
生成N个节点的单链表
*/
void CreateListHead(LinkList *L, int n){
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

    // LinkList *L = NULL; // 错误（Segmentation fault: 11），Mac中指针需先分配空间再传入函数使用，修改如下：
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    
    // 创建单链线性表
    CreateListHead(L, 5);

    // 删除线性表
    DeleteList(*L);
    return 1;
}
