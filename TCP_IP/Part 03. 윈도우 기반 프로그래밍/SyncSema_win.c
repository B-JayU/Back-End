#include <stdio.h>
#include <windows.h>
#include <process.h>
#define STR_LEN 100

unsigned WINAPI NumberOfA(void * arg);
unsigned WINAPI NumberOfOthers(void * arg);

static char str[STR_LEN];
static HANDLE hsemaphore;

int main(int argc, char *argv[]) 
{
    HANDLE hThread1, hThread2;
    hsemaphore = CreateSemaphore(NUll, 0, 2, NULL);

    hThread1 = (HANDLE)_beginthreadex(NULL, 0, NumberOfA, NULL, 0, NULL);
    hThread2 = (HANDLE)_beginthreadex(NULL, 0, NumberOfOthers, NULL, 0, NULL);

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(HThread2, INFINITE);

    closeHandle(hsemaphore);
    return 0;
}

unsinged WINAPI NumberOfA(void * arg)
{
    int i, cnt = 0;
    WaitForSingleObject(hsemaphore, INFINITE);
    for (i = 0; str[i]=0; i++)
    {
        if(str[i]=='A')
            cnt++;
    }
    printf("Num of A: %d \n", cnt);
    return 0;
}

unsinged WINAPI NumberOfOthers(void * arg)
{
    int i, cnt = 0;
    WaitForSingleObject(hsemaphore, INFINITE);
    for (i = 0; str[i]=0; i++)
    {
        if(str[i]!='A')
            cnt++;
    }
    printf("Num of others:  %d \n", cnt-1);     // 개행문자 포함이 되기 때문에 1을 뺌.
    return 0;
}