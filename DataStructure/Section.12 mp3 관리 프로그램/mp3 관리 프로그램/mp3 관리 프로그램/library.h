//
//  library.h
//  mp3 관리 프로그램
//
//  다른 소스 파일과 공유할 매크로와 타입정의를 헤더파일에 넣는다.
//  공유 변수의 선언은 헤더 파일에 둔다.
//  공유 변수를 사용하는 모든 소스 파일은 헤더 파일을 include한다.
//  소스 파일 중 오직 한 곳에서 공유 변수를 정의한다. (타입 정의(구조체 정의)가 중복되는 것은 컴파일 오류를 야기한다.)
//  매크로 정이, 함수 프로토타입, 그리고 외부(extern) 변수의 선언은 여러 번 중복되어도 상관 없다.
//
//  Created by byju_yu on 2021/04/12.
//

#ifndef library_h
#define library_h

#include <stdio.h>
#define MAX 100

typedef struct song Song;
typedef struct sNode SNode;
typedef struct artist Artist;


typedef struct song{
    Artist *artist;
    char *title;
    char *path;
    int index;
}Song;

struct sNode {
    struct sNode *next;
    struct sNode *prev;
    struct song *song;
};

struct artist {
    char *name;
    struct artist *next;
    struct sNode *head;
    struct sNode *tail;
};


void initialize(void);
Artist *create_artist_instance(char *name);
Artist* add_artist(char *artist);
Artist* find_artist(char *artist);
Song *create_song_instance(Artist *ptr_artist, char *title, char *path);
void add_song(char *artist, char *title, char *path);
void find_song(void);
int remove_song(void);
void status(void);
void print_artist(Artist *p);
void print_song(Song *ptr_song);

void load(FILE *fp);



#endif /* library_h */
