//practice 01. buffer size만큼 문자열 읽어들이기

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
		// gets함수는 줄바꿈 입력하기 전까지 1줄을 그대로 읽어들인다.
		// 다만, buffer 사이즈에 관계없이 수행
		
		//maxCount를 sizeof(str) 또는 buffer_size만크 설정
		// stdin 대신 특정 파일로부터 입력을 받아올 수 있다.
		//fgets는 new line문자까지 포함한다.
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
	return i; // 읽어들인 문자열 바이트 수를 반환
}