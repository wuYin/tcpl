#include <stdio.h>

main()
{
    // float f = 2.1;
    // switch(f){    // statement requires expression of integer type ('float' invalid)
    //     case 2.1: // expression is not an integer constant expression
    // }

    // int i, j = 10;
    // printf("%d, %d\n", i, j); // 345969106 10

    for (float i = 1, j = 5; i < j; i++, j--)
        printf("%.0f+%.0f = 6\n", i, j);

    // 1+5 = 6
    // 2+4 = 6
}