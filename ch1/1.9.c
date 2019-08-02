#include <stdio.h>

// 将输入复制到输出，合并其中的多个空格为一个
// prev 或 cur 不为空格则输出 cur 即可
main()
{
	int cur, prev;
	prev = '_'; // 初始化为非空格字符，类似于单链表中的 dummy 节点
	while ((cur = getchar()) != EOF)
	{
		if (cur != ' ' || prev != ' ')
			putchar(cur);
		prev = cur;
	}
}