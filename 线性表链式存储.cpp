#include<stdio.h>
#include<malloc.h>
//��ͷ���



//����Node�ṹ��ΪNode
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//����struct Node *  ΪLinkList
//LinkList L ��Ϊָ��Node��ָ��
typedef struct Node *LinkList;

int initList(LinkList *L) {

	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return 0;
	(*L)->next = NULL;
	return 1;
}
//position��1��ʼ�����Ǵ�0��ʼ
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
	//û�в��ҵ�
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
	//��ʼ��һ��������Ϊͷָ��
	LinkList L;

	return 0;
}