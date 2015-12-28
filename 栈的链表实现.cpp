#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct stackNode {
	int data;
	struct stackNode *next;
}stackNode,*LinkStackPrt;

typedef struct LinkStack {
	LinkStackPrt top;
	int count;
}LinkStack;

int initStack(LinkStack *S) {
	S->top = (LinkStackPrt)malloc(sizeof(stackNode));
	if (!S->top)
		return 0;

	S->top = NULL;
	S->count = 0;
	return 1;
}

int push(LinkStack *S, int e) {
	LinkStackPrt a = (LinkStackPrt)malloc(sizeof(stackNode));

	if (!a)
		return 0;

	a->data = e;
	a->next = S->top;

	S->top = a;
	S->count++;
	return 1;

}

int pop(LinkStack *S, int *e) {
	if (S->count == 0)
		return 0;

	*e = S->top->data;
	stackNode *p = (LinkStackPrt)malloc(sizeof(stackNode));
	p = S->top;
	S->top = p->next;
	free(p);
	S->count--;
	return 1;
}

void printStack(LinkStack S) {
	if (S.count == 0)
		printf("链表为空，无法打印");
	LinkStackPrt A = S.top;

	while (A) {
		printf("%d", A->data);
		A = A->next;
	}

}
int main() {
	LinkStack S;
	if (initStack(&S) == 0)
		printf("创建栈失败\n");


	return 0;
}