#include <stdio.h>
#include <stdlib.h>

//һ��ָ�뺯��ʾ��
void exchange(int *a,int *b) {
	int tmp=*a;
	*a = *b;
	*b = tmp;
	*b += 20;
}


//����ָ�뺯��ʾ��
void boy_home(int **meipo) {
	//��̬����,�����ͷŻ������,��ȫ�ֱ����Ĵ���
	static int boy = 23;
	//�ü�ӷ�*�������һ��ָ��ռ��һ����,���,Ȼ��boy�ĵ�ַ�Ž�ȥ
	*meipo = &boy;
}

int main(void) {

	/*һ��ָ�뺯��ʾ��
	int x=10, y=100;
	exchange(&x, &y);
	printf("x=%d  y=%d\n", x, y);
	*/
	int* meipo = NULL;
	//��meipo�ĵ�ַ���ݵ�boy_home����,����ָ�����
	boy_home(&meipo);
	//���������и������meipo=&boy;
	printf("boy:%d\n",*meipo);//��ӷ�����boy,��ӡ����boy:23

	system("pause");
	return 0;
}