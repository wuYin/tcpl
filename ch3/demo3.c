#include <stdio.h>

int binSearch(int target, int nums[], int n);

main()
{
    int nums[] = {1, 3, 5, 7, 8, 9};
    int len = 6;
    printf("binary search: %d, %d\n", binSearch(8, nums, len), binSearch(4, nums, len)); // 4 -1
}

// 折半查找
// 在长为 n 的有序数组 nums 中查找数 target，存在则返回索引，否则返回 -1
int binSearch(int target, int nums[], int n)
{
    int l, r, mid;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (nums[mid] < target)
            l = mid + 1;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            return mid;
    }

    return -1;
}