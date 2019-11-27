#include <iostream>
#include <Windows.h>
#include <time.h>//time();����,��ȡ��ǰϵͳʱ��
//#include <stdlib.h>
#pragma warning(disable:4996)//Ϊ���strpy();�ַ������ƺ��������ӵ�Ԥ����

using namespace std;

/*
				   ΪʲôҪʹ��ָ��
   1.������ֵ���ݣ� �޷�ͨ�����ú��������޸ĺ�����ʵ��
   2.�����ú�����Ҫ�ṩ���� �ġ�����ֵ"�����ú���
   3.����ֵ����ʱ�����Ķ��⿪������ߴ���ִ��Ч��
*/

//��Ѫ����,������ֵ���ݣ� �޷�ͨ�����ú��������޸ĺ�����ʵ��
int add_blood0(int blood) {
	blood += 1000;//Ѫ��
	return blood;
}

//�����ú�����Ҫ�ṩ���� �ġ�����ֵ"�����ú���
bool add_blood1(int blood) {
	if (blood > 1000) {
		return false;
	}
	else {
		blood += 1000;
	}
	return true;
	//���⻹��Ҫ����Ѫ��
}

//����ֵ����ʱ�����Ķ��⿪������ߴ���ִ��Ч��
//�ؼ���struct �ṹ��(Ӣ�۵�״̬){};
struct _heroic_state {//�ṹ��
	int blood;//Ѫ��
	int attack_power;//������
	int level;//����
	char name[64];//����
	char state_description[1024];//״̬����
};

//��Ӣ�������ķ���:�汾1,��һ������ʱ��9s
//�����ṹ�� ��Ϊupgrade1�ķ���(����ṹ��Ĳ��� ��Ϊhero�β�,���Ͳ���)
struct _heroic_state upgrade1(struct _heroic_state hero, int type) {
	switch (type) {
	case 1://������
		hero.blood += 1000;//Ѫ��+=1000
		hero.attack_power += 200;//������+=200
		hero.level++;//�ȼ�++
		break;
	case 2://������
		hero.blood += 2000;//Ѫ��+=2000
		hero.attack_power += 50;//������+=50
		hero.level++;//�ȼ�++
		break;
	default:
		break;
	}
	return (hero);
}

//��Ӣ�������ķ���:�汾2,��ָ��ʵ������,��2������ʱ��
//�����ṹ�� ��Ϊupgrade2�ķ���(����ṹ��Ĳ��� ��Ϊhero�β�,���Ͳ���)
void upgrade2(struct _heroic_state *hero, int type) {
	switch (type) {
	case 1://������
		hero->blood += 1000;//Ѫ��+=1000
		hero->attack_power += 200;//������+=200
		hero->level++;//�ȼ�++
		break;
	case 2://������
		hero->blood += 2000;//Ѫ��+=2000
		hero->attack_power += 50;//������+=50
		hero->level++;//�ȼ�++
		break;
	default:
		break;
	}
}

int main(void) {
	/*
	int zwc = 1000;//����Ӣ��,Ѫ��1000
	zwc=add_blood0(zwc);
	cout << "zwc's blood:"<<zwc << endl;
	*/

	time_t start, end;//����ʱ��� ��ʼ,����;

	struct _heroic_state zwc;//����һ��zwc��Ӣ��

	//���ýṹ���е�name����,���ַ������ƹ�ȥ,�ṹ����name[64]="zwc"
	//strpy();�ַ������ƺ���
	strcpy(zwc.name, "zwc");//ʹ���ַ�������,��Ӣ������ȡ��zwc

	zwc.blood = 1000;//Ӣ�۳�ʼѪ��
	zwc.level = 100;//Ӣ�۳�ʼ�ȼ�100��
	zwc.attack_power = 1000;//Ӣ�۳�ʼ����1000

	time(&start);//1970��1��1��0ʱ0��0�뵽���������
	//���ýṹ��upgrade1�ķ���,�Ѳ������ݹ�ȥ
	for (int i = 0; i < 100000000; i++) {
		//zwc = upgrade1(zwc, 1);//zwc(������������ǽṹ��)=upgrade1.���ص�ֵ
		upgrade2(&zwc, 1);//��zwc��ַ�ŵ�ָ��
	}
	time(&end);

	cout << "zwc's blood:" << zwc.blood << endl;
	cout << "zwc's level:" << zwc.level << endl;
	cout << "zwc's attack_power:" << zwc.attack_power << endl;
	cout << "��ʱ:" << end-start << endl;


	system("pause");
	return 0;
}