#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//voidָ��Ľ���
void void_introduction() {
	int arr[3] = { 1,2,3 };
	char ch = '8';

	void* p = arr;//������void���͵�ָ��
	p = &ch;//�������Ϳ����Զ�ת����void*ָ��

	//��Ȼvoid����ָ���޷�ֱ�ӷ���,�����滹�Ǳ����ŵ�ַ�ܴ�ӡ������
	printf("������ָ��:Ox%p  ch�ĵ�ַ:Ox%p\n", p, &ch);

	//ǿ������ת��
	char* p1 = (char*)p;
	printf("p1ָ����ַ���:%c  ", *p1);
	//void*ָ�벻������ʽ����,��:p++;
}

//����ָ��
int Function_pointer(const void *a,const void *b) {
	//printf("��ѽ,�ұ��������,��ɧ��Ŷ!,�Һ�ϲ��Ŷ!\n");
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	//printf("a�ĵ�ַ:%p  b�ĵ�ַ:%p\n", &a,&b);
	//return *a1 - *b1;//��С����
	return *b1 - *a1;//�Ӵ�С
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
	printf("�����ĵ�ַ:%p \n", &Function_pointer);//��ӡ���˺����ĵ�ַ
	//Function_pointer(&x,&y);//�����ĵ�ַ�������ڲ������ĵ�ַ���Զ,����һ�������

	//ָ������ָ��(ִ�к���ָ��Ķ���)
	//�Ѻ��������ƹ���,�Ѻ������ĳ�(*����ָ����)
	int (*Pointing_function)(const void*, const void*);
	//����ָ��ĸ�ֵ
	Pointing_function = &Function_pointer;

	//(*Pointing_function)==Function_pointer
	//(*Pointing_function)(&x, &y);//����ָͨ������ķ�ʽ���е���
	Pointing_function(&x, &y);//ֱ�ӵ���

	//qsort �����������������
	int arr[] = { 2,10,30,1,11,8,7,111,520 };
	//C�⺯��,��С��������,��������
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), &Function_pointer);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//qsort ���Զ��κ����͵������������
	char arr1[] = { "adcdefgJHDABNSG" };
	qsort(arr1,sizeof(arr1)/sizeof(char)-1,sizeof(char),&Function_pointer1);
		for (int i = 0; i < sizeof(arr1) / sizeof(char); i++) {
			printf("%c ", arr1[i]);
		}




	printf("\n");

	system("pause");
	return 0;
}