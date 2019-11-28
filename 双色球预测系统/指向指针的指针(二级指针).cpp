#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int gui2 = 888;//二号柜子里存的是老婆收缴的我的工资
	int *gui1=&gui2;//一号柜子里存的是二号柜子的地址和密码
	//老婆一号柜子的地址和密码
	int **wife = &gui1; //int *gui0 = &gui1;

	printf("老婆打开一号柜子,得到二号柜子的地址:Ox%p\n", *wife);
	printf("gui2的地址:Ox%p\n", &gui2);
	//printf("**wife:%d\n", *wife);

	int* husband = *wife;
	//通过老婆说梦话
	printf("通过老婆打开二号柜子拿到钱:%d\n", *husband);

	//老婆发善心,地址,密码都告诉我了,直接就去拿钱了
	printf("直接去二号柜子拿钱:%d\n",**wife);

	system("pause");
	return 0;
}