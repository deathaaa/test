#include<stdio.h>
#include<malloc.h>
//无头结点



//定义Node结构体为Node
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//定义struct Node *  为LinkList
//LinkList L 即为指向Node的指针
typedef struct Node *LinkList;

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
	if (P->next = NULL)
		return 0;
	int i = 1;
	while (i < position && P != NULL ) {
		P = P->next;
		i++;
	}
	if (P == NULL) {
		return 0;
	}
	*e = P->data;
}

int findNumber(LinkList L, int number) {
	LinkList P = L;
	int position = 1;
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

int addElement(LinkList *L, int position,int number) {
	LinkList P = *L;
	int i = 1;
	while (i < position&&P!=NULL) {
		P = P->next;
		i++;
	}

	if (P == NULL) {
		return 0;
	}

	LinkList A = (LinkList)malloc(sizeof(Node));
	A->data = number;
	A->next = P->next;
	P = A;

	return 1;
	
}
int deleteElement(LinkList *L, int position, int *e) {
	LinkList P = *L;
	int i = 1;

	while (i < position-1&&P != NULL) {
		P = P->next;
		i++;
	}
	if (P == NULL) {
		return 0;
	}
	*e = P->data;
	P = P->next;
	return 1;

}
int main() {
	//初始化一个链表，此为头指针
	LinkList L;

	return 0;
}