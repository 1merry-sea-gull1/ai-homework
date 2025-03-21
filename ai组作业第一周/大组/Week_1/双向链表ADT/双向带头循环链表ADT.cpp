/* ADT双向带头节点循环链表
 1.数据对象
 双向链表由一系列节点组成，每个节点包括数据域和指针域（next和pre)
 数据域：存储变量的值，即具体数字（如身高，体重）
 next指针域：存储下一个节点的地址
 pre指针域：存储上一个节点的地址

 2. 数据关系
 节点通过next指向下一个节点，节点通过pre指向上一个节点，
 数据域中存储的数据在内存中是不一定连续的，
 在单向链表中这种连接方向是双向的，遍历时可以正，反向遍历

 3.基本操作（使用的函数）
 创建头节点dNode* dList(LT_data_type data);
 初始化dNode* Init();
 双向带头链表正向遍历函数dPrint1(dNode* dlist);
 双向带头链表反向遍历函数dPrint2(dNode* dlist);
 插入（不会）
 双向链表销毁destroy_list(dNode* node);
 双向链表搜索函数Search_dNode(dNode* dlist, int num);
 */









#include<stdio.h>
#include<malloc.h>

typedef int LT_data_type;//方便更改数据类型

typedef struct dListnode {
    LT_data_type data;
    struct dListnode* pre;
    struct dListnode* next;
}dNode;

//创建头节点
dNode* dList(LT_data_type data);
dNode* dList(LT_data_type data) {
    dNode* node = (dNode*)malloc(sizeof(dNode));
    node->data = data;
    node->pre = node;
    node->next = node;
    return node;
}

//初始化链表
dNode* dInit();
dNode* dInit() {
    dNode* pdHead = dList(-1);
    return pdHead;
}

//双向带头链表正向遍历函数
void dPrint1(dNode* dlist);
void dPrint1(dNode* dlist)//输入链表头节点地址
{   
    //判断链表是否为空
    if (dlist == NULL) {
        printf("链表为空！\n");
        return;
    }

    //遍历链表到最后一个节点
    dNode* temp = dlist->next;//暂存头节点地址
    while (temp != dlist) {
        printf("%d\t", temp->data);//打印值
        temp = temp->next;//向下一个节点移动
    }

}

//双向带头链表反向遍历函数
void dPrint2(dNode* dlist);
void dPrint2(dNode* dlist) {
    //判断链表是否为空
    if (dlist == NULL) {
        printf("链表为空！\n");
        return;
    }



    // 从尾节点开始反向遍历
    dNode* temp = dlist->pre;
    while (temp != dlist) {
        printf("%d\t", temp->data);
        temp = temp->pre; // 移动到上一个节点
    }
    printf("\n");
}

//双向链表尾插法
int dAdd_tail(dNode* head,int data);
int dAdd_tail(dNode* head,int data)
{
    dNode* newdnode = (dNode*)malloc(sizeof(dNode));
    newdnode->data = data;
    newdnode->next = head->next;
    newdnode->pre = head;
    if (head->next != NULL) {
        head->next->pre = newdnode;
    }
    head->next = newdnode;
    return 1;
};

//双向链表搜索函数
void Search_dNode(dNode* dlist, int num);
void Search_dNode(dNode* dlist, int num)//输入链表头节点地址
{
    //显示搜索数字
    printf("输入的数字为%d\n", num);
    //判断链表是否为空
    if (dlist == NULL) {
        printf("链表为空！\n");
        return;
    }

    dNode* temp = dlist->next;//暂存头节点下一个节点地址
    int cnt = 1;//记录位置
    while (temp != dlist) {
        if (num == temp->data) {
            printf("找到了,在第%d个位置", cnt);
            break;
        }//打印值
        temp = temp->next;//向下一个节点移动
        printf("没找到");
    }

}

//双向链表销毁
void destroy_list(dNode* node);
void destroy_list(dNode* node) {
    //判断当前节点是否为空
    if (node != NULL) {
        dNode* next = node->next;//空就往下一个走
        destroy_list(next);//先递归删除下一个节点
        free(node);//再释放当前节点内存
    }
};

    int main()
    {


    /*测试链表1
    //dNode head  = { -1,NULL,NULL};
    //dNode node1 = { 20,NULL,NULL };
    //dNode node2 = { 30,NULL,NULL };
    //dNode node3 = { 40,NULL,NULL };
    //dNode node4 = { 50,NULL,NULL };
    //dNode last = { -1,NULL,NULL };

    //head.pre = NULL;
    //head.next = &node1;
    //node1.pre = &head;
    //node1.next = &node2;
    //node2.pre = &node1;
    //node2.next = &node3;
    //node3.pre = &node2;
    //node3.next = &node4;
    //node4.pre = &node3;
    //node4.next = &last;
    //last.pre = &node4;
    //last.next = NULL;*/
    
    /*测试链表2
    //dNode*head=dList();
    //dAdd_tail(head, 20);
    //dAdd_tail(head, 10);*/

    /*测试代码
    printf("正向遍历为：");
    dPrint1(head);
    printf("\n");
    printf("反向遍历为：");
    dPrint2(head);
    printf("\n");
    Search_dNode(head,10);*/

    return 0;
}


