#include <stdio.h>
#include <stdlib.h>


//������Ϊ����ʾ��
void shu_zu(int days[]) {

	int index = 0;
	for (index = 0; index < 12; index++) {
		//�����ʾ��
		printf("Month %2d has % d days. \n", index + 1, days[index]);

		//ָ���ʾ��
		//printf("Month %2d has % d days. \n", index + 1, *(days + index));
	}

}

//ָ����Ϊ����ʾ��
void zhi_zhen(int *days) {

	int index = 0;
	for (index = 0; index < 12; index++) {
		//�����ʾ��
		//printf("Month %2d has % d days. \n", index + 1, days[index]);

		//ָ���ʾ��
		printf("Month %2d has % d days. \n", index + 1, *(days + index));
	}

}


int main(void) {
	int days[12] = { 31, 28, 31, 30, 31,30,31,31,30, 31,30, 31 };
	/*
	int index = 0;
	for (index = 0; index < 12; index++) {
		//�����ʾ��
		//printf("Month %2d has % d days. \n", index + 1, days[index]);

		//ָ���ʾ��
		printf("Month %2d has % d days. \n", index + 1, *(days+index));
	}
	*/

	zhi_zhen(days);

	system("pause");
	return 0;
}