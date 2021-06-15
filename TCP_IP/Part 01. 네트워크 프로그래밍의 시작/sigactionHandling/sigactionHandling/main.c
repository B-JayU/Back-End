//
//  main.c
//  sigactionHandling
//
//  Created by 조팝개발자by_ju on 2021/06/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>

void keycontrol(int sig) {
    
    static char buf[30];
    if (sig==SIGINT){
        printf("Want exit? : ");
        fgets(buf, sizeof(buf), stdin);
        if (!strcmp(buf, "y\n")||!strcmp(buf, "Y\n")){
            exit(EXIT_SUCCESS);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i;
    signal(SIGINT, keycontrol);
    
    for (i = 0; i < 100; i++) {
        puts("String...");
        sleep(1);
    }
    return 0;
}
