#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct term {
	int coef;
	int expo;
	struct term* next;
};
typedef struct term Term;

typedef struct polynomial {
	char name;
	Term* first;
	int size;
}Polynomial;

Polynomial* polys[10]; //polys�� ���׽ĵ鿡 ���� ����Ʈ �迭
int n = 0; //����� ���׽��� ����
Term* create_term_instance();
Polynomial* create_polynomial_instance(char name);
void add_term(int c, int e, Polynomial* poly);
int eval(Polynomial* poly, int x);
void print_poly(Polynomial* p);
void handle_print(char);
void handle_calc(char,char *);
void handle_definition(char*);
Polynomial* create_by_parse_polynomial(char name, char* body);
Term* parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly);
void insert_polynomial(Polynomial* ptr_poly);
void destroy_polynomial(Polynomial* ptr_poly);
void erase_blanks(char*);

int main() {

	char command_line[100];
	char copied[100];
	char *command, *arg1, *arg2;
	int ar2;

	while (1) {
		printf("%s ");
		if (read_line(stdin, command_line, 100, 0) <= 0)
			continue;
		strcpy(copied, command_line); // �Է� ������ �����صд�.
		command = strtok(command_line, " ");

		if (!strcmp(command, "print")) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]); // ����ϰ��� �ϴ� ���� ���� �ϳ��� ǥ���ȴ�.
		}
		else if (!strcmp(command, "calc")) {
			arg1 = strtok(NULL, " "); // ���׽� �Է�
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			ar2 = atoi(arg2);
			handle_calc(arg1[0], ar2);
		}
		else if (!strcmp(command, "exit"))
			break;
		else {
			handle_definition(copied);
		}
	}
	return 0;
}

Term* create_term_instance() { // ���׽Ŀ� ���ԵǴ� �� ���� �����ϴ� �Լ�
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial* create_polynomial_instance(char name) { // ���׽� ��ü�� ����(����)�ϴ� �Լ�
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial* poly) {
	if (c == 0) // ����� 0�̸� ���� �߰��� �ʿ䰡 ����.
		return;
	Term* p = poly->first, *q = NULL;
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e) { // �ش� �������� �̹� �����ϴ� ���
		p->coef += c;
		if (p->coef == 0) { // ���� ����� 0 �̸�...
			if (q == NULL) { // �����尡 ù��° ����̸�..
				poly->first = p->next;
			}
			else {
				q->next = p->next;
			}
			poly->size--;
			free(p); // ���ʿ����� ��� p�� free ��Ű��
		}
		return;
	}
	
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	if (q == NULL) {
		term->next = poly->first;
		poly->first = term;
	}
	else {
		term->next = q->next;
		q->next = term;
	}
	poly->size++;

	return;
}

int eval(Polynomial* poly, int x) {
	int result = 0;
	Term* t = poly->first;
	while (t) {
		result += t->coef * pow(x, t->expo);
		t = t->next;
	}
	return result;
}

void print_poly(Polynomial* p)
{
	printf("%c=", p->name);
	Term* t = p->first;
	while(t) {
		if (t->next) {
			printf("%dx^%d + ", t->coef, t->expo);
		}
		else {
			printf("%dx^%d", t->coef, t->expo);
		}
		t = t->next;
	}
}

void handle_print(char c) {

	int i = 0;
	Term* t;
	while (i < n && polys[i]->name != c) i++;

	if (i == n) {
		printf("Invalid arguments\n");
		return;
	}

	t = polys[i]->first;
	while (t) {
		if (t->next)
			printf("%dx^%d + ", t->coef, t->expo);
		else
			printf("%dx^%d", t->coef, t->expo);
		t = t->next;
	}

}

void handle_calc(char c, char *arg) {
	
	int i = 0;
	
	while (i < n && polys[i]->name != c) i++;

	if (i == n) {
		printf("Invalid arguments\n");
		return;
	}

	printf("%d\n", eval(polys[i], atoi(arg)));
}

