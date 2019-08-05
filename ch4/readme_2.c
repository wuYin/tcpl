#include <stdio.h>

int sum(int x, int y);

int main()
{
    int x = 1, y = 2;
    printf("sum: %d\n", sum(x, y)); // sum: 27955024

    extern char *name;
    // printf("%s\n", name);
}