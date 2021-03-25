#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define BUF_SIZE 1024
void ErrorHandling(char* message);
int calculate(int opnum, int opnds[], char operator);

int main(int argc, char* argv[]) {

	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	char message[BUF_SIZE];
	int result, opnd_cnt, recvLen, recvCnt;

	SOCKADDR_IN servAdr,clntAdr;
	int clntAdrSize;

	argc = 2;
	argv[0] = "server";
	argv[1] = "9190";
	
	if (argc != 2) {
		printf("usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socekt() error!");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	clntAdrSize = sizeof(clntAdr);

	// 실제 구현부분

		opnd_cnt = 0; // 피연산자 개수 초기화
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
		recv(hClntSock, &opnd_cnt, 1, 0); // 피연산자 개수 recv

		recvLen = 0;
		while ((opnd_cnt * sizeof(int) + 1) > recvLen) { // +1은 마지막에 연산자를 읽어들이기 위함.
			recvCnt = recv(hClntSock, &message[recvLen], BUF_SIZE - 1, 0);
			recvLen += recvCnt;
		}
	
		result = calculate(opnd_cnt, (int*)message, message[recvLen - 1]);
		send(hClntSock, (char*)&result, sizeof(result), 0);

		closesocket(hClntSock);
		closesocket(hServSock);
		WSACleanup();
		return 0;

}
int calculate(int opnum, int opnds[], char operator) {

	int result=opnds[0]; // 첫번째 피연산자가 저장

	switch (operator) {
		case '+':
			for (int i = 1; i < opnum; i++) result += opnds[i];
			break;
		case '*':
			for (int i = 1; i < opnum; i++) result *= opnds[i];
			break;
		case '-':
			for (int i = 1; i < opnum; i++) result -= opnds[i];
			break;
	}

	return result;
}

void ErrorHandling(char* message) {

	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}