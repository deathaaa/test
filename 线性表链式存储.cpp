#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
//��ͷ��㣬����̫�鷳�˻��Ǹĳɴ�ͷ���İɡ�����



//����Node�ṹ��ΪNode
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//����struct Node *  ΪLinkList
//LinkList L ��Ϊָ��Node��ָ��
typedef struct Node *LinkList;


//����ͷ��㣬��ʼ��һ������
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
	//����ͷ���
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

//��ѯ�������Ƿ���ڸ�����
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
	//û�в��ҵ�
	return 0;
}

//��position���ǰ������½ڵ㣬���¼���Ľڵ���positionλ��
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

//ɾ��positionλ�õ�Ԫ��
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
	//ָ�����һ���ڵ��ָ��   ���������½ڵ��ָ��
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
		printf("%s\n", "��������������");
	}
	LinkList P = L->next;
	while (P != NULL) {
		printf("%d\n", P->data);
		P = P->next;
	}
}
//����ͷ��㣬�ͷ������ڵ��ڴ�
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
	//��ʼ��һ��������Ϊͷָ��
	LinkList L;
	int number;
	createRandomListTail(&L, 2);
	printList(L);

	deleteElement(&L, 2, &number);
	printf("ɾ��������Ϊ%d\n", number);
	printList(L);

	addElement(&L, 1, 1);
	printList(L);

	system("pause");
	return 0;
}