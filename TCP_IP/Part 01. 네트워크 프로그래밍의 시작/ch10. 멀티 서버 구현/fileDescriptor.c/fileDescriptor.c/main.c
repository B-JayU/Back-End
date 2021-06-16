//
//  main.c
//  fileDescriptor.c
//
//  Created by 조팝개발자by_ju on 2021/06/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

void errorHandling(char *message);

int main(int argc, const char * argv[]) {
    
    int sock;
    pid_t pid;
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    pid = fork();
    
    if (pid==0){
        printf("Child Process's file descriptor : %d\n", sock);
    }else{
        printf("Parent Process's file descriptor : %d\n", sock);
    }
    
    close(sock);
    return 0;
}

void errorHandling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

