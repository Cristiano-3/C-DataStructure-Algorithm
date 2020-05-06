#ifndef NULL
    #ifdef _cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif

typedef int ElemType;

typedef struct LinkList
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct  Node *LinkList;


/*
头插法创建链表
生成N个节点的单链表
*/
void CreateListHead(LinkList *L, int n){
    srand(time(0));
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));  // L是Node指针的指针
    (*L)->next = NULL;

    for(int i=0; i<n; i++){
        // 生成新节点
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;  // 随机生成100以内的数字
        p->next = (*L)->next;
        (*L)->next = p;
    }


}