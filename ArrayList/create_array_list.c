#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "array_list.h"

/**
 * 读取指定位置元素
 * inputs：线性表结构体，指定位置，元素返回指针
 */
Status GetElem(ArrayList A, int i, ElemType *e){
    // 位置合法判断
    if (i>A.length || i<1 || A.length==0){
        return ERROR;
    }

    *e = A.data[i-1];  // 注意：数组第i个元素，下标索引为i-1
    return OK;
}

/**
 * 元素插入指定位置
 * inputs：线性表结构体，插入位置，待插入元素
 */
Status Insert(ArrayList *A, int i, ElemType e){
    // 是否已存满
    if (A->length == MAXSIZE)
        return ERROR;

    // 位置是否合法
    if (i<1 || i>A->length+1)
        return ERROR;

    // 判断是否需要挪动（是否插入表尾）
    if (i <= A->length){

        int k; // 工作索引
        for(k=A->length-1; k>=i-1; k--){  // 第i个及之后的元素都后移，这里i-1是因为数组下标从0开始；
            A->data[k+1] = A->data[k];    // 向后移动一位
        }
    }    

    // 插入值并更新表的长度
    A->data[i-1] = e;
    A->length++;

    return OK;
}


int main(){
    // 结构体变量创建，结构体成员变量初始化方法1
    ArrayList A = {{3,4,5,6,7,}, 5};

    // 初始化方法2
    // ArrayList A;
    // A.data[0] = 100;  
    // A.length = 1;  
    
    // 插入末尾
    Insert(&A, (A.length+1), 6);  // 结构体传址 Insert(ArrayList* A, ...)，函数才能修改其值
    Insert(&A, (A.length+1), 9);  // 传值 Insert(ArrayList A, ...) 则不可
    Insert(&A, 5, 8);

    // 读取
    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    for(int i=1; i<=A.length; i++){
        GetElem(A, i, e);  // 这里是传值
        printf("get value:%d\n", *e);
    }
}