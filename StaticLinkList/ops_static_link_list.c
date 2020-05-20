#include "static_link_list.h"

/**
 * 初始化静态链表
 */
Status InitList(StaticLinkList space){
    int i;

    // 初始化每个元素的游标（为下一个元素的下标）
    // 链成一个备用链表
    for (i=0; i<MAXSIZE-1; i++){
        space[i].cur = i+1;
    }

    // 最后一个元素游标为第一个插入元素的下标，
    // 链表为空时，初始化为0，表示空指针
    // 类似头节点
    space[MAXSIZE-1].cur = 0; 
}

/**
 * 模拟动态链表中的空间申请 malloc 函数
 * 若备用链表非空，则返回分配的节点下标，否则返回0
 */
int Malloc_SLL(StaticLinkList space){
    int i = space[0].cur; // 取得第一个元素的cur值，空间空间的第一个元素下标

    if(i)
        space[0].cur = space[i].cur; // 更新空闲空间第一个元素下标

    return i;
}

