//
//  main.c
//  Process Communication
//
//  Created by 조팝개발자by_ju on 2021/06/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUF_SIZE 50
int main(int argc, const char * argv[]) {
   
    int fds1[2], fds2[2];
    char buf[BUF_SIZE];
    char str1[] = "Hello";
    char str2[] = "Good afternoon";
    char str3[] = "Good Day";
    char *str_ary[] = {str1, str2, str3};
    
    pid_t pid;
    
    pipe(fds1), pipe(fds2);
    pid = fork();
    if (pid==0)
    {
        for (int i = 0; i < 3; i++){
            write(fds1[1], str_ary[i],strlen(str_ary[i])+1);
            read(fds2[0], buf, BUF_SIZE);
            printf("Child proc output : %s\n", buf);
        }
    }
    else{
        for (int i = 0; i < 3; i++){
            write(fds2[1], str_ary[i],strlen(str_ary[i])+1);
            read(fds1[0], buf, BUF_SIZE);
            printf("Parent proc output : %s\n", buf);
        }
    }
    return 0;
}
