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

Polynomial* polys[10]; //polys는 다항식들에 대한 포인트 배열
int n = 0; //저장된 다항식의 개수
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
		strcpy(copied, command_line); // 입력 라인을 복사해둔다.
		command = strtok(command_line, " ");

		if (!strcmp(command, "print")) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]); // 출력하고자 하는 식은 문자 하나로 표현된다.
		}
		else if (!strcmp(command, "calc")) {
			arg1 = strtok(NULL, " "); // 다항식 입력
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

Term* create_term_instance() { // 다항식에 포함되는 각 항을 구성하는 함수
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial* create_polynomial_instance(char name) { // 다항식 개체를 생성(구성)하는 함수
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial* poly) {
	if (c == 0) // 계수가 0이면 항을 추가할 필요가 업음.
		return;
	Term* p = poly->first, *q = NULL;
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e) { // 해당 차수항이 이미 존재하는 경우
		p->coef += c;
		if (p->coef == 0) { // 더한 결과가 0 이면...
			if (q == NULL) { // 현재노드가 첫번째 노드이면..
				poly->first = p->next;
			}
			else {
				q->next = p->next;
			}
			poly->size--;
			free(p); // 불필요해진 노드 p를 free 시키기
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

	if (coef == 0) // 생략되었다... +1 또는 -1인 경우
		coef = sign_coef;
	else
		coef *= sign_coef;

	if (i >= end) { 
		add_term(coef, 0, p_poly); // 상수인 경우
		return 1;
	}

	if (expr[i] != 'x') // x가 아닌 문자로 끝난 경우
		return 0;
	i++;

	if (i >= end) {  // x문자로 바로 끝나는 경우
		add_term(coef, 1, p_poly); // 1차 항이라서 지수가 생략된 형태 그러므로 expo를 1로 매핑
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
		if (polys[i]->name == ptr_poly->name) { // 다항식을 덮어줄 경우에는 기존의 다항식 객체를 free시켜줘야 한다.

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

	// line단위 입력은 fgets, getline 등의 함수들을 이용하여 할 수도 있따.

	int ch;
	int i = 0; // 실제로 읽어들인 문자수 반환용 변수

	while ((ch = getchar()) != '\n') { // 엔터 개행문자
		if (i < limit - 1) // limit -1 인 이유는 str[] 배열 마지막에 null문자를 추가하기 위함.
			str[i++] = ch;
	}

	str[i] = '\0'; // 문자 끝 널 문자 삽입

	return i; // 실제로 읽어들인 문자수를 반환한다.
}