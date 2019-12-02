#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

#define NUM 7 
#define LEN 33

using namespace std;

/*
����Ҫ�����Ǳ�д�����ҳ����һ��ʱ��ÿ��������ֵĴ���,
���ѽ�����浽һ������,����������ģ�����
�������ݱ�����һһ����Ϊball.txt ��:
*/

//ͳ��(�ļ���,�ļ�����ֵ�������)
bool Statistics(const char* path, int ball_16[LEN],int len){
	int result[NUM];//���
	ifstream file;//�ļ�����
	int i = 0;//ѭ������

	if (!path) {//�ж��Ƿ��ָ��
		cout << "path is NULL\n";
		return false;
	}

	file.open(path);//���ļ�
	if (file.fail()) {//�ж��ļ��Ƿ�򿪴���,�����ִ��
		//strerror(errno�������)�Ǵ�ӡ����ԭ���
		cerr << "���ļ�����."<< errno <<endl;
		return false;
	}

	//�������ļ���ȡ������,ÿ�б����ȡ7��
	do {
		i=0;
		for (i = 0; i < NUM; i++) {
			file>>result[i];//���ļ��������뵽result[]������
			/*
			if (file.eof()) {//��ȡ���ļ�β���˾�����ѭ��
				break;
			}
			*/
			if (file.fail()) {//�����ļ���ʧ,�����𻵵������쳣,���˳�ѭ��
				cerr << "��ȡ�ļ�ʧ��,ԭ��:" << errno << endl;//��ӡ����ԭ��

				break;
			}
		}

		if (i == 0) { break; }//��¼��������
		//�����û��NUM����ֵ
		if (i < NUM) {
			cerr << "������" << i << "����¼,Ԥ�ڶ�7��\n";
			file.close();//�ļ��ر�
			return false;
			break;
		}

		for (i = 0; i < NUM; i++) {
			cout << " " << result[i];
		}
		cout <<"\n";//����ȡ�����ݴ�ӡ����

		if (file.eof()) {//��ȡ���ļ�β���˾�����ѭ��
			break;//����do{}while();ѭ��
		}
		//�Զ�������ݽ���ͳ��
		for (i = 0; i < NUM-1; i++) {
			int Ball = *(result + i) - 1;//1��=>0,33��=>32
			//*result=result[0];*(result+i)=result[0+i]
			//cout << "*(result + i) - 1=" << *result  << endl;
			if (Ball >= 0 && Ball <len) {//�Ϸ��Լ��,����������Խ��
				//*(ball_16 + Ball)=ball_16[0+Ball]
				//�ѳ��ֵ����Ƶ�ball_16������±���,33�Ƶ�32,
				//����һ��+1,ball_16[32]+=1;����ʵ�ֺ�����ִ���ͳ��
				(*(ball_16 + Ball))++;
			}
		}
	} while (1);
	cout << "-----------�ָ���------------\n";
	file.close();//�ļ��ر�
	return true;
}




int main(void) {
	string filename;//����һ���ַ���
	int ball_16[LEN] = { 0 };//���Ǵ�����ݵ�����
	cout << "�������ļ���:\n";
	cin >> filename;

	//Statistics(���ַ������Ƶ�����,��ȡ�����ﱣ���ļ�������)
	if (Statistics(filename.c_str(), ball_16, LEN)) {
		for (int i = 0; i < LEN; i++) {
			cout << "��" << i + 1 << "����ִ���:" << ball_16[i] << endl;
		}
		cout << "ͳ�Ƴɹ�\n";
	}
	else {//ͳ��ʧ��
		cout << "ͳ��ʧ��\n";
	}

	system("pause");
	return 0;
}
