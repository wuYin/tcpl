#include <stdio.h>
#include "calc.h"

// 定义存放栈数据的数组、栈顶游标的全局变量
double stack[MAX_ELEMS]; // 栈数组
int next = 0;            // 数组下一个空闲位置的游标
