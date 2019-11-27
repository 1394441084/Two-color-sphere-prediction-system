#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//初试指针,指针的初讲解,指针的定义
void First_time_pointer() {
	int age = 0;

	//定义了指针p,开了一个四字节的空间保存着age的地址
	//那此时age与指针*p都能操作age的空间,age=80;打印出来的age就是80
	//p=100;p里面存的是age的地址,空间满了,那这100就顺着地址
	//通道跑进了age的空间,打印出来的age就是100;
	//如果打印p,那么打印出来的就age的地址
	int* p, p0;//int *p1, *p2;定义了两个指针
	p0 = 0;//p0只是整形变量;
	p = &age;//定义,指针*p也是变量
	int* p3 = &age;

	//输入一个数到指针,指针通过地址改变参数
	scanf_s("%d", p);//p是指针所以不用取地址符

	//scanf_s("%d",&age);//指针就是地址

	cout << age << endl;
	printf("指针p是%p\n", p);//打印地址
}

//指针地址与空间
void Pointer_addressand_Space() {
	int room = 2;
	int* p1 = &room;
	int* p2 = &room;

	printf("room地址:0x%p\n", &room);//room地址:0x004FF988
	printf("p1地址:0x%p\n", &p1);	   //p1地址:0x004FF97C
	printf("p2地址:0x%p\n", &p2);	   //p2地址:0x004FF970

	printf("room所占字节:%d\n", sizeof(room));//32,64,86系统中所占字节:4
	printf("p1所占字节:%d\n", sizeof(p1));    //指针在64系统中所占字节:8
	printf("p2所占字节:%d\n", sizeof(p2));   //指针在32,86系统所占字节:8
}

//指针的访问
void Access_to_pointers() {
	int room = 2;
	/*
	int room1 = 3;
	int* p1 = &room;
	//访问(读,写)指针变量本身的值,跟其它普通变量的访问一样
	int* p2 = p1;//int* p2 = &room;
	int* p3 = p2;

	printf("room的地址Ox%p\n", &room);
	printf("p1的值:Ox%p  p2的值:Ox%p\n", p1, p2);//&room
	printf("p3的值:Ox%p\n",p3);//用%d,%x,%X也能打印出来但会报警告

	p3 = &room1;
	printf("p3的值:Ox%p  room1的地址:Ox%p\n",p3,&room1);
	*/
	int* girl = &room;
	int x = 0;
	x = *girl;//*是特殊运算符,*girl表示读取指针girl所指向变量的值,*girl相当于room
	printf("x=%d\n", x);
	*girl = 4;
	printf("room=%d  *girl=%d\n", room,*girl);

}

int main(void) {
	Access_to_pointers();

	system("pause");
	return 0;
}