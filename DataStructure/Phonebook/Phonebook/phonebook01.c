#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
	char name[10];
	char numbers[15];
};
struct contact p[100];

int pCount = 0;

#define BUFFER_SIZE 100

void add();
void find();
void removeE();
void status();
void errorHandling();

int main() {

	char command[BUFFER_SIZE]; 
	printf("Start Phonebook program\n");
	
	while (1) {
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "add") == 0) {
			add();
		}
		else if (strcmp(command, "find") == 0) {
			find();
		}
		else if (strcmp(command, "status") == 0) {
			status();
		}
		else if (strcmp(command, "delete") == 0) {
			removeE();
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else
			errorHandling();
	}

	return 0;
}

void add() {
	scanf("%s %s", p[pCount].name, p[pCount].numbers);
	printf("%s was added successfully.\n", p[pCount].name);
	pCount++;
}

void find() {
	
	char fName[20];
	scanf("%s", fName);

	for (int i = 0; i < pCount; i++) {
		if (strcmp(fName, p[i].name) == 0) {
			printf("%s\n", p[i].numbers);
			return;
		}
	}

	printf("No person names '%s' exists.\n", fName);
	return;
}

void removeE() {
	
	char fName[20];
	scanf("%s", fName);

	for (int i = 0; i < pCount; i++) {
		if (strcmp(fName, p[i].name) == 0) {
			printf("%s was deleted successfully\n", p[i].name);
			p[i] = p[pCount - 1];
			pCount--;
			return;
		}
	}

	printf("No person names '%s' exists.\n", fName);
}

void status() {
	
	for (int i = 0; i < pCount; i++) {
		printf("%s %s\n", p[i].name, p[i].numbers);
	}

	if (pCount <= 1)
		printf("Total %d person.\n", pCount);
	else
		printf("Total %d persons.\n", pCount);

}

void errorHandling() {

	printf("Input Error!!!\n");
}