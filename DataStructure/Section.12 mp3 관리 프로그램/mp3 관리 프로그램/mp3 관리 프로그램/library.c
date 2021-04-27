//
//  library.c
//  mp3 관리 프로그램
//
//  Created by byju_yu on 2021/04/12.
//

#include "library.h"
#include "string_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CHARS 256
#define BUFFER_LENGTH 200
Artist *artist_directory[NUM_CHARS];
int num_index = 0;

void initialize(void){
    
    // 가수들을 동일한 이니셜 단위로 묶어서 연결리스트를 구성함.
    for (int i = 0; i < NUM_CHARS; i++)
        artist_directory[i] = NULL;
}

void load(FILE *fp){
    
    char buffer[BUFFER_LENGTH];
    char *name, *title, *path;
    
    while(1) {
        printf("$ ");
        
        if (read_line(stdin, buffer, BUFFER_LENGTH) <= 0)
            break;
        
        name = strtok(buffer, "#");
        if (!strcmp(name, " "))
            name = NULL;
        else
            name = strdup(name);
        
        title = strtok(NULL, "#");
        if (!strcmp(name, " "))
            title = NULL;
        else
            title = strdup(title);
        
        path = strtok(NULL, "#");
        if (!strcmp(name, " "))
            path = NULL;
        else
            path = strdup(name);
    
        printf("%s %s %s\n", name, title, path);
    }
}

Artist* find_artist(char* name){
    
    // 가수 이름의 이니셜을 파악하기
    Artist *p = artist_directory[(unsigned)name[0]];
    // first_artist at with initial name[0]
    
    if (p == NULL)
        return NULL;
    
    while (strcmp(p->name,name) < 0){ // 
        p=p->next;
    }
    
    return p;
}

Artist *create_artist_instance(char *name){
    
    // 아티스트 노드 생성하기
    Artist *ptr_artist = (Artist *)malloc(sizeof(Artist));
    ptr_artist->name = name;
    ptr_artist->head  = NULL;
    ptr_artist->tail = NULL;
    ptr_artist->next = NULL;
    
    return ptr_artist;
}

Artist *add_artist(char *name){
    
    // 새로운 아티스트 노드를 생성하고
    Artist * ptr_artist = create_artist_instance(name);
    
    // 아티스트 이름 이니셜을 이용하여 연결리스트에 삽입하기
    Artist *p = artist_directory[(unsigned)name[0]];
    Artist *q = NULL;
    
    while(p!=NULL && strcmp(p->name, name) < 0) {
        q = p;
        p = p->next;
    }
    
    if (p==NULL & q ==NULL) { // 아티스트 디렉토리 인덱스에 유일한 노드 인 경우
        artist_directory[(unsigned)name[0]]=ptr_artist;
    }else if (q == NULL){ // 해당 인덱스 첫번째 노드로 추가하는 경우
        ptr_artist->next = p;
        artist_directory[(unsigned)name[0]]=ptr_artist;
    }else{ // 일반적인 추가인 경우 (q->ptr_artist->p)
        ptr_artist->next = p;
        q->next= ptr_artist;
    }

    return ptr_artist;
}

Song *create_song_instance(Artist *ptr_artist, char *title, char *path){
    
    Song *ptr_song = (Song *)malloc(sizeof(Song));
    ptr_song->artist = ptr_artist;
    ptr_song->title = title;
    ptr_song->path = path;
    ptr_song->index = num_index;
    num_index++;
    return ptr_song;
}

void insert_node(Artist *ptr_artist, SNode *ptr_snode){
    
    SNode *p = ptr_artist->head;
    while(p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0)
        p = p->next;
    
    // add ptr_snode before p ( 이중연결리스트 )
    
    // 1. empty인 경우
    if (ptr_artist->head == NULL) {
        ptr_artist->head = ptr_snode;
        ptr_artist->tail = ptr_snode;
        
    }
    // 2. empty가 아니지만, 맨 앞에 인 경우
    else if(p == ptr_artist->head) {
        ptr_snode->next = p;
        //ptr_snode->prev = p->prev;
        p->prev = ptr_snode;
        ptr_artist->head = ptr_snode;
    }
    // 3. 마지막에 추가되는 경우
    else if(p == NULL){
        ptr_artist->tail->next = ptr_snode;
        ptr_snode->prev = ptr_artist->tail;
        ptr_artist->tail = ptr_snode;
    }
    // 4. 중간에 삽입되는 경우 (가장 일반적인 경우)
    else{
        ptr_snode->next = p->prev->next; // prev->next... 다시 원점
        ptr_snode->prev = p->prev;
        p->prev->next = ptr_snode;
        p->prev = ptr_snode;
    }
}

void add_song(char *artist, char *title, char *path){
    
    // find if the artist already exists
    // return NULL if not
    Artist *ptr_artist = find_artist(artist);
    
    if (ptr_artist == NULL){ // artist not exist
        ptr_artist = add_artist(artist);
    }
    
    // ptr_artist가 가리키고 있는 아티스트에게 노래를 추가
    Song *ptr_song = create_song_instance(ptr_artist, title, path);
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL;
    
    //insert node
    insert_node(ptr_artist, ptr_snode);
}
void print_song(Song *ptr_song){
    printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
}

void print_artist(Artist *p) {
    printf("%s\n", p->name);
    SNode *ps = p->head;
    while(ps != NULL){
        print_song(ps->song);
        ps = ps->next;
    }
}

void status(void){
    for (int i = 0; i < NUM_CHARS; i++){
        Artist *p = artist_directory[i];
        while(p != NULL) {
            print_artist(p);
            p=p->next;
        }
    }
}


void find_song(){
    
}

int remove_song(){
    
    return 0;
}
