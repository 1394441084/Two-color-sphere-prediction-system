#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��ָ��ʾ��˵��
//�����������ӹ���
//VS2019�㲻�˻�ָ��,Ҳ����û�г�ʼֵ��ָ��
void Get_two_roomsand_get_the_girl_over_here() {
	int room1 = 666;
	int room2 = 888;
	int girl = 0;
	//Կ��
	//int* keys=0;//��ָ��NULL
	//��ָ�����������,��������Ϊ��ָ��,�������ʱ,���ϴε�ֵ���ݹ�����
	int* keys = NULL;
	printf("��Ҫȥ������:");
	scanf_s("%d",&girl);

	if (girl == 666) {
		keys = &room1;
	}
	else if (girl == 888) {
		keys = &room2;
	}
	if (keys == 0) {
		printf("�����治����˼,���з��䶼������.\n");
	}else{
		printf("ѡ��ķ�����:%d\n", *keys);
	}
	
}

//ָ����������
void Pointer_self_increment() {
	int age[] = {21,15,18,14,23,28,10};
	int subscript = sizeof(age)/sizeof(age[0]);
	for (int i = 0; i < subscript; i++) {
		printf("��%d��ѧԱ����:%d\n", i+1, age[i]);
	}
	//��ӡ����ĵ�ַ�͵�һ����Ա�ĵ�ַ
	printf("age����ĵ�ַ:Ox%p ,��һ��Ԫ�صĵ�ַ:Ox%p ,", age, &age[0]);
	printf("�ڶ���Ԫ�صĵ�ַ:Ox%p\n", &age[1]);//�����ַ�͵�һԪ�ص�ַ��һ����

	int* p = age;
	//���ʵ�һ��Ԫ��
	printf("��һ��Ԫ�صĵ�ַ:%d\n", *p);
	p += 1;//�������Ż�Ĭ��:p=p+1*sizeof(int),�Ӷ�����p+=4;
	printf("�ڶ���Ԫ�صĵ�ַ:%p\n", p);
	printf("�ڶ���Ԫ�صĵ�ַ:%d\n", *p);

	int* p1 = age;
	//ָ���������
	for (int i = 0; i < subscript; i++) {
		printf("��%d��Ԫ�صĵ�ַ:%d  ��ַ:Ox%p\n",i+1, *p1,p1);
		p1++;
	}

	printf("-------------�ָ���--------------\n");

	char ch[4] = {'a','b','c','d'};
	char* ch1 = ch;
	for (int i = 0; i < sizeof(ch); i++) {
		printf("��%d��Ԫ�صĵ�ַ:%c  ��ַ:Ox%p\n", i + 1, *ch1, ch1);
		ch1++;//�������Ż�Ĭ��:ch1=ch1+1*sizeof(char);
	}
	//�ܽ�:ָ��++�ĸ�������ָ�뵱ǰ��ַ������ָ������

}

//ָ���Լ�����
//�����ַ���,���ܸı�ԭ�ַ���,������ת���
void Pointer_self_subtraction() {
	char str[128];
	printf("����������Ҫ��ת���ַ���:\n");
	scanf_s("%s", &str, sizeof(str));
	int len = strlen(str);//��ȡ��ǰ�ַ����ĳ���

	//��ת�ַ�������1
	/*
	char tmp;
	for (int i = 0; i < len / 2; i++) {
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1-i] = tmp;
	}
	//for (int i = 0; i < len; i++) {
	//	printf("%c", str[i]);
	//}
	printf("��ת��:%s\n", str);
	*/

	//��ת�ַ�������2
	/*
	for (int i = 0; i < len; i++) {
		printf("%c", str[len - 1 - i]);
	}
	*/

	//��ת�ַ�������3
	/*
	for(int i =len-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	*/

	//��ת�ַ�������4,��ָ���Լ�ʵ��
	char* s = &str[len - 1];//ȡstr�������һ��Ԫ�صĵ�ַ
	for (int i = 0; i < len; i++) {
		printf("%c", *s--);
		//s--;
	}

	printf("\n");
}

/*
(1)ʹ�á�ָ��-ָ�롱�ķ�ʽ������������Ԫ�ص�ƫ��ֵ;
(2)ʹ�á�ָ��-ָ�롱�ķ�ʽ�����ַ���Ԫ�ص�ƫ��ֵ;
(3)ָ����ָ��û�мӷ�
(4)ָ��-ָ��,���ó���:ָ��ͬһ����.�õ��Ľ��Ϊ��ָ��֮���Ԫ����Ŀ
*/
void Operation() {
	int ages[] = {20,18,19,24,23,28,30,38,35,32};
	int ages1[] = {18,19,20,22};
	int len = sizeof(ages) / sizeof(ages[0]);
	int* martin = ages + 6;//30
	int* rock = ages + 9;//32
	printf("martin = %d\n",*martin);
	printf("rock - martin = %d\n",(rock-martin)) ;
	//��ָ��ָ��ͬ����,����Ľ��Ϊ��ָ��֮���Ԫ����Ŀ,��������ָ��֮�������ֽ�
	//��Ȼ*(����),���ܵó���ָ������ֽ�
	printf("martin - rock = %d\n",(martin-rock)) ;

	martin = ages + 6;//ָ��ָ��ͬ����ü���û������
	rock = ages1 + 3;//��ַ����ٳ������Ͳŵó����
	//���=-9,��ַ�����24,��ת��Ϊ2*16+4=36,36/4(�����ֽ�)=9.
	printf("martin��ַ:%p  rock��ַ:%p  rock-martin=%d\n", martin, rock, rock - martin);
}



int main(void) {
	Operation();
	system("pause");
	return 0;
}