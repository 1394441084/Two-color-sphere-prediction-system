#include <iostream>
#include <Windows.h>
#include <time.h>//time();函数,获取当前系统时间
//#include <stdlib.h>
#pragma warning(disable:4996)//为解决strpy();字符串复制函数所增加的预处理

using namespace std;

/*
				   为什么要使用指针
   1.函数的值传递， 无法通过调用函数，来修改函数的实参
   2.被调用函数需要提供更多 的“返回值"给调用函数
   3.减少值传递时带来的额外开销，提高代码执行效率
*/

//加血函数,函数的值传递， 无法通过调用函数，来修改函数的实参
int add_blood0(int blood) {
	blood += 1000;//血量
	return blood;
}

//被调用函数需要提供更多 的“返回值"给调用函数
bool add_blood1(int blood) {
	if (blood > 1000) {
		return false;
	}
	else {
		blood += 1000;
	}
	return true;
	//另外还需要返回血量
}

//减少值传递时带来的额外开销，提高代码执行效率
//关键词struct 结构名(英雄的状态){};
struct _heroic_state {//结构体
	int blood;//血量
	int attack_power;//攻击力
	int level;//级别
	char name[64];//名字
	char state_description[1024];//状态描述
};

//让英雄升级的方法:版本1,第一版所用时间9s
//声明结构体 名为upgrade1的方法(定义结构体的参数 名为hero形参,类型参数)
struct _heroic_state upgrade1(struct _heroic_state hero, int type) {
	switch (type) {
	case 1://攻击型
		hero.blood += 1000;//血量+=1000
		hero.attack_power += 200;//攻击力+=200
		hero.level++;//等级++
		break;
	case 2://防御型
		hero.blood += 2000;//血量+=2000
		hero.attack_power += 50;//攻击力+=50
		hero.level++;//等级++
		break;
	default:
		break;
	}
	return (hero);
}

//让英雄升级的方法:版本2,用指针实现升级,第2版所用时间
//声明结构体 名为upgrade2的方法(定义结构体的参数 名为hero形参,类型参数)
void upgrade2(struct _heroic_state *hero, int type) {
	switch (type) {
	case 1://攻击型
		hero->blood += 1000;//血量+=1000
		hero->attack_power += 200;//攻击力+=200
		hero->level++;//等级++
		break;
	case 2://防御型
		hero->blood += 2000;//血量+=2000
		hero->attack_power += 50;//攻击力+=50
		hero->level++;//等级++
		break;
	default:
		break;
	}
}

int main(void) {
	/*
	int zwc = 1000;//定义英雄,血量1000
	zwc=add_blood0(zwc);
	cout << "zwc's blood:"<<zwc << endl;
	*/

	time_t start, end;//定义时间初 开始,结束;

	struct _heroic_state zwc;//声明一个zwc的英雄

	//调用结构体中的name变量,把字符串复制过去,结构体中name[64]="zwc"
	//strpy();字符串复制函数
	strcpy(zwc.name, "zwc");//使用字符串复制,把英雄名字取作zwc

	zwc.blood = 1000;//英雄初始血量
	zwc.level = 100;//英雄初始等级100级
	zwc.attack_power = 1000;//英雄初始攻击1000

	time(&start);//1970年1月1日0时0分0秒到至今的秒数
	//调用结构体upgrade1的方法,把参数传递过去
	for (int i = 0; i < 100000000; i++) {
		//zwc = upgrade1(zwc, 1);//zwc(现在所代表的是结构体)=upgrade1.返回的值
		upgrade2(&zwc, 1);//把zwc地址放到指针
	}
	time(&end);

	cout << "zwc's blood:" << zwc.blood << endl;
	cout << "zwc's level:" << zwc.level << endl;
	cout << "zwc's attack_power:" << zwc.attack_power << endl;
	cout << "用时:" << end-start << endl;


	system("pause");
	return 0;
}