//
//  main.c
//  mp3 관리 프로그램
//
//  Created by byju_yu on 2021/04/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "string_tools.h"

#define BUFFER_SIZE 200
// 함수 선언부
void process_command(void);
void handle_add(void);
void handle_status(void);
void handle_load(void);
void load(FILE *fp);

int main(int argc, const char * argv[]) {
    
    // strtok, 없는내용은 공백문자로, 구분자 #을 이용할것
    // artist_directory 에 sNode들을 연결해서 길게 연장해서 뻗어나가기
    // artist 단방향 연결리스트
    
    initialize();
    handle_load();
    process_command();
    
    return 0;
}

// 함수 정의부
void handle_load(){
    
    char fname_line[BUFFER_SIZE];
    
    printf("Data file name? ");
    if (read_line(stdin,fname_line, BUFFER_SIZE) <= 0)
        return; // get a line
    
    FILE *fp = fopen(fname_line, "r");
    if (fp == NULL){
        printf("No such file exists.\n");
        return;
    }
    
    load(fp);
    fclose(fp);
}

void process_command(void)
{
    char command_line[BUFFER_SIZE];
    char *command;
    
    while(1) {
        printf("$ "); // prompt
        
        if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
            continue; // get a line
        
        command = strtok(command_line, " ");
        if (strcmp(command, "add") == 0)
            handle_add();
        
//        else if(strcmp(command, "search") == 0)
//            handle_search();
//        else if(strcmp(command, "remove") == 0)
//            handle_remove();
          else if(strcmp(command, "status") == 0)
                handle_status();
//        else if(strcmp(command, "play") == 0)
//            handle_play();
//        else if(strcmp(command, "save") == 0)
//            handle_save();
        else if (strcmp(command, "exit") == 0)
            break;
    }
}

void handle_add(void) {
    
    char buffer[BUFFER_SIZE];
    char *artist = NULL, *title= NULL,  *path = NULL;
    
    printf("    Artist : ");
    if(read_line(stdin, buffer, BUFFER_SIZE) > 0)
        artist = strdup(buffer);
    
    printf("    title : ");
    if (read_line(stdin, buffer, BUFFER_SIZE) > 0)
        title = strdup(buffer);
    
    printf("    path : ");
    if (read_line(stdin, buffer, BUFFER_SIZE) > 0)
        path = strdup(buffer);
    
    printf("%s %s %s\n", artist, title, path);

    //    add to the music library
    
    add_song(artist, title, path);
    
}

void handle_status(void){
    status();
}
