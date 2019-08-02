#include <stdio.h>
#include <limits.h> // 定义各类型的最值

// 输出 signed / unsigned 限定的 char/short/int/long 的最值
main()
{
    // 直接输出标准库 limits.h 定义的常量
    // signed
    printf("signed char min: %d\n", SCHAR_MIN); // -128
    printf("signed char max: %d\n", SCHAR_MAX); // 127

    printf("signed short min: %d\n", SHRT_MIN); // -32768
    printf("signed short max: %d\n", SHRT_MAX); // 32767

    printf("signed int min: %d\n", INT_MIN);
    printf("signed int max: %d\n", INT_MAX);

    printf("signed long min: %ld\n", LONG_MIN); // 注意占位符用法
    printf("signed long max: %ld\n", LONG_MAX); // l 即 long，u 即 unsigned

    // unsigned // min 均为0
    printf("unsigned char max: %d\n", UCHAR_MAX);  // 255
    printf("unsigned short max: %d\n", USHRT_MAX); // 65535
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
}