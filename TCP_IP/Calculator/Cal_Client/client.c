#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define BUF_SIZE 1024
void ErrorHandling(char* message);


int main(int argc, char* argv[]) {

	WSADATA wsaData;
	SOCKET sock;
	char message[BUF_SIZE];
	int result, opnd_cnt, i;

	SOCKADDR_IN servAdr;

	argc = 3;
	argv[0] = "client";
	argv[1] = "127.0.0.1";
	argv[2] = "9190";

	if (argc != 3) {
		printf("usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
		ErrorHandling("socket() error!");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
	servAdr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error");
	else
		puts("Connected..............");
	
	// 실제 구현부분
	fputs("Operand count: ", stdout);
	scanf("%d", &opnd_cnt);
	message[0] = (char)opnd_cnt;

	for (i = 0; i < opnd_cnt; i++) {
		printf("Operand %d: ", i + 1);
		scanf("%d", (int*)&message[1+sizeof(int)*i]);
	}
	fgetc(stdin); // \n charater 버퍼 비워주기

	fputs("Operator: ", stdout);
	scanf("%c", &message[sizeof(int)*opnd_cnt + 1]);
	send(sock, message, sizeof(int) * opnd_cnt + 2, 0);
	recv(sock, &result, 4, 0); // 연산된 결과값은 4바이트 정수

	printf("Operation result : %d \n", result);
	
	closesocket(sock);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message) {

	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}