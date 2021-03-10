#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {

	// 문자열은 char타입의 배열의 각 칸마다 문자 하나씩 저장됨.
	// 문자열의 끝에는 null('\0') 명시하여, 문자열이 끝남을 알려야한다.
	char str[6];
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("str : %s\n", str);

	// c언어에서 문자열 생성
	// string literal 방식에서는 문자열 수정이 불가능하다.
	char str2[] = "hello";
	printf("str2 : %s\n\n", str2);
	// char *str2 = "hello"

	//string.h 라이브러리는 문자열을 다루는 다양한 함수를 제공
		// strcpy : 문자열 복사
		// strlen : 문자열의 길이
		// strcat : 문자열 합치기
		// strcmp : 문자열 비교


	char *words[100]; // 문자열의 주소를 가리키는 포인터 배열
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