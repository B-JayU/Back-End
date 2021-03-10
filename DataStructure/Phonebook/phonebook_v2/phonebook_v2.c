#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void file_open();
void add();
void find();
void removeE();
void status();
void save();
void errorHandling();

struct contact {
	char name[10];
	char numbers[15];
};
struct contact p[100];
int pCount = 0;


int main() {
	
	char command[BUFFER_SIZE];
	printf("Start Phonebook program v2\n");
	
	while(1) {
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "read") == 0) {
			file_open();
		}
		else if (strcmp(command, "add") == 0) {
			add();
		}
		else if (strcmp(command, "find") == 0) {
			find();
		}
		else if (strcmp(command, "delete")==0) {
			removeE();
		}
		else if (strcmp(command, "status")==0) {
			status();
		}
		else if (strcmp(command, "save")==0) {
			save();
		}
		else if (strcmp(command, "exit")==0) {
			break;
		}
	}
	return 0;
}

void file_open() {

	FILE* fp;
	char fName[20];

	scanf("%s", fName);
	fp = fopen(fName, "r+");

	while (!feof(fp)) {
		fscanf(fp, "%s %s", p[pCount].name, p[pCount].numbers);
		pCount++;
	}

	fclose(fp);
}

void add() {
	
	char name[15];
	char numbers[15];
	struct contact newC;

	scanf("%s", newC.name);
	scanf("%s", newC.numbers);
	

	int i = pCount - 1;
	while (i >= 0 && strcmp(p[i].name, newC.name) > 0) {
		p[i + 1] = p[i];
		i--;
	}
	p[i + 1] = newC;

	printf("%s was added successfully.\n", p[i+1].name);
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
			
			for (int j = i + 1; j < pCount; j++) {
				p[j - 1] = p[j];
			}
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

void save() {

	char buffer[BUFFER_SIZE];
	char fName[20];

	FILE *fp2;
	scanf("%s %s", buffer, fName);

	fp2 = fopen(fName, "w+");
	
	for (int i = 0; i < pCount; i++) {
		fprintf(fp2, "%s %s\n", p[i].name, p[i].numbers);
	}

	fclose(fp2);

}