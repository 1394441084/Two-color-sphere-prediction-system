#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//ʵ�ֺ��������ַ����ַ�����ת����: ��cba123����С���¡� ת���ɡ�����С����321abc��
int main(void) {
	while (1) {
		string str;
		cout << "�����Ҫ��ת���ַ���:\n";
		cin >> str;

		char* p2 = &str[str.length() - 1];//ָ�����һ���ַ�
		int len = str.length();//����
		for (int i = 0; i < len; i++) {
			if (*p2 < 0 || *p2 > 256) {//�ж��Ƿ�Ϊ�����ַ�
				cout << *(p2 - 1) << *p2;//����1���
				len--;//��Ϊ���������2�ֽ�,���Լ�һ���ֽڳ���
				p2 -= 2;//��Ϊ�������ַ�������2�ֽ�
			}
			else {
				cout << *p2;
				p2--;
			}
		}
		cout << "\n";
		
	}
	system("pause");
	return 0;
}