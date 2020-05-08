
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
