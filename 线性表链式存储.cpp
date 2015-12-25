#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
//无头结点，算了太麻烦了还是改成带头结点的吧。。。



//定义Node结构体为Node
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//定义struct Node *  为LinkList
//LinkList L 即为指向Node的指针
typedef struct Node *LinkList;


//创建头结点，初始化一个链表
int initList(LinkList *L) {

	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return 0;
	(*L)->next = NULL;
	return 1;
}

//position从1开始，不是从0开始
int getElement(LinkList L, int position, int *e) {

	LinkList P = L;
	//仅有头结点
	if (P->next = NULL)
		return 0;

	int i = 1;
	while (i < position && P != NULL) {
		P = P->next;
		i++;
	}
	if (P == NULL) {
		return 0;
	}
	*e = P->next->data;
}

//查询链表中是否存在该数字
int findNumber(LinkList L, int number) {
	LinkList P = L;
	int position = 0;
	while (P != NULL) {
		if (P->data == number) {
			return position;
		}
		position++;
		P = P->next;
	}
	//没有查找到
	return 0;
}

//在position这个前面插入新节点，即新加入的节点在position位置
int addElement(LinkList *L, int position, int number) {
	LinkList P = *L;
	int i = 1;
	while (i < position && P != NULL) {
		P = P->next;
		i++;
	}

	if (P == NULL) {
		return 0;
	}

	LinkList A = (LinkList)malloc(sizeof(Node));
	A->data = number;
	A->next = P->next;
	P->next = A;

	return 1;

}

//删除position位置的元素
int deleteElement(LinkList *L, int position, int *e) {
	LinkList P = *L;
	int i = 1;

	while (i < position && P != NULL) {
		P = P->next;
		i++;
	}
	if (P->next == NULL) {
		return 0;
	}


	LinkList Q = P->next;
	*e = Q->data;
	P->next = Q->next;
	free(Q);
	return 1;

}

void createRandomListHead(LinkList *L, int number) {
	LinkList P;
	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < number; i++) {
		P = (LinkList)malloc(sizeof(Node));
		P->data = rand() % 100 + 1;
		P->next = (*L)->next;

		(*L)->next = P;
	}

}

void createRandomListTail(LinkList *L, int number) {
	//指向最后一个节点的指针   用来创建新节点的指针
	LinkList A, B;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	A = *L;

	for (int i = 0; i < number; i++) {
		B = (LinkList)malloc(sizeof(Node));
		B->data = rand() % 100 + 1;
		A->next = B;
		A = B;
	}
	A->next = NULL;
}

void printList(LinkList L) {
	if ((L->next) == NULL) {
		printf("%s\n", "此链表中无数据");
	}
	LinkList P = L->next;
	while (P != NULL) {
		printf("%d\n", P->data);
		P = P->next;
	}
}
//保留头结点，释放其他节点内存
void deleteList(LinkList *L) {
	LinkList A, B;

	A = (*L)->next;

	while (A != NULL) {
		B = A->next;
		free(A);
		A = B;
	}

	(*L)->next = NULL;
}

int main() {
	//初始化一个链表，此为头指针
	LinkList L;
	int number;
	createRandomListTail(&L, 2);
	printList(L);

	deleteElement(&L, 2, &number);
	printf("删除的内容为%d\n", number);
	printList(L);

	addElement(&L, 1, 1);
	printList(L);

	system("pause");
	return 0;
}