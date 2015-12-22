#include <stdio.h>
//@all 返回1说明成功
typedef struct {
	int data[10];
	int length;
} testList;

int initList(testList *L) {
	L->length = 0;
	return 1;
}
int getElement(testList L, int i, int *e) {
	if (L.length == 0 || i < 1 || i >L.length) {
		return 0;
	}

	*e = L.data[i - 1];
	return 1;

}
int addElement(testList *L, int position, int i) {
	if (L->length >= 10|| position < 1 || position > L->length+1) {
		return 0;
	}
	L->length = L->length + 1;
	if (position <= L->length) {
		for (int j = L->length; j >= position; j--) {
			L->data[j] = L->data[j - 1];
		}

		
	}
	L->data[position - 1] = i;

	return 1;
}

int deleteElement(testList *L, int position, int *e) {
	if (L->length == 0 || position<1 || position>L->length) {
		return 0;
	}
	*e = L->data[position - 1];
	if (position < L->length) {
		for (int i = position - 1; i <= L->length - 2; i++) {
			L->data[i] = L->data[i + 1];
		}
	}
	L->length = L->length - 1;

}

int main() {
	int *point;
	int value = 1;
	
	point = &value;

	printf("%d\n", value);

	*point = 3;

	printf("%d\n", value);

	system("pause");
	return 0;
}