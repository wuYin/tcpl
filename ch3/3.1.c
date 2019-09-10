#include <stdio.h>

// 优化 3.3 中 binSearch 的 while 内部条件测试的执行次数
main()
{
    int nums[] = {1, 3, 5, 7, 8, 9};
    int len = 6;
    printf("binary search: %d, %d\n", binSearch(8, nums, len), binSearch(4, nums, len)); // 4 -1
}

// 优化思路：将 if-else 的等值测试逻辑提高到 while 循环上
// 代码可读性不高
int binSearch(int target, int nums[], int n)
{
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;

    while (l <= r && nums[mid] != target) // 只要值不等就直接循环 //
    {
        if (target < nums[mid])
            r = mid - 1;
        else
            l = mid + 1;

        mid = (l + r) / 2;
    }
    if (nums[mid] == target)
        return mid;

    return -1;
}