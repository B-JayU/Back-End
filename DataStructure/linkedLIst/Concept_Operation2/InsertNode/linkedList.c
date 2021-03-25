#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL; // 전역변수 head NULL 초기화

void insert(Node*);
void showLinkedList();

int main() {

	char buffer;
	char cmd;
	char* data = NULL;
	Node* temp;

	printf("연결리스트 새로운 노드 삽입하기 \n");
	
	while (1) {
		
		printf("Input data( i : insert, s : showData , q : quit) : ");
		scanf("%c", &cmd);

		if (cmd=='q') {
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
		else if(cmd == 'i') {
			// 새로운 노드 생성
		
			temp = (Node*)malloc(sizeof(Node)); // 노드 동적할당
			printf("추가할 데이터를 입력하세요 : ");
			data = (char*)malloc(sizeof(char) * 50);
			scanf("%s", data);
			scanf("%c", &buffer);
			temp->data = data;
			temp->next = NULL;

			insert(temp);
		}
		else if (cmd == 's') {
			showLinkedList(head);
			scanf("%c", &buffer);
		}
		else {
			printf("잘못된 입력입니다.\n");
			scanf("%c", &buffer);
			continue;
		}
	}
	
	
	return 0;
}

void insert(Node* n) {

	n->next = head;
	head = n;
}


void showLinkedList(Node* head) {

	while (head) {
		printf("%s\n", head->data);
		head = head->next;
	}
}