#include <stdio.h>
#include <stdlib.h>

/*
��дһ�����򣬳�ʼ��һ�� double ���͵����飬Ȼ��Ѹ���������� 
������ 3 ���������� �У��� main()�������� 4 �����飩��
ʹ�ô������ʾ���� �������е� 1 �ݿ�����ʹ�ô�ָ ���ʾ����
ָ������ĺ������е� 2 �ݿ����� 
��Ŀ����������Դ�������ʹ�������Ԫ�ظ� ����Ϊǰ���������Ĳ�����
�� 3 ��������Ŀ����������Դ��������ָ��Դ�������һ��Ԫ �غ����Ԫ�ص�ָ �롣
Ҳ����˵������������������������������ʾ�� 
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; 
double target1[5];
double target2[5]; 
double target3[5]; 
copy_arr(target1, source, 5); 
copy_ptr(target2, source, 5); 
copy_ptrs(target3, source, source + 5);
*/

//���鿽��
void a11(double a1[], double a[], int a11) {
	for (int i = 0; i < a11; i++) {
		a1[i] = a[i];
	}
}

//ָ���ʾ����ָ������ĺ���
void a22(double a2[], double a[], int a22) {
	double* p = a;
	for (int i = 0; i < a22; i++) {
		a2[i] = *(p++);
	}
}

void a33(double a3[], double a[], double *a33) {
	
	int i = 0;
	a33--;
	/*
	while (1) {
		if (a[i] == '\0')break;
		a3[i] = a[i];
		i++;
	}
	//printf("%p\n", a33);
	*/
	while (1) {
		a3[i] = *(a33--);
		i++;
		if (a33 == a-1)  break; 
	}
}

int main(void) {
	double a[5] = { 1.1, 2.2, 3.3, -4.4, 5.5 };
	double a1[5] = {0};
	double a2[5] = {0};
	double a3[5] = {0};

	//�����ʾ��
	a11(a1, a, 5);
	for(int i=0;i<5;i++){
	printf("%.1f  ", a1[i]);
	}
	printf("\n");
	//�����ʾ��

	//ָ���ʾ����ָ������ĺ���
	a22(a2, a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%.1f  ", *(a2+i));
	}
	printf("\n");
	//ָ���ʾ����ָ������ĺ���

	//printf("%p\n", &a[5]);
	a33(a3, a, a+5);
	for (int i = 0; i < 5; i++) {
		printf("%.1f  ", *(a3 + 4-i));
	}
	printf("\n");

	system("pause");
	return 0;
}