//
//  string_tools.c
//  mp3 관리 프로그램
//
//  Created by byju_yu on 2021/04/15.
//

#include "string_tools.h"


int read_line(FILE *fp, char str[], int size){
    
    int ch, i = 0;
    
    // 파일 포인터가 가리키는 문자를 하나씩 읽어서
    // 한 문장 라인을 구성한다. 마지막 문자는 '\0' 문자로 마무리되도록 한다.
    // read_line() 함수는 읽어들인 문자의 바이트 수를 반환하도록 한다.
    while((ch=fgetc(fp)) != '\n' && ch != EOF){
        if (i<size-1)
            str[i++]=ch;
    }
    
    str[i] = '\0';
    
    return i;
}
