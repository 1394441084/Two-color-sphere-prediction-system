#include <iostream>
#include <Windows.h>

using namespace std;

//��һ���������飬 a[3] = { 7,2,5 }�� 
//Ҫ��ʹ��ָ��ʵ�������Ա��С�����˳�����У��� ���Ϊ��a[3] = { 2,5,7 };

//����ָ��
int a123a(const void* a, const void* b) {
	//printf("��ѽ,�ұ��������,��ɧ��Ŷ!,�Һ�ϲ��Ŷ!\n");
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	//printf("a�ĵ�ַ:%p  b�ĵ�ַ:%p\n", &a,&b);
	return *a1 - *b1;//��С����
	//return *b1 - *a1;//�Ӵ�С
}

int main(void) {
	
	//qsort �����������������
	int a[] = { 2,5,7};
	//C�⺯��,��С��������,��������
	//qsort(��������,�ж��ٸ�,һ���Ƕ����ֽ�,���򷽷�(�Լ��ĺ���)����qsort��Ҫ����);
	qsort(a, sizeof(a) / sizeof(int), sizeof(int), &a123a);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);//�������,��ӡ���
	}
	printf("\n");

	system("pause");
	return 0;
}