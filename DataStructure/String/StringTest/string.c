#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {

	// ���ڿ��� charŸ���� �迭�� �� ĭ���� ���� �ϳ��� �����.
	// ���ڿ��� ������ null('\0') ����Ͽ�, ���ڿ��� ������ �˷����Ѵ�.
	char str[6];
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("str : %s\n", str);

	// c���� ���ڿ� ����
	// string literal ��Ŀ����� ���ڿ� ������ �Ұ����ϴ�.
	char str2[] = "hello";
	printf("str2 : %s\n\n", str2);
	// char *str2 = "hello"

	//string.h ���̺귯���� ���ڿ��� �ٷ�� �پ��� �Լ��� ����
		// strcpy : ���ڿ� ����
		// strlen : ���ڿ��� ����
		// strcat : ���ڿ� ��ġ��
		// strcmp : ���ڿ� ��


	char *words[100]; // ���ڿ��� �ּҸ� ����Ű�� ������ �迭
	char buffer[BUFFER_SIZE];
	int n = 0;
	char* p;

	/*while (n<4 && scanf_s("%s", buffer) != EOF) {
		p = malloc((char*)malloc(BUFFER_SIZE));
		if (p != NULL) {
			strcpy(p, buffer);
			words[n] = p;
			n++;
		}
	}

	for (int i = 0; i < 4; i++) {
		printf("%s\n", words[i]);
	}*/

	FILE* fp = fopen("input.txt", "r");
	char buffer2[100];
	while (fscanf(fp, "%s ", buffer2) != EOF) 
		printf("%s", buffer2);
	fclose(fp);
	return 0;
}