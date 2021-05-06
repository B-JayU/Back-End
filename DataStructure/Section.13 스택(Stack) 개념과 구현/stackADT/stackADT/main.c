//
//  main.c
//  stackADT
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#include <stdio.h>
#include "STACK_ADT.h"

int main(int argc, const char * argv[]) {
    
    Stack s1 = create();
    Stack s2 = create();
    
    push(s1, 12);
    push(s2, 9);
    push(s1, 53);
    push(s2, 47);
    
}
