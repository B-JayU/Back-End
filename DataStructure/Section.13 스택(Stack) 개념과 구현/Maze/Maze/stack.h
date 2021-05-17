//
//  stack.h
//  Maze
//
//  Created by 조팝개발자by_ju on 2021/05/17.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "pos.h"

void push(position e);
int is_full(void);
position pop(void);
int is_empty(void);

#endif /* stack_h */
