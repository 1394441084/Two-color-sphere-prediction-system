#include <stdio.h>
#include <stdlib.h>

/*
编写一个程序，初始化一个 double 类型的数组，然后把该数组的内容 
拷贝至 3 个其他数组 中（在 main()中声明这 4 个数组）。
使用带数组表示法的 函数进行第 1 份拷贝。使用带指 针表示法和
指针递增的函数进行第 2 份拷贝。 
把目标数组名、源数组名和待拷贝的元素个 数作为前两个函数的参数。
第 3 个函数以目标数组名、源数组名和指向源数组最后一个元 素后面的元素的指 针。
也就是说，给定以下声明，则函数调用如下所示： 
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; 
double target1[5];
double target2[5]; 
double target3[5]; 
copy_arr(target1, source, 5); 
copy_ptr(target2, source, 5); 
copy_ptrs(target3, source, source + 5);
*/

//数组拷贝
void a11(double a1[], double a[], int a11) {
	for (int i = 0; i < a11; i++) {
		a1[i] = a[i];
	}
}

//指针表示法和指针递增的函数
void a22(double a2[], double a[], int a22) {
	double* p = a;
	for (int i = 0; i < a22; i++) {
		a2[i] = *(p++);
	}
}

void a33(double a3[], double a[], double *a33) {
	
	int i = 0;
	a33--;
	/*
	while (1) {
		if (a[i] == '\0')break;
		a3[i] = a[i];
		i++;
	}
	//printf("%p\n", a33);
	*/
	while (1) {
		a3[i] = *(a33--);
		i++;
		if (a33 == a-1)  break; 
	}
}

int main(void) {
	double a[5] = { 1.1, 2.2, 3.3, -4.4, 5.5 };
	double a1[5] = {0};
	double a2[5] = {0};
	double a3[5] = {0};

	//数组表示法
	a11(a1, a, 5);
	for(int i=0;i<5;i++){
	printf("%.1f  ", a1[i]);
	}
	printf("\n");
	//数组表示法

	//指针表示法和指针递增的函数
	a22(a2, a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%.1f  ", *(a2+i));
	}
	printf("\n");
	//指针表示法和指针递增的函数

	//printf("%p\n", &a[5]);
	a33(a3, a, a+5);
	for (int i = 0; i < 5; i++) {
		printf("%.1f  ", *(a3 + 4-i));
	}
	printf("\n");

	system("pause");
	return 0;
}