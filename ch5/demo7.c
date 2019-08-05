#include <stdio.h>

int date2day(int y, int m, int d);
void day2date(int y, int d, int *pm, int *pd);
void f(int nums[][13]);

// 多维数组
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

main()
{
    printf("%d\n", date2day(2000, 3, 20)); // 80
    int pm = 0, pd = 0;
    day2date(2000, 80, &pm, &pd);
    printf("day2date: %d, %d", pm, pd); // 3, 20

    // 多维数组传参需指定列数
    f(daytab);
}

// void f(int nums[][13])
// void f(int nums[][])   // error: array has incomplete element type 'int []'
void f(int (*daytab)[13])
{
    // int nums[][13]
    // int (*nums)[13] // 等效
    // int *nums[13]   // [] 优先级高于 *，此时为一维数组
}

// 日期转为第几天
int date2day(int y, int m, int d)
{
    // 闰年
    // 普通闰年：4 的倍数且不是 100 的倍数
    // 世纪闰年：400 的倍数
    int leapIdx = (y % 4 == 0 && y % 100 == 0) || y % 400 == 0; // 条件表达式 false 0 / true 1
    for (int i = 1; i < m; i++)
        d += daytab[leapIdx][i];
    return d;
}

// 天数转日期
// C 函数的多返回值：以多个指针参数的形式传入并修改值，达到返回值的效果
void day2date(int y, int d, int *pm, int *pd)
{
    int leapIdx = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    int m;
    for (m = 1; d > daytab[leapIdx][m]; m++) // 向上累加月份的天数
        d -= daytab[leapIdx][m];
    *pm = m;
    *pd = d;
}