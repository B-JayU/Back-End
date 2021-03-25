#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL; // �������� head NULL �ʱ�ȭ
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

	printf("���Ḯ��Ʈ ���ο� ��� ����/�����ϱ� \n");

	while (1) {

		printf("-------- insert : ���� , delete : ���� , show : Ȯ�� , quit : ���� --------\n");
		printf("Ű���带 �Է��ϼ��� : ");
		
		scanf("%s", cmd);

		if (!strcmp(cmd, "quit")) {
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		else if (!strcmp(cmd, "insert")) {
			// ���ο� ��� ����

			temp = (Node*)malloc(sizeof(Node)); // ��� �����Ҵ�
			printf("�߰��� ������ �����͸� �Է��ϼ��� : ");
			scanf("%d", &data);
			//scanf("%s", buffer);
			temp->data = data;
			temp->next = NULL;

			insert_after(temp);
		}
		else if (!strcmp(cmd, "delete")) {
			printf("������ ������ �����͸� �Է��ϼ��� : ");
			scanf("%d", &data);
			remove_data(data);
		}
		else if (!strcmp(cmd, "show")) {
			showLinkedList(head);
		}
		else {
			printf("�߸��� �Է��Դϴ�.\n");
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
			if (pre == NULL) { // �� �� ��� ����
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