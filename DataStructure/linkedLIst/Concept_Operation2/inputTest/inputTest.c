#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char *s1 = NULL;
	while (1) {
		char ch = 'q';
		int det;

		printf("Input data: ");
		s1 = (char*)malloc(sizeof(char) * 100);
		scanf("%s", s1);
		printf("%s\n", s1);

		printf("Compare\n");

		det = strcmp(s1, *(&ch));
		if (!strcmp(s1, *(&ch)))
			printf("�� ���ڿ��� ��ġ�մϴ�.\n");
		else
			printf("�� ���ڿ��� ��ġ���� �ʽ��ϴ�.\n");
	}
}