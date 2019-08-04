#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atoi(char s[]);
void shellSort(int nums[], int n);
void reverse(char s[]);

// 3.5 while 与 for 循环
main()
{
    printf("atoi: %d\n", atoi("  -123"));
    int nums[] = {2, 5, 1, 3, 4, -6, 1, -4};
    shellSort(nums, 8);
    for (int i = 0; i < 8; i++)
        printf("%d, ", nums[i]);
    putchar('\n');

    char s[] = "abcd";
    reverse(s);
    printf("reversed: %s\n", s);
}

// 字符串转数字，跳过前缀空格与正负号
int atoi(char s[])
{
    int i, sign, res;
    for (i = 0; isspace(s[i]); i++) // isspace 跳过空白符
        ;
    sign = s[i] == '-' ? -1 : 1;    // 记录正负
    if (s[i] == '+' || s[i] == '-') // 跳过正负号
        i++;

    for (res = 0; isdigit(s[i]); i++) // isdigit 取数字并进位累加
        res = res * 10 + (s[i] - '0');

    return sign * res;
}

// 希尔排序
void shellSort(int nums[], int n)
{
    int gap, i, j, tmp;

    for (gap = n / 2; gap > 0; gap /= 2)                                   // 步长从 n/2 递减至 1
        for (i = gap; i < n; i++)                                          // 向后遍历各组
            for (j = i - gap; j >= 0 && nums[j] > nums[j + gap]; j -= gap) // 每组组内交换排序
            {
                tmp = nums[j];
                nums[j] = nums[j + gap];
                nums[j + gap] = tmp;
            }
}

// 反转字符串
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) // "," 逗号运算符从左到右求值，优先级最低
        c = s[i], s[i] = s[j], s[j] = c;            // 简化版的顺序赋值，一条语句实现 swap
}