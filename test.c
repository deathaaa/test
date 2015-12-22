#include <stdio.h>
//@all 返回1说明成功
typedef struct {
	int date[10];
	int length;
} testList;

int initList(testList *L) {
	L->length = 0;
	return 1;
}
int getElement(testList L, int i, int *e) {
	if (L.length == 0 || i < 1 || i >10) {
		return 0;
	}

	*e = L.date[i - 1];
	return 1;

}
int addElement(testList *L, int position, int i) {
	
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