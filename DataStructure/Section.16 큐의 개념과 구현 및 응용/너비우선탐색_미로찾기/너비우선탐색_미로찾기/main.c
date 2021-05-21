//
//  main.c
//  너비우선탐색_미로찾기
//
//  Created by 조팝개발자by_ju on 2021/05/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueADT.h"

#define MAZE_SIZE 7
//Item** maze;

typedef struct point {
    int x;
    int y;
}position;

position move_to(position p, int dir);
int movable(int maze[][MAZE_SIZE], position cur, int dir);
int movable2(int maze[][MAZE_SIZE], position cur, int dir);
void print_maze(int maze[][MAZE_SIZE]);

int main(int argc, const char * argv[]) {
   
    Queue queue = create();
    Queue queue2 = create();
    int maze[MAZE_SIZE][MAZE_SIZE];
    position cur;
    
    FILE *fp = fopen("maze.txt", "r");
    if (fp == NULL)
        terminate("Error in fopen().\n");
    
    for(int i = 0; i < MAZE_SIZE; i++) {
        for (int j  = 0; j < MAZE_SIZE; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    
    cur.x = 0;
    cur.y = 0;
    
    enqueue(queue, cur);
    maze[0][0] = -1;
    int found = 0;
    
    while(!is_empty(queue)) {
        cur = dequeue(queue);
        for (int dir = 0; dir < 4; dir++){
            if (movable(maze, cur, dir)) {
                position p = move_to(cur, dir);
                
                maze[p.x][p.y] = maze[cur.x][cur.y] -1;
                if (p.x == MAZE_SIZE-1 && p.y==MAZE_SIZE-1) {
                    printf("Found the path.\n");
                    found = 1;
                    break;
                }
                enqueue(queue, p);
            }
        }
        if (found == 1)
            break;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cur.x = MAZE_SIZE -1;
    cur.y = MAZE_SIZE -1;
    
    enqueue(queue, cur);
    enqueue(queue2, cur);
    //maze[0][0] = -1;
    found = 0;
    
    while(!is_empty(queue)) {
        cur = dequeue(queue);
        for (int dir = 0; dir < 4; dir++){
            if (movable2(maze, cur, dir)) {
                position p = move_to(cur, dir);
                
                //maze[p.x][p.y] = maze[cur.x][cur.y] -1;
                if (p.x == 0 && p.y== 0) {
                    enqueue(queue2, p);
                    found = 1;
                    break;
                }
                enqueue(queue, p);
                enqueue(queue2, p);
            }
        }
        if (found == 1)
            break;
    }
    
    while(!is_empty(queue2)){
        cur = dequeue(queue2);
        maze[cur.x][cur.y] = 2;
    }

    print_maze(maze);
    return 0;
}

//position move_to(position c, int d) {
//
//
//}

int movable(int maze[][MAZE_SIZE], position pos, int dir){
    
    
    if (dir == 0){
        if (pos.x == 0)
            return 0;
        pos.x--;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 1) {
        if (pos.y == MAZE_SIZE -1)
            return 0;
        pos.y++;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 2) {
        if (pos.x == MAZE_SIZE -1)
            return 0;
        pos.x++;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }else if(dir == 3){
        if (pos.y == 0)
            return 0;
        pos.y--;
        if (maze[pos.x][pos.y] == 0)
            return 1;
    }
    return 0;
}

int movable2(int maze[][MAZE_SIZE], position pos, int dir){
    
    int tmp_x, tmp_y;
    
    if (dir == 0){
        if (pos.x == 0)
            return 0;
        tmp_y = pos.y;
        tmp_x = pos.x-1;
        if (maze[tmp_x][tmp_y] < 0){
            if (maze[tmp_x][tmp_y] == maze[pos.x][pos.y] + 1)
                return 1;
            else
                return 0;
        }
        
        
    }else if(dir == 1) {
        if (pos.y == MAZE_SIZE -1)
            return 0;
       
        tmp_y = pos.y+1;
        tmp_x = pos.x;
        if (maze[tmp_x][tmp_y] < 0){
            if (maze[tmp_x][tmp_y] == maze[pos.x][pos.y] + 1)
                return 1;
            else
                return 0;
        }
        
        
    
    
    }else if(dir == 2) {
        if (pos.x == MAZE_SIZE -1)
            return 0;
        
        tmp_y = pos.y;
        tmp_x = pos.x+1;
        if (maze[tmp_x][tmp_y] < 0){
            if (maze[tmp_x][tmp_y] == maze[pos.x][pos.y] + 1)
                return 1;
            else
                return 0;
        }
    
    
    }else if(dir == 3){
        if (pos.y == 0)
            return 0;
        tmp_y = pos.y-1;
        tmp_x = pos.x;
        if (maze[tmp_x][tmp_y] < 0){
            if (maze[tmp_x][tmp_y] == maze[pos.x][pos.y] + 1)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

position move_to(position p, int dir){
    
    position tmp;
    if (dir == 0){
        tmp.x = p.x-1;
        tmp.y = p.y;
    }else if (dir == 1) {
        tmp.x = p.x;
        tmp.y = p.y+1;
    }else if (dir == 2) {
        tmp.x = p.x+1;
        tmp.y = p.y;
    }else {
        tmp.x = p.x;
        tmp.y = p.y-1;
    }
    
    return tmp;
} 

void print_maze(int maze[][MAZE_SIZE]){
    
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            //printf("%d ", m[i][j]);
            if (maze[i][j] == 1)
                printf("⬛️ ");
            else if(maze[i][j] == 0)
                printf("⬜️ ");
            else if(maze[i][j] == 2)
                printf("🟨 ");
            else if (maze[i][j] < 0)
                printf("🟩 ");
        }
        printf("\n");
    }
}
