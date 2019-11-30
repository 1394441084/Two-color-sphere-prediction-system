#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void指针的介绍
void void_introduction() {
	int arr[3] = { 1,2,3 };
	char ch = '8';

	void* p = arr;//定义了void类型的指针
	p = &ch;//其它类型可以自动转换成void*指针

	//虽然void类型指针无法直接访问,但里面还是保存着地址能打印出来的
	printf("无类型指针:Ox%p  ch的地址:Ox%p\n", p, &ch);

	//强制类型转换
	char* p1 = (char*)p;
	printf("p1指向的字符是:%c  ", *p1);
	//void*指针不允许算式运算,如:p++;
}

//函数指针
int Function_pointer(const void *a,const void *b) {
	//printf("哎呀,我被你调用了,好骚气哦!,我好喜欢哦!\n");
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	//printf("a的地址:%p  b的地址:%p\n", &a,&b);
	//return *a1 - *b1;//从小到大
	return *b1 - *a1;//从大到小
}

int Function_pointer1(const void* a, const void* b) {

	char c1 = *((char *)a);
	char c2 = *((char *)b);

	if (c1 >= 'A' && c1 <= 'Z')c1 += 32;
	if (c2 >= 'A' && c2 <= 'Z')c1 += 32;

	return c1 -c2;
}



int main(void) {
	int x = 10, y = 20;
	printf("函数的地址:%p \n", &Function_pointer);//打印出了函数的地址
	//Function_pointer(&x,&y);//函数的地址跟函数内部变量的地址差很远,不是一块区域的

	//指向函数的指针(执行函数指针的定义)
	//把函数声明移过来,把函数名改成(*函数指针名)
	int (*Pointing_function)(const void*, const void*);
	//函数指针的赋值
	Pointing_function = &Function_pointer;

	//(*Pointing_function)==Function_pointer
	//(*Pointing_function)(&x, &y);//按普通指针解引的方式进行调用
	Pointing_function(&x, &y);//直接调用

	//qsort 对整形数组进行排序
	int arr[] = { 2,10,30,1,11,8,7,111,520 };
	//C库函数,从小到大排序,快速排序
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), &Function_pointer);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//qsort 可以对任何类型的数组进行排序
	char arr1[] = { "adcdefgJHDABNSG" };
	qsort(arr1,sizeof(arr1)/sizeof(char)-1,sizeof(char),&Function_pointer1);
		for (int i = 0; i < sizeof(arr1) / sizeof(char); i++) {
			printf("%c ", arr1[i]);
		}




	printf("\n");

	system("pause");
	return 0;
}