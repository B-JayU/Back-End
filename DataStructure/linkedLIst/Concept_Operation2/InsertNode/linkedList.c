#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL; // �������� head NULL �ʱ�ȭ

void insert(Node*);
void showLinkedList();

int main() {

	char buffer;
	char cmd;
	char* data = NULL;
	Node* temp;

	printf("���Ḯ��Ʈ ���ο� ��� �����ϱ� \n");
	
	while (1) {
		
		printf("Input data( i : insert, s : showData , q : quit) : ");
		scanf("%c", &cmd);

		if (cmd=='q') {
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		else if(cmd == 'i') {
			// ���ο� ��� ����
		
			temp = (Node*)malloc(sizeof(Node)); // ��� �����Ҵ�
			printf("�߰��� �����͸� �Է��ϼ��� : ");
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
			printf("�߸��� �Է��Դϴ�.\n");
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