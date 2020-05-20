#include "global.h"

/* 
有些语言无指针，无法用 LinkList 的方法实现
用结构体数组实现，线性表的（静态）链表存储结构 
*/

// 链表最大长度
#define MAXSIZE 1000

// 元素类型
typedef int ElemType;

// 数组的元素为结构体
typedef struct
{
    ElemType data; // 数据
    int cur; // 游标，为0表示无指向
}Component, StaticLinkList[MAXSIZE];  // Component 即数组元素，StaticLinkList 即数组
