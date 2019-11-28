#include <stdio.h>
#include <stdlib.h>

//一级指针函数示例
void exchange(int *a,int *b) {
	int tmp=*a;
	*a = *b;
	*b = tmp;
	*b += 20;
}


//二级指针函数示例
void boy_home(int **meipo) {
	//静态变量,函数释放还会存在,是全局变量的存在
	static int boy = 23;
	//用间接符*把外面的一级指针空间打开一个口,清空,然后将boy的地址放进去
	*meipo = &boy;
}

int main(void) {

	/*一级指针函数示例
	int x=10, y=100;
	exchange(&x, &y);
	printf("x=%d  y=%d\n", x, y);
	*/
	int* meipo = NULL;
	//把meipo的地址传递到boy_home函数,二级指针接收
	boy_home(&meipo);
	//函数运作中搞了这个meipo=&boy;
	printf("boy:%d\n",*meipo);//间接访问了boy,打印出了boy:23

	system("pause");
	return 0;
}