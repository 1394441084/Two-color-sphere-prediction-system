#include <iostream>
#include <Windows.h>

using namespace std;

//1.���ø���
void Reference_concept() {
	int a = 666;
	int c = 899;
	//&b==��һ���ڴ�ռ�(��ַ&),������һ����b�Ļ���
	//��b����a������,��Ȼ��aҲ����
	//��b���Ǵ�a,�޸�b�����޸�a,���������ָ��ô?û��ײ����ָ��
	//����ֻ����Ѷ���ı���,��Ȼ�������ȡ����?
	//����ȡ�������
	int& b = a;//�����˱���b,��Ϊ��a�ı���
	b = c;//��ͬ��a=c;
	printf("b=%d a=%d\n", b,a);//666,ָ��c��=899
	b = 888;
	printf("b=%d  a=%d c=%d\n", b, a,c);//888 888 899
	//a��b��ַһëһ��,b��c��ַ��һ��
	printf("b��ַ:%p  a��ַ:%p c��ַ:%p\n", &b, &a ,&c);
	//�����пռ��,���þ��Ǹ���ȫ��ָ��
	
}

//2.������Ϊ�����Ĳ���
void Reference_parameter(int &a,int &b) {
	int tmp = a;
	a = b;//������Ϊ�����������ó�ʼ��
	b = tmp;
}

//3.ָ�������
void Reference_pointer() {//����
	int x = 666;
	int* p = &x;
	int*& o = p;//ָ������
	int& b = *p;//��ͨ����
	//x:Ox0135FB84 p:Ox0135FB78 o:Ox0135FB78 b:Ox0135FB84
	printf("x:Ox%p p:Ox%p o:Ox%p b:Ox%p\n", &x, &p, &o, &b);
	//x=666 p=666 o=666 b=666
	printf("x=%d p=%d o=%d b=%d\n", x, *p, *o, b);
}
void girl_house(int*& wife) {//�������ָ������
	static int girl = 18;
	wife = &girl;
}
void girl_house1(int & wife) {//wife�Ǵ������ı����ı���
	static int girl1 = 20;
	wife = girl1;
}
void girl_house2(int** wife) {
	static int girl2 = 22;
	*wife = &girl2;//�Ѵ�����ָ���,��NULLֵ�滻��&girl2
}

//��������
void Constant_reference() {
	int a = 10;
	//int& b = a;
	const int& b = a;//const�����ñ��ֻ��,����ͨ�������޸ı���
	//b = 100;
	const int& c = 30;//c���ܱ��޸�,�൱�ڳ���,û������
	const int c1 = 40;
	printf("a=%d c=%d c1=%d\n", a,c,c1);
}

int main(void) {

	//2.������Ϊ�����Ĳ���
	printf("----------������Ϊ�����Ĳ���----------\n");
	int x = 10, y = 100;
	//����&a��Ϊx�ı���,y
	Reference_parameter(x,y);
	printf("x=%d y=%d\n", x, y);
	

	printf("----------ָ������----------\n");
	int wife1 = 0;
	int* wife = NULL;

	girl_house(wife);
	//wife=&girl;
	printf("wife��������:%d\n", *wife);

	girl_house1(wife1);
	//wife1=girl1;
	printf("wife1��������:%d\n", wife1);
	
	girl_house2(&wife);
	//wife=&girl2;
	printf("wife1��������:%d\n", *wife);

	printf("----------��������----------\n");
	Constant_reference();
	system("pause");
	return 0;
}