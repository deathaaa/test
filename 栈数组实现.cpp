#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10



typedef struct {
	int data[MAXSIZE];

	//top的位置  -1表示为空栈
	int top;
}sqStack;

int initStack(sqStack *L) {
	L->top = -1;

	return 1;
}

int push(sqStack *L, int e) {
	if ((L->top) == MAXSIZE - 1)
		return 0;

	L->top++;
	L->data[L->top] = e;
	return 1;
		
}

int pop(sqStack *L,int *e){
	if (L->top = -1)
		return 0;

	*e = L->data[L->top];
	L->top--;
	return 1;
}


int main() {

	return 0;
}