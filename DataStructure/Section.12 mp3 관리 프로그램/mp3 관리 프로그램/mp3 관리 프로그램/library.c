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
// #include <windows.h>

#define NUM_CHARS 256
#define SIZE_INDEX_TABLE 100
#define BUFFER_LENGTH 200
Artist *artist_directory[NUM_CHARS];
SNode *index_directory[SIZE_INDEX_TABLE];
void insert_to_index_directory(Song *ptr_song);
SNode *find_song_index(int index);
void save_artist(Artist *p, FILE *fp);
void save_song(Song *ptr_song, FILE *fp);
void removeSong(int);
void remove_snode(Artist *ptr_artist, SNode *ptr_snode);
void destroy_song(Song *ptr_song);

int num_index = 0;

void initialize(void){
    
    // 가수들을 동일한 이니셜 단위로 묶어서 연결리스트를 구성함.
    for (int i = 0; i < NUM_CHARS; i++)
        artist_directory[i] = NULL;
    
    for (int i = 0; i < SIZE_INDEX_TABLE; i++)
        index_directory[i] = NULL;
    
}

void load(FILE *fp){
    
    char buffer[BUFFER_LENGTH];
    char *name=NULL , *title=NULL, *path=NULL;
    
    while(1) {
        //printf("$ ");
        
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
            break;
        
        name = strtok(buffer, "#");
//        if (!strcmp(name, " "))
//            name = NULL;
//        else
//            name = strdup(name);
        
        if (name != NULL)
            name = strdup(name);
        else
            name = "\0";
        
        
//        title = strtok(NULL, "#");
//        if (!strcmp(title, " "))
//            title = NULL;
//        else //
//            title = strdup(title);
        
        title = strtok(NULL, "#");
        if (title != NULL)
            title = strdup(title);
        else
            title = "\0";
        
        path = strtok(NULL, "#");
        if (path != NULL)
            path = strdup(path);
        else
            path = "\0";
    
        //printf("%s %s %s\n", name, title, path);
        add_song(name, title, path);
        
    }
}

void search_song(char *artist, char *title){
    
    Artist *ptr_artist = find_artist(artist);
    if (ptr_artist == NULL){
        printf("No such artist exists.\n");
        return;
    }
    
    SNode *ptr_snode = find_snode(ptr_artist, title);
    
    if (ptr_snode != NULL){
        printf("Found:\n");
        print_song(ptr_snode->song);
    }
    else {
        printf("No such song exists.\n");
        return;
    }
}

void search_songA(char *artist){
    
    Artist *ptr_artist = find_artist(artist);
    if (ptr_artist == NULL){
        printf("No such artist exists.\n");
        return;
    }
    
    printf("Found:\n");
    print_artist(ptr_artist);
    
}

SNode *find_snode(Artist *ptr_artist, char *title) {
    
    SNode *ptr_snode = ptr_artist->head;
    while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) < 0)
        ptr_snode = ptr_snode->next;
    
    if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) == 0){
        return ptr_snode;
    }else {
        return NULL;
    }
}

