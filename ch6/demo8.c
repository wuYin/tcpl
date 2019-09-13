#include <stdio.h>

// 6.8 联合
int main() {
	struct user {
		char *name;
		union {
			int iv;
			float fv;
			char *sv;
		} un;
	} user;
	user.un.sv = "xxx";
	printf("%s\n", user.un.sv);
}

struct x {
	struct x *y;
};