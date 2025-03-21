/* ADT单向链表
 1.数据对象
 单向链表由一系列节点组成，每个节点包括数据域和指针域
 数据域：存储变量的值，即具体数字（如身高，体重）
 指针域：存储下一个节点的地址

 2. 数据关系
 节点通过指针域指向下一个节点，数据域中存储的数据在内存中是不一定连续的，
 在单向链表中这种连接方向是单向的，遍历时只能单向遍历

 3.基本操作（使用的函数）
 初始化Node* Init(LT_data_type data);
 遍历PrintNode(Node *head);
 尾插入Addtail_Node(Node* list,LT_data_type data);
 插入任意节点（不会）
 销毁destroy_list(Node* node);
 删除任意节点（不会）
 查找Search_Node(Node* head, int num);
 */



#include <stdio.h>
#include<malloc.h>


typedef int LT_data_type;//方便更改数据类型
typedef struct _node {
	int data;
	struct _node* next;
}Node;

//单链表初始化函数
Node* Init(int data);
Node* Init(int data)
{
	Node* node1 = (Node*)malloc(sizeof(Node));//调用一个内存中的空间
	node1->data = data;//赋值
	node1->next = NULL;//指向空
	return node1;//返回地址
}

//单链表遍历函数
void PrintNode(Node* list);
void PrintNode(Node* list) {
	Node* temp = list;//暂存头节点地址
	while (temp != NULL) {

		printf("%d\t", temp->data);//打印值
		temp = temp->next;//向下一个节点移动
	}
};

//单链表尾插入函数
void Addtail_Node(Node* list, int data);
void Addtail_Node(Node* list, int data)//输入链表地址和数据
{
	Node* newnode = (Node*)malloc(sizeof(Node));//创建新节点

	//遍历链表到最后一个节点
	Node* temp = list;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	//插入新节点
	newnode->data = data;
	newnode->next = NULL;
	list->next = newnode;
}

//单链表尾销毁函数
void destroy_list(Node* node);
void destroy_list(Node* node) {
	Node* next = NULL;
	//判断当前节点是否为空
	if (node != NULL) {
		next = node->next;//空就往下一个走
		free(node);//释放当前节点内存
		destroy_list(next);
	}
}

//单链表尾查找函数
void Search_Node(Node* head, int num);
void Search_Node(Node* head, int num)//输入首元地址和数据
{
	printf("输入的数字为%d", num);
	//遍历链表到最后一个节点并判断是否有这个数据
	Node* temp = head;
	int cnt = 1;//记录位置
	while (temp->next != NULL) {
		if (num == temp->data) {
			printf("找到了,在第%d个位置", cnt);
			break;
		}
		temp = temp->next;
		printf("没找到");
	}
}

int main()
{

}


