#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int gui2 = 888;//���Ź��������������սɵ��ҵĹ���
	int *gui1=&gui2;//һ�Ź��������Ƕ��Ź��ӵĵ�ַ������
	//����һ�Ź��ӵĵ�ַ������
	int **wife = &gui1; //int *gui0 = &gui1;

	printf("���Ŵ�һ�Ź���,�õ����Ź��ӵĵ�ַ:Ox%p\n", *wife);
	printf("gui2�ĵ�ַ:Ox%p\n", &gui2);
	//printf("**wife:%d\n", *wife);

	int* husband = *wife;
	//ͨ������˵�λ�
	printf("ͨ�����Ŵ򿪶��Ź����õ�Ǯ:%d\n", *husband);

	//���ŷ�����,��ַ,���붼��������,ֱ�Ӿ�ȥ��Ǯ��
	printf("ֱ��ȥ���Ź�����Ǯ:%d\n",**wife);

	system("pause");
	return 0;
}