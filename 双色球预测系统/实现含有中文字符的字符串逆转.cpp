#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//实现含有中文字符的字符串逆转，如: “cba123我是小萌新” 转换成“新萌小是我321abc”
int main(void) {
	while (1) {
		string str;
		cout << "请输出要逆转的字符串:\n";
		cin >> str;

		char* p2 = &str[str.length() - 1];//指向最后一个字符
		int len = str.length();//长度
		for (int i = 0; i < len; i++) {
			if (*p2 < 0 || *p2 > 256) {//判断是否为中文字符
				cout << *(p2 - 1) << *p2;//是退1输出
				len--;//因为上面输出了2字节,所以减一个字节长度
				p2 -= 2;//因为是中文字符所以退2字节
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