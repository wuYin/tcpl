#include <stdio.h>

#define MAX_LINE 100

int main(int argc, char *argv[])
{
    // int *ip = &MAX_LINE;

    char s[] = "demo";
    printf("%p, %p\n", s, &s[0]);       // 0x7ffee5dad7bb, 0x7ffee5dad7bb
    printf("%c, %c\n", s[2], *(s + 2)); // m, m

    printf("%d, %d\n", NULL == 0, NULL == '\0'); // 1 1

    char p1[] = "abcd";
    char *p2 = "abcd";
    p1[1] = 'B';

    printf("%d\n", argv[argc] == NULL); // 1
}

// void up(int twice[][])   // error: array has incomplete element type 'int []'
// void up(int twice[2][2]) // ok
// void up(int twice[][2])  // ok
void up(int (*twice)[2]) // ok
{
    twice[0][0]++;
    twice[1][1]++;
}