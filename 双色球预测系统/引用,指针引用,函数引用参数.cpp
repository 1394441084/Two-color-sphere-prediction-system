#include <iostream>
#include <Windows.h>

using namespace std;

//1.引用概念
void Reference_concept() {
	int a = 666;
	int c = 899;
	//&b==在一个内存空间(地址&),赋予了一个叫b的花名
	//叫b就是a本人啦,当然叫a也是它
	//打b就是打a,修改b就是修改a,这个不就是指针么?没错底层就是指针
	//别名只针对已定义的变量,不然你替空气取花名?
	//可以取多个别名
	int& b = a;//定义了别名b,成为了a的别名
	b = c;//等同于a=c;
	printf("b=%d a=%d\n", b,a);//666,指向c后=899
	b = 888;
	printf("b=%d  a=%d c=%d\n", b, a,c);//888 888 899
	//a和b地址一毛一样,b和c地址不一样
	printf("b地址:%p  a地址:%p c地址:%p\n", &b, &a ,&c);
	//引用有空间的,引用就是更安全的指针
	
}

//2.引用作为函数的参数
void Reference_parameter(int &a,int &b) {
	int tmp = a;
	a = b;//引用作为函数参数不用初始化
	b = tmp;
}

//3.指针的引用
void Reference_pointer() {//定义
	int x = 666;
	int* p = &x;
	int*& o = p;//指针引用
	int& b = *p;//普通引用
	//x:Ox0135FB84 p:Ox0135FB78 o:Ox0135FB78 b:Ox0135FB84
	printf("x:Ox%p p:Ox%p o:Ox%p b:Ox%p\n", &x, &p, &o, &b);
	//x=666 p=666 o=666 b=666
	printf("x=%d p=%d o=%d b=%d\n", x, *p, *o, b);
}
void girl_house(int*& wife) {//函数里的指针引用
	static int girl = 18;
	wife = &girl;
}
void girl_house1(int & wife) {//wife是传过来的变量的别名
	static int girl1 = 20;
	wife = girl1;
}
void girl_house2(int** wife) {
	static int girl2 = 22;
	*wife = &girl2;//把传来的指针打开,将NULL值替换成&girl2
}

//常量引用
void Constant_reference() {
	int a = 10;
	//int& b = a;
	const int& b = a;//const把引用变成只读,不能通过引用修改变量
	//b = 100;
	const int& c = 30;//c不能被修改,相当于常量,没有意义
	const int c1 = 40;
	printf("a=%d c=%d c1=%d\n", a,c,c1);
}

int main(void) {

	//2.引用作为函数的参数
	printf("----------引用作为函数的参数----------\n");
	int x = 10, y = 100;
	//函数&a成为x的别名,y
	Reference_parameter(x,y);
	printf("x=%d y=%d\n", x, y);
	

	printf("----------指针引用----------\n");
	int wife1 = 0;
	int* wife = NULL;

	girl_house(wife);
	//wife=&girl;
	printf("wife老婆年龄:%d\n", *wife);

	girl_house1(wife1);
	//wife1=girl1;
	printf("wife1老婆年龄:%d\n", wife1);
	
	girl_house2(&wife);
	//wife=&girl2;
	printf("wife1老婆年龄:%d\n", *wife);

	printf("----------常量引用----------\n");
	Constant_reference();
	system("pause");
	return 0;
}