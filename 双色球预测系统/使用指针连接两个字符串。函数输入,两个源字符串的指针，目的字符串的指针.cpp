#include <stdio.h>
#include <stdlib.h>

/*
ʵ��һ��������ʹ��ָ�����������ַ����� �������룺 ����Դ�ַ�����ָ�룬Ŀ���ַ�����ָ��
*/

//���ַ���ƴ�Ӻ���(a�ַ���,b�ַ���,c���ع�ȥ���ַ���)
void ����ƴװ(char a[], char b[],char c[]) {
	int a1 = 0;
	int b1 = 0;
	while (1) {
		if (a[a1] == '\0') {
			break;
		}
		c[a1] = a[a1];
		a1++;
	}
	while (1) {
		c[a1] = b[b1];
		if (b[b1] == '\0') {
			break;
		}
		a1++;
		b1++;
	}
}



int main(void) {
	char a[258] = { 0 };
	char b[258] = { 0 };
	char c[1024] = { 0 };//���������������ַ���
	printf("������a�ַ���:");
	scanf_s("%s", a,sizeof(a));
	printf("������b�ַ���:");
	scanf_s("%s", b,sizeof(b));
	����ƴװ(a, b, c);
	printf("���ӵ��ַ�����������:\n%s\n",c);
	
	system("pause");
	return 0;
}