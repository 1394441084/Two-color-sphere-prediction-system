#include <stdio.h>
#include <stdlib.h>

/*
实现一个函数，使用指针连接两个字符串。 函数输入： 两个源字符串的指针，目的字符串的指针
*/

//两字符串拼接函数(a字符串,b字符串,c返回过去的字符串)
void 函数拼装(char a[], char b[],char c[]) {
	int a1 = 0;
	int b1 = 0;
	while (1) {
		if (a[a1] == '\0') {
			break;
		}
		c[a1] = a[a1];
		a1++;
	}
	while (1) {
		c[a1] = b[b1];
		if (b[b1] == '\0') {
			break;
		}
		a1++;
		b1++;
	}
}



int main(void) {
	char a[258] = { 0 };
	char b[258] = { 0 };
	char c[1024] = { 0 };//接收连接起来的字符串
	printf("请输入a字符串:");
	scanf_s("%s", a,sizeof(a));
	printf("请输入b字符串:");
	scanf_s("%s", b,sizeof(b));
	函数拼装(a, b, c);
	printf("连接的字符串是这样的:\n%s\n",c);
	
	system("pause");
	return 0;
}