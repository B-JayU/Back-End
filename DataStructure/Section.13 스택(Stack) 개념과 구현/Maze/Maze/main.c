//
//  main.c
//  Maze
//
//  Created by 조팝개발자by_ju on 2021/05/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "pos.h"

#define MAZE_SIZE 10

position start;
position end;
int** maze = NULL;

void read_maze(FILE*);
void find_maze(int**);
void print_maze(int**);
void process(int**);
int movable(position pos, int dir);

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    
    fp = fopen("maze.txt", "r");
    if (fp == NULL){
        printf("FIle not found\n");
        return 1;
    }
    
    read_maze(fp);
    
    process(maze);
    
    //print_maze(maze);
    
    return 0;
}

void process(int** maze){
    
    // 시작점에서 시작하기
    position current = start;
    
    // 길 탐색하기
    while(1){
     
        maze[current.x][current.y] = 2;
        // 현재 위치가 도착지점인가
        if (current.x == end.x && current.y == end.y){
            print_maze(maze);
            printf("Found the path.\n");
            break;
        }
        
        // 이동할 수 있는 길이면... 스택에 넣고 현재 위치 renew
        int flag = 0;
        for (int dir = 0; dir < 4; dir++){
            if (movable(current, dir) == 1) {
                push(current);
                if (dir == 0){
                    current.x--;
                }else if(dir == 1) {
                    current.y++;
                }else if(dir == 2) {
                    current.x++;
                }else if(dir == 3){
                    current.y--;
                }
                flag = 1;
                break;
            }
        }
        
        // 이동할 수 있는 길이 없으면... 현재위치는 pop()한 position으로 갱신
        if (flag != 1){
            maze[current.x][current.y] = 3; // 되돌아 나오는 길
            current = pop();
        }
    }
}

int movable(position pos, int dir){
    if (dir == 0){
        pos.x--;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 1) {
        pos.y++;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 2) {
        pos.x++;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 3){
        pos.y--;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }
    return 0;
}


void read_maze(FILE* fp){
    
    fscanf(fp, "%d %d", &start.x, &start.y);
    fscanf(fp, "%d %d", &end.x, &end.y);
    
    maze = (int**)malloc(sizeof(int*) * MAZE_SIZE);
    
    for (int i = 0; i< MAZE_SIZE; i++) {
        maze[i] = (int*)malloc(sizeof(int) * MAZE_SIZE);
        for (int j = 0; j < MAZE_SIZE; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
}

void print_maze(){
    
    for (int i = start.x; i <= end.x; i++) {
        for (int j = start.y; j <= end.y; j++) {
            //printf("%d ", m[i][j]);
            if (maze[i][j] == 1)
                printf("⬛️ ");
            else if(maze[i][j] == 2)
                printf("🟩 ");
            else if(maze[i][j] == 3)
                printf("🟨 ");
            else if(maze[i][j] == 0)
                printf("⬜️ ");
        }
        printf("\n");
    }
}