void handle_definition(char* exp) {

	erase_blanks(exp);

	char* f_name = strtok(exp, "=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("Unsupported command.");
		return;
	}

	char* exp_body = strtok(NULL , "=");
	if (exp_body == NULL || strlen(exp_body) <= 0) {
		printf("Invalid expression format.--");
		return;
	}

	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
		char* former = strtok(exp_body, "+");
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression format.");
			return;
		}
		char* later = strtok(NULL, "+");
		if (later = NULL || strlen(later) != 1) {
			printf("Invalid expresion format.");
			return;
		}
		Polynomial* pol = create_by_parse_polynomial(f_name[0], former[0], later[0]);

		if (pol == NULL) {
			printf("Invalid expression format.");
			return;
		}
		insert_polynomial(pol);
	}
	else {
		Polynomial* pol = create_by_parse_polynomial(f_name[0], exp_body);
		if (pol == NULL) {
			printf("Invalud expression format.");
			return;
		}
		insert_polynomial(pol);
	}
	return;
}

void erase_blanks(char* exp) {

	char* str;
	char* temp="";
	str = strtok(exp, " ");
	while (str) {
		strcat(temp, str);
		str = strtok(NULL, " ");
	}

	exp = temp;
}

Polynomial* create_by_parse_polynomial(char name, char* body)
{
	Polynomial* ptr_poly = create_polynomial_instance(name);

	int i = 0, begin_term = 0;
	while (i < strlen(body)) {
		if (body[i] == '+' || body[i] == '-')
			i++;
		while (i < strlen(body) && body[i] != '+' && body[i] != '-')
			i++;

		int result = parse_and_add_term(body, begin_term, i, ptr_poly);

		if (result == 0) {
			destroy_polynomial(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

Term* parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly)
{
	int i = begin;
	int sign_coef = 1, coef = 0, expo = 1;

	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-') {
		sign_coef = -1;
		i++;
	}

	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}

	if (coef == 0) // �����Ǿ���... +1 �Ǵ� -1�� ���
		coef = sign_coef;
	else
		coef *= sign_coef;

	if (i >= end) { 
		add_term(coef, 0, p_poly); // ����� ���
		return 1;
	}

	if (expr[i] != 'x') // x�� �ƴ� ���ڷ� ���� ���
		return 0;
	i++;

	if (i >= end) {  // x���ڷ� �ٷ� ������ ���
		add_term(coef, 1, p_poly); // 1�� ���̶� ������ ������ ���� �׷��Ƿ� expo�� 1�� ����
		return 1;
	}

	if (expr[i] != '^')
		return 0;
	i++;

	expo = 0;
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		expo = expo * 10 + (int)(expr[i] - '0');
		i++;
	}

	add_term(coef, expo, p_poly);
	return 1;
}

void insert_polynomial(Polynomial* ptr_poly) {
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == ptr_poly->name) { // ���׽��� ������ ��쿡�� ������ ���׽� ��ü�� free������� �Ѵ�.

			destroy_polynomial(polys[i]);

			polys[i] = ptr_poly;
			return;
		}
	}
	polys[n++] = ptr_poly;
}

void destroy_polynomial(Polynomial* ptr_poly) {
	if (ptr_poly == NULL)
		return;
	Term* t = ptr_poly->first, * tmp;
	while (t!= NULL) {
		tmp = t;
		t = t->next;
		free(tmp);
	}
	free(ptr_poly);
}

int read_line(char str[], int limit) {

	// line���� �Է��� fgets, getline ���� �Լ����� �̿��Ͽ� �� ���� �ֵ�.

	int ch;
	int i = 0; // ������ �о���� ���ڼ� ��ȯ�� ����

	while ((ch = getchar()) != '\n') { // ���� ���๮��
		if (i < limit - 1) // limit -1 �� ������ str[] �迭 �������� null���ڸ� �߰��ϱ� ����.
			str[i++] = ch;
	}

	str[i] = '\0'; // ���� �� �� ���� ����

	return i; // ������ �о���� ���ڼ��� ��ȯ�Ѵ�.
}