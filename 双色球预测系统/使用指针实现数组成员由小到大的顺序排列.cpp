#include <iostream>
#include <Windows.h>

using namespace std;

//有一个整形数组， a[3] = { 7,2,5 }， 
//要求使用指针实现数组成员由小到大的顺序排列，即 结果为：a[3] = { 2,5,7 };

//函数指针
int a123a(const void* a, const void* b) {
	//printf("哎呀,我被你调用了,好骚气哦!,我好喜欢哦!\n");
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	//printf("a的地址:%p  b的地址:%p\n", &a,&b);
	return *a1 - *b1;//从小到大
	//return *b1 - *a1;//从大到小
}

int main(void) {
	
	//qsort 对整形数组进行排序
	int a[] = { 2,5,7};
	//C库函数,从小到大排序,快速排序
	//qsort(参数进来,有多少个,一个是多少字节,排序方法(自己的函数)进来qsort需要调用);
	qsort(a, sizeof(a) / sizeof(int), sizeof(int), &a123a);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);//排序好了,打印输出
	}
	printf("\n");

	system("pause");
	return 0;
}