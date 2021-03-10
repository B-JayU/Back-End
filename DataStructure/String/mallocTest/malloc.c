#include <stdio.h>
#include <stdlib.h>

int main() {

	int* p, * array, * temp;
	int i;

	p = (int*)malloc(4 * sizeof(int));

	if (p == NULL) {
		return -1;
	}

	p[0] = 12;
	p[1] = 24;
	*(p + 2) = 36;
	*(p + 3) = 48;

	temp = (int*)malloc(8 * sizeof(int));
	if (temp == NULL) {
		return -1;
	}

	for (i = 0; i < 4; i++) {
		*(temp + i) = *(p + i);
	}

	array = temp;

	*(array + 4) = 60;
	*(array + 5) = 72;
	*(array + 6) = 84;
	*(array + 7) = 96;

	printf("배열 array 출력하기\n");
	for (i = 0; i < 8; i++) {
		printf("%d ", *(array + i));
	}

	return 0;
}