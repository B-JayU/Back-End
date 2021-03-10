//practice 02. trim 공백 제거함수 구현하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int trim(char*, char*, int);

int main() {

	char buffer[BUFFER_SIZE];
	char s[100];
	int len;

	while (1) {
		printf("$ ");
		gets(buffer, BUFFER_SIZE, stdin);
		//printf("%s", buffer);
		len = trim(buffer, s, strlen(buffer));
		s[len] = '\0';
		printf("%s:%d\n", s, strlen(s));
	}
	return 0;
}

int trim(char buf[], char str[], int bufsize) {
	int i = 0, n = 0;
	int start = 0;

	while (i < bufsize || buf[i] != '\0') {
		
		// 문장 앞에 공백지우기
		while (n == 0 && buf[i] == ' ')
			i++;

		// 단어 사이에 2개 이상의 공백지우기
		while (buf[i] == ' ' && buf[i + 1] == ' ')
			i++;

		// 문장 뒤에 공백지우기
		while (buf[i] == ' ' && buf[i + 1] == '\0')
			i++;

		if (i < bufsize)
			str[n++] = buf[i++];
	}
	return n;
}