#include <stdio.h>

// 3.8 goto 语句与标号
main()
{
    // 检查两个数组中是否有相同的元素
    int a[] = {1, 3, 5, 6, 7, 10};
    int b[] = {2, 4, 6, 8, 10};
    int same = -1;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            if (a[i] == b[j])
            {
                same = a[i];
                goto found;
            }
found:
    printf("found: %d\n", same);
}