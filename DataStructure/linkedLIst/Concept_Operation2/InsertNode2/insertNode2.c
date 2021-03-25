#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL; // 전역변수 head NULL 초기화
//Node* pre = NULL;
//Node* current = NULL;

void insert_after(Node*);
Node* find(Node*);
void remove_data(int n);
void showLinkedList(Node*);

int main() {

	char cmd[10];
	int data;
	Node* temp;

	printf("연결리스트 새로운 노드 삽입/삭제하기 \n");

	while (1) {

		printf("-------- insert : 삽입 , delete : 삭제 , show : 확인 , quit : 종료 --------\n");
		printf("키워드를 입력하세요 : ");
		
		scanf("%s", cmd);

		if (!strcmp(cmd, "quit")) {
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
		else if (!strcmp(cmd, "insert")) {
			// 새로운 노드 생성

			temp = (Node*)malloc(sizeof(Node)); // 노드 동적할당
			printf("추가할 정수형 데이터를 입력하세요 : ");
			scanf("%d", &data);
			//scanf("%s", buffer);
			temp->data = data;
			temp->next = NULL;

			insert_after(temp);
		}
		else if (!strcmp(cmd, "delete")) {
			printf("삭제할 정수형 데이터를 입력하세요 : ");
			scanf("%d", &data);
			remove_data(data);
		}
		else if (!strcmp(cmd, "show")) {
			showLinkedList(head);
		}
		else {
			printf("잘못된 입력입니다.\n");
			continue;
		}
	}
	return 0;
}

void insert_after(Node* n) {

	Node* prev;
	prev = find(n);
	
	if (prev == NULL) {
		n->next = head;
		head = n;
	}
	else {
		n->next = prev->next;
		prev->next = n;
	}
}

void remove_data(int n) {

	Node *pre = NULL, *cur = head;
	Node* temp;

	while (cur != NULL && n > cur->data) {
		pre = cur;
		cur = cur->next;
	}

	if (cur == NULL) {
		printf("Data not exist\n");
		return;
	}
	else {
		if (cur->data == n) {
			if (pre == NULL) { // 맨 앞 노드 삭제
				temp = cur;
				head = head->next;
				free(temp);
				printf("Deleted\n");
			}
			else {
				temp = cur;
				pre->next = cur->next;
				free(temp);
				printf("Deleted\n");
			}
		}
		else {
			printf("Data not exist\n");
		}
	}
}

void showLinkedList(Node* head) {

	if (head == NULL)
		printf("Data Not exist\n");

	while (head) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

Node* find(Node* n) {

	Node *pre=NULL, *cur = head;

	while (cur != NULL && n->data > cur->data) {
		pre = cur;
		cur = cur->next;
	}
	
	return pre;
}