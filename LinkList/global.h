// 定义 NULL
#ifndef NULL
    #ifdef _cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// 函数返回值
typedef int Status;