#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//注意带头结点
typedef struct QNode {
	int date;
	struct QNode *next;

}QNode,*QueuePtr;

typedef struct LinkQueue {
	QueuePtr front, rear;
}LinkQueue;

int initQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		return 0;

	Q->front->next = NULL;
	

}


int add(LinkQueue *Q, int data) {

	QueuePtr L = (QueuePtr)malloc(sizeof(QNode));

	if (!L)
		return 0;

	L->date = data;
	L->next = NULL;

	Q->rear->next = L;
	Q->rear = L;

	return 1;
}

int del(LinkQueue *Q,int *e) {
	if (Q->front->next == NULL)
		return 0;

	QueuePtr L = Q->front->next;
	*e = L->date;
	Q->front->next = L->next;

	if (L == Q->rear)
		Q->rear = Q->front;

	free(L);

	return 1;

}

int main() {

	LinkQueue Q;



	return 0;
}