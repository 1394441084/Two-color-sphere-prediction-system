#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

/*
ʵ��һ������������������¹��ܣ�
1.����������Ϊһ�����飬����ĳ�Ա������������������Ϊ 0 ����Ҳ����Ϊ����� 
2.�����ҵ���Ա�����Ԫ�غ���СԪ�أ������ú����ĵ�����֪�����Ԫ�غ���СԪ�� ����һ��
*/
bool Find_out_the_bigand_the_small(int j[],int len,int &d,int &x,int &d1,int &x1) {

	if (len < 0) {
		return false;
	}

	d = j[0];
	x = j[0];

	if (len == 0) {
		return true;
	}
     
	 for (int i = 1; i < len; i++) {
		 if (d < j[i]) {
			 d = j[i];
			 d1 = i;
		 }
		 if(x>j[i]){
			 x = j[i];
			 x1 = i;
		 }
	 }
	 return true;
}

int main(void) {
    int j[] = {555,9,156,4598,548,1564,1253,21,1,3,5,4,7,89,9};
	int d = 0;//���ֵ
	int x = 0;//��Сֵ
	int d1 = 0;//���Ԫ��
	int x1 = 0;//��СԪ��
	int len = sizeof(j) / sizeof(j[0]);
	if (Find_out_the_bigand_the_small(j,len, d, x,d1,x1)) {
		cout << "���ֵ:" << d << "  ��Сֵ:" << x << endl;
		cout << "���Ԫ��:" << d1+1 << "  ��СԪ��:" << x1+1 << endl;
	}
	else {
		cerr << "����Խ��,����" << errno << endl;
	}
	
	
	
	system("pause");
	return 0;
}