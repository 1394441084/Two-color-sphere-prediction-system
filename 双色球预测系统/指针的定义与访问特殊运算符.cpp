#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//����ָ��,ָ��ĳ�����,ָ��Ķ���
void First_time_pointer() {
	int age = 0;

	//������ָ��p,����һ�����ֽڵĿռ䱣����age�ĵ�ַ
	//�Ǵ�ʱage��ָ��*p���ܲ���age�Ŀռ�,age=80;��ӡ������age����80
	//p=100;p��������age�ĵ�ַ,�ռ�����,����100��˳�ŵ�ַ
	//ͨ���ܽ���age�Ŀռ�,��ӡ������age����100;
	//�����ӡp,��ô��ӡ�����ľ�age�ĵ�ַ
	int* p, p0;//int *p1, *p2;����������ָ��
	p0 = 0;//p0ֻ�����α���;
	p = &age;//����,ָ��*pҲ�Ǳ���
	int* p3 = &age;

	//����һ������ָ��,ָ��ͨ����ַ�ı����
	scanf_s("%d", p);//p��ָ�����Բ���ȡ��ַ��

	//scanf_s("%d",&age);//ָ����ǵ�ַ

	cout << age << endl;
	printf("ָ��p��%p\n", p);//��ӡ��ַ
}

//ָ���ַ��ռ�
void Pointer_addressand_Space() {
	int room = 2;
	int* p1 = &room;
	int* p2 = &room;

	printf("room��ַ:0x%p\n", &room);//room��ַ:0x004FF988
	printf("p1��ַ:0x%p\n", &p1);	   //p1��ַ:0x004FF97C
	printf("p2��ַ:0x%p\n", &p2);	   //p2��ַ:0x004FF970

	printf("room��ռ�ֽ�:%d\n", sizeof(room));//32,64,86ϵͳ����ռ�ֽ�:4
	printf("p1��ռ�ֽ�:%d\n", sizeof(p1));    //ָ����64ϵͳ����ռ�ֽ�:8
	printf("p2��ռ�ֽ�:%d\n", sizeof(p2));   //ָ����32,86ϵͳ��ռ�ֽ�:8
}

//ָ��ķ���
void Access_to_pointers() {
	int room = 2;
	/*
	int room1 = 3;
	int* p1 = &room;
	//����(��,д)ָ����������ֵ,��������ͨ�����ķ���һ��
	int* p2 = p1;//int* p2 = &room;
	int* p3 = p2;

	printf("room�ĵ�ַOx%p\n", &room);
	printf("p1��ֵ:Ox%p  p2��ֵ:Ox%p\n", p1, p2);//&room
	printf("p3��ֵ:Ox%p\n",p3);//��%d,%x,%XҲ�ܴ�ӡ�������ᱨ����

	p3 = &room1;
	printf("p3��ֵ:Ox%p  room1�ĵ�ַ:Ox%p\n",p3,&room1);
	*/
	int* girl = &room;
	int x = 0;
	x = *girl;//*�����������,*girl��ʾ��ȡָ��girl��ָ�������ֵ,*girl�൱��room
	printf("x=%d\n", x);
	*girl = 4;
	printf("room=%d  *girl=%d\n", room,*girl);

}

int main(void) {
	Access_to_pointers();

	system("pause");
	return 0;
}