#include <stdio.h>

int main() {
	int sum, i;
	double average;

	int num[10];

	for (i = 0; i < 10; i++)
		scanf_s("%d", &num[i]);

	sum = calculate_sum(num);
	average = (double)sum / 10;

	printf("num[] array의 평균은 %.2lf입니다.\n", average);

	return 0;
}

int calculate_sum(int *array) {

	int sum = 0, i;
	for (i = 0; i < 10; i++)
		sum += *(array + i);

	return sum;
}