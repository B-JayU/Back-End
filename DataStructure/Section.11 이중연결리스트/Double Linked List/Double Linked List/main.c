#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 단방항 연결리스트는 어떤 노드의 앞에 새로운 노드를 삽입하기 어려웠다.
 삭제할 경우에, 항상 삭제할 노드의 앞 노드가 필요하다. 단방향의 순회만 가능했다.
 이중 연결 리스트는 각각의 노드가 다음 노드와 이전 노드의 주소를 가지는 연결 리스트 이므로
 양방향의 순회가 가능하다.
 */

/* 구현 기능 : 검색(search), 삽입(insert), 제거(remove), 순회(traverse) */

/* head: 첫번째 노드, tail : 마지막 노드
 next : 다음 노드, prev : 이전 노드*/

typedef struct Node {
    char data[20];
    struct Node* next;
    struct Node* prev;
} node;

node *head;
node *tail;
int size = 0; // 이중 연결 리스트 내 노드의 개수

void insert_init(char* data);
void insert_before(node* p, char* data);
void insert_after(node* pre, char* item);
node* head_traverse(void);
node* tail_traverse(void);
node* search(char* data);
void delete(char* data);

int main(int argc, const char * argv[]) {
   
    FILE *fp;
    char name[20];
    node* temp;
    
    fp = fopen("input.txt", "r");
    
    if (fp == NULL){
        fprintf(stdout, "파일열기 실패");
    }
    
    head = NULL;
    tail = NULL;
    
    // 이중 연결 리스트 초기 설정하기
    while(feof(fp) == 0){ //
        fscanf(fp, "%s", name);
        insert_init(name);
    }
    
    printf("연결리스트 생성\n");
    head_traverse();
    tail_traverse();
    printf("\n");
    
    printf("중간에 삽입하기\n");
    temp = search("clara");
    insert_before(temp, "Dick");
    
    head_traverse();
    tail_traverse();
    printf("\n");
    
    // 삭제하기
    delete("sharon");
    
    head_traverse();
    tail_traverse();
    return 0;
}

void insert_init(char* item){
    node* new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->data,item);
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if (head == NULL){ // 연결 리스트에 아무 노드도 없을 때
        head = new_node;
        tail = new_node;
    }else { // 초기 새롭게 추가하는 노드는 항상 연결리스트에 마지막에 연결한다는 가정하에
        new_node->next = NULL;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void insert_before(node* p, char* item){
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->data, item);
    
    // p가 가리키는 노드 앞에 새로운 노드를 삽입하는 경우
    new_node->next = p;
    new_node->prev = p->prev;
    p->prev->next = new_node;
    p->prev = new_node;
}

void insert_after(node* pre, char* item) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->data, item);
    new_node->prev = NULL;
    new_node->next = NULL;
    
    if (pre == NULL && head == NULL) {
        head = new_node;
        tail = new_node;
    }else if (pre==NULL) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }else if (pre == tail) {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }else {
        new_node->prev = pre;
        new_node->next = pre->next;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    
}

void delete(char* data){
    
    node* temp;
    temp = head;
    while(temp){
        if (strcmp(temp->data, data) == 0){
            
            // 1. p가 유일한 노드인 경우
            if (head==temp && tail==temp && temp!=NULL){
                free(temp);
            }
            // 2. p가 head node 인 경우
            else if (temp == head){
                head->next->prev = NULL;
                head = head->next;
                free(temp);
            }
            // 3. p가 tail 인 경우
            else if (temp == tail) {
                tail->prev->next = NULL;
                tail = tail->prev;
                free(temp);
            }
            // 4. 그 밖의 일반적인 경우
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                printf("%s 삭제되었습니다.\n", temp->data);
                free(temp);
            }
            return;
        }
        temp=temp->next;
    }
    printf("삭제하고자 하는 데이터가 존재하지 않습니다.\n");
    return;
    
}
node* search(char *data){
    
    node* temp;
    temp=head;
    
    while(temp){
        if (strcmp(temp->data, data) == 0){
            return temp;
        }
        temp=temp->next;
    }
    return temp;
}

node* head_traverse(void){
    node* temp;
    
    temp = head;
    printf("head 순회 : ");
    while(temp){
        printf("%s ", temp->data);
        temp=temp->next;
    }
    
    printf("\n");
    return temp;
}

node* tail_traverse(void){
    node* temp;
    
    temp=tail;
    printf("tail 순회 : ");
    while(temp) {
        printf("%s ", temp->data);
        temp=temp->prev;
    }
    
    printf("\n");
    return temp;
}
