#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int wife = 24;
	int girl = 18;

	//��һ�� ������
	int* zha_nan = &wife;
	*zha_nan = 25;
	zha_nan = &girl;
	*zha_nan = 19;
	printf("wife:%d  girl:%d\n", wife, girl);

	//�ڶ��� ֱ����
	//const int* zhi_nan = &wife;
	int const *zhi_nan = &wife;
	//*zhi_nan = 26;�����Ų�ϲ��ֱ��,�������޸�
	printf("ֱ�����ŵ�����:%d\n", *zhi_nan);
	if (wife != 24) { printf("��,�ж���ñ��\n"); }
	zhi_nan = &girl;
	printf("ֱ�����˵�����:%d\n", *zhi_nan);
	if (girl != 18) { printf("Ů�������ҵ�ñ��,�Һ�ϲ��.\n"); }

	//������ ů����
	int* const nuan_nan = &wife;
	*nuan_nan = 26;
	//nuan_nan = &girl;//������ָ���ĵ�ַ
	printf("ů����������:%d\n", *nuan_nan);
	
	//������ ����ů����
	const int* const super_nuan_nan = &wife;
	//super_nuan_nan = &girl;//����ָ����Ů��(��ַ)
	//*super_nuan_nan = 27;//һ��������Ϊ��,�����޸�����



	system("pause");
	return 0;
}