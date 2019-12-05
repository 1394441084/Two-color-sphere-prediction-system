#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

/*
实现一个函数，函数完成如下功能：
1.函数的输入为一个数组，数组的成员个数不定（即：可能为 0 个，也可能为多个） 
2.函数找到成员的最大元素和最小元素，并能让函数的调用者知道最大元素和最小元素 是哪一个
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
	int d = 0;//最大值
	int x = 0;//最小值
	int d1 = 0;//最大元素
	int x1 = 0;//最小元素
	int len = sizeof(j) / sizeof(j[0]);
	if (Find_out_the_bigand_the_small(j,len, d, x,d1,x1)) {
		cout << "最大值:" << d << "  最小值:" << x << endl;
		cout << "最大元素:" << d1+1 << "  最小元素:" << x1+1 << endl;
	}
	else {
		cerr << "数组越界,请检测" << errno << endl;
	}
	
	
	
	system("pause");
	return 0;
}