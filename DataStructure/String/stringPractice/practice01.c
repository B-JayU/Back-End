//practice 01. buffer size��ŭ ���ڿ� �о���̱�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int read_line(char*, int);

int main() {

	char str[BUFFER_SIZE];
	while (1) {
		int len = 0;
		printf("$ ");
		// gets�Լ��� �ٹٲ� �Է��ϱ� ������ 1���� �״�� �о���δ�.
		// �ٸ�, buffer ����� ������� ����
		
		//maxCount�� sizeof(str) �Ǵ� buffer_size��ũ ����
		// stdin ��� Ư�� ���Ϸκ��� �Է��� �޾ƿ� �� �ִ�.
		//fgets�� new line���ڱ��� �����Ѵ�.
		/*fgets(str, BUFFER_SIZE, stdin);
		str[strlen(str) - 1] = '\0';
		printf("%s:%d\n", str, (int)strlen(str));
		*/
		
		len += read_line(str, BUFFER_SIZE);
		printf("%s:%d\n", str, len);
		
	}
	return 0;
}

int read_line(char str[], int limit) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < limit)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i; // �о���� ���ڿ� ����Ʈ ���� ��ȯ
}