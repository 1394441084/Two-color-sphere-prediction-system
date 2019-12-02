#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

#define NUM 7 
#define LEN 33

using namespace std;

/*
现在要求我们编写程序找出最近一段时间每个号码出现的次数,
并把结果保存到一个数组,供其它分析模块调用
往期数据保存在一一个名为ball.txt 中:
*/

//统计(文件名,文件里数值保存进来)
bool Statistics(const char* path, int ball_16[LEN],int len){
	int result[NUM];//结果
	ifstream file;//文件变量
	int i = 0;//循环变量

	if (!path) {//判断是否空指针
		cout << "path is NULL\n";
		return false;
	}

	file.open(path);//打开文件
	if (file.fail()) {//判断文件是否打开错误,错误就执行
		//strerror(errno出错代号)是打印出错原因的
		cerr << "打开文件出错."<< errno <<endl;
		return false;
	}

	//从数据文件读取到数组,每行必须读取7个
	do {
		i=0;
		for (i = 0; i < NUM; i++) {
			file>>result[i];//将文件数据输入到result[]数组中
			/*
			if (file.eof()) {//读取到文件尾部了就跳出循环
				break;
			}
			*/
			if (file.fail()) {//出现文件丢失,磁盘损坏等其它异常,就退出循环
				cerr << "读取文件失败,原因:" << errno << endl;//打印出错原因

				break;
			}
		}

		if (i == 0) { break; }//记录正常结束
		//如果到没有NUM个数值
		if (i < NUM) {
			cerr << "仅读到" << i << "个记录,预期读7个\n";
			file.close();//文件关闭
			return false;
			break;
		}

		for (i = 0; i < NUM; i++) {
			cout << " " << result[i];
		}
		cout <<"\n";//将读取的数据打印出来

		if (file.eof()) {//读取到文件尾部了就跳出循环
			break;//跳出do{}while();循环
		}
		//对读入的数据进行统计
		for (i = 0; i < NUM-1; i++) {
			int Ball = *(result + i) - 1;//1球=>0,33球=>32
			//*result=result[0];*(result+i)=result[0+i]
			//cout << "*(result + i) - 1=" << *result  << endl;
			if (Ball >= 0 && Ball <len) {//合法性检测,不能让数组越界
				//*(ball_16 + Ball)=ball_16[0+Ball]
				//把出现的球移到ball_16数组的下标里,33移到32,
				//出现一次+1,ball_16[32]+=1;这样实现号码出现次数统计
				(*(ball_16 + Ball))++;
			}
		}
	} while (1);
	cout << "-----------分割线------------\n";
	file.close();//文件关闭
	return true;
}




int main(void) {
	string filename;//定义一个字符串
	int ball_16[LEN] = { 0 };//这是存放数据的数组
	cout << "请输入文件名:\n";
	cin >> filename;

	//Statistics(把字符串复制到这里,提取函数里保存文件的数据)
	if (Statistics(filename.c_str(), ball_16, LEN)) {
		for (int i = 0; i < LEN; i++) {
			cout << "第" << i + 1 << "球出现次数:" << ball_16[i] << endl;
		}
		cout << "统计成功\n";
	}
	else {//统计失败
		cout << "统计失败\n";
	}

	system("pause");
	return 0;
}