Artist* find_artist(char* name){
    
    // 가수 이름의 이니셜을 파악하기
    Artist *p = artist_directory[(unsigned)name[0]];
    // first_artist at with initial name[0]
    
    if (p == NULL)
        return NULL;
    
    while (p != NULL && strcmp(p->name,name) < 0){ //
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
    ptr_song->index = ++num_index;
    //++num_index;
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
    Artist *temp = NULL;
    
    if (ptr_artist == NULL){ // artist not exist
        ptr_artist = add_artist(artist);
    }
    
    if (strcmp(ptr_artist->name, artist) != 0){
        temp = add_artist(artist);
        ptr_artist = temp;
    }
    
    // ptr_artist가 가리키고 있는 아티스트에게 노래를 추가
    Song *ptr_song = create_song_instance(ptr_artist, title, path);
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL;
    
    //insert node
    insert_node(ptr_artist, ptr_snode);
    insert_to_index_directory(ptr_song);
}

void insert_to_index_directory(Song *ptr_song){
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL; // unused
    
    int index = ptr_song->index % SIZE_INDEX_TABLE;
    
    // add the snode into the single linked list at index_table[index]
    
    SNode *p = index_directory[index];
    SNode *q = NULL;
    while (p!=NULL && strcmp(p->song->title, ptr_song->title) < 0){
        q = p;
        p = p->next;
    }
    if (q == NULL){ // add_first
        ptr_snode->next = p;
        index_directory[index] = ptr_snode;
    }
    else { // add_after q
        ptr_snode->next = p;
        q->next = ptr_snode;
    }
    
}

void print_song(Song *ptr_song){
    
    if (!strcmp(ptr_song->title, ""))
        return;
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

SNode *find_song_index(int index) {
    
    SNode *ptr_snode = index_directory[index%SIZE_INDEX_TABLE];
    while (ptr_snode != NULL && ptr_snode->song->index != index)
        ptr_snode = ptr_snode->next;
    
    return ptr_snode;
}

void play(int index) {
    
    SNode *ptr_snode = find_song_index(index);
    if (ptr_snode == NULL) {
        printf("No such song exist.\n");
    }
    
    printf("%s is now playing.\n", ptr_snode->song->title);
    //ShellExcute(GetDesktopWindow(), "open", ptr_snode->song->path, NULL, NULL, SW_SHOW);
}

void save(FILE *fp){
    
    for (int i = 0; i < NUM_CHARS; i++) {
        Artist *p = artist_directory[i];
        while(p != NULL) {
            save_artist(p, fp);
            p = p->next;
        }
    }
    
    printf("Saved succeeded\n");
}

void save_artist(Artist *p, FILE *fp) {
    //printf("%s\n", p->name);
    SNode *ps = p->head;
    while(ps != NULL){
        save_song(ps->song, fp);
        ps = ps->next;
    }
}

void save_song(Song *ptr_song, FILE *fp) {
    
    if (ptr_song->artist != NULL)
        fprintf(fp, "%s#", ptr_song->artist->name);
    else
        fprintf(fp, " #");
    
    if (ptr_song->title != NULL)
        fprintf(fp, "%s#", ptr_song->title);
    else
        fprintf(fp, " #");
    
    if (ptr_song->path != NULL)
        fprintf(fp, "%s#\n", ptr_song->path);
    else
        fprintf(fp, "#\n");
}

void removeSong(int index) {
    
    SNode *q = NULL;                                            // previous to p
    SNode *p = index_directory[index%SIZE_INDEX_TABLE]; // head node
    while (p != NULL && p->song->index != index){
        q = p;
        p = p->next;
    }
    
    if (p == NULL) { // either empty list or no exist
        printf("No such song exists.\n");
        return;
    }
    
    Song *ptr_song = p->song;
    if (q == NULL) {
        index_directory[index%SIZE_INDEX_TABLE] = p->next;
    }
    else {
        q->next =  p->next;
    }
    
    Artist *ptr_artist = ptr_song->artist;
    
    SNode *ptr_snode = find_snode(ptr_artist, ptr_song->title);
    if (ptr_snode == NULL) {
        printf("No found snode - something wrong.\n");
        return;
    }
    
    remove_snode(ptr_artist, ptr_snode);
    destroy_song(ptr_song);
}

void destroy_song(Song *ptr_song) {
    if (ptr_song ->title != NULL)
        free(ptr_song->title);
    if (ptr_song ->path != NULL)
        free(ptr_song->path);
    free(ptr_song);
}

void remove_snode(Artist *ptr_artist, SNode *ptr_snode) {
 
    SNode *first = ptr_artist->head;
    SNode *last = ptr_artist->tail;
    
    if (first == ptr_snode && last == ptr_snode) { // unique node
        ptr_artist->head = NULL;
        ptr_artist->tail = NULL;
    }
    else if(first == ptr_snode) { // remove first
        first->next->prev = NULL;
        ptr_artist->head = first->next;
        //first = first->next;
    }else if(last == ptr_snode) { // remove last
        last->prev->next = NULL;
        ptr_artist->tail = last->prev;
        //last = last->prev;
    }else{ // in the middle
        ptr_snode->prev->next = ptr_snode->next;
        ptr_snode->next->prev = ptr_snode->prev;
    }
    free(ptr_snode);
}
