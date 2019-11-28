#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//空指针示例说明
//开两房让妹子过来
//VS2019搞不了坏指针,也就是没有初始值的指针
void Get_two_roomsand_get_the_girl_over_here() {
	int room1 = 666;
	int room2 = 888;
	int girl = 0;
	//钥匙
	//int* keys=0;//空指针NULL
	//空指针如果不用了,可以重置为空指针,以免调用时,把上次的值传递过来了
	int* keys = NULL;
	printf("您要去房间是:");
	scanf_s("%d",&girl);

	if (girl == 666) {
		keys = &room1;
	}
	else if (girl == 888) {
		keys = &room2;
	}
	if (keys == 0) {
		printf("客人真不好意思,所有房间都被定了.\n");
	}else{
		printf("选择的房间是:%d\n", *keys);
	}
	
}

//指针自增操作
void Pointer_self_increment() {
	int age[] = {21,15,18,14,23,28,10};
	int subscript = sizeof(age)/sizeof(age[0]);
	for (int i = 0; i < subscript; i++) {
		printf("第%d个学员年龄:%d\n", i+1, age[i]);
	}
	//打印数组的地址和第一个成员的地址
	printf("age数组的地址:Ox%p ,第一个元素的地址:Ox%p ,", age, &age[0]);
	printf("第二个元素的地址:Ox%p\n", &age[1]);//数组地址和第一元素地址是一样的

	int* p = age;
	//访问第一个元素
	printf("第一个元素的地址:%d\n", *p);
	p += 1;//编译器优化默认:p=p+1*sizeof(int),从而不用p+=4;
	printf("第二个元素的地址:%p\n", p);
	printf("第二个元素的地址:%d\n", *p);

	int* p1 = age;
	//指针遍历数组
	for (int i = 0; i < subscript; i++) {
		printf("第%d个元素的地址:%d  地址:Ox%p\n",i+1, *p1,p1);
		p1++;
	}

	printf("-------------分割线--------------\n");

	char ch[4] = {'a','b','c','d'};
	char* ch1 = ch;
	for (int i = 0; i < sizeof(ch); i++) {
		printf("第%d个元素的地址:%c  地址:Ox%p\n", i + 1, *ch1, ch1);
		ch1++;//编译器优化默认:ch1=ch1+1*sizeof(char);
	}
	//总结:指针++的概念是在指针当前地址上增加指针类型

}

//指针自减操作
//输入字符串,不能改变原字符串,进行逆转输出
void Pointer_self_subtraction() {
	char str[128];
	printf("请输入您需要逆转的字符串:\n");
	scanf_s("%s", &str, sizeof(str));
	int len = strlen(str);//获取当前字符串的长度

	//逆转字符串方法1
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
	printf("逆转后:%s\n", str);
	*/

	//逆转字符串方法2
	/*
	for (int i = 0; i < len; i++) {
		printf("%c", str[len - 1 - i]);
	}
	*/

	//逆转字符串方法3
	/*
	for(int i =len-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	*/

	//逆转字符串方法4,用指针自减实现
	char* s = &str[len - 1];//取str数组最后一个元素的地址
	for (int i = 0; i < len; i++) {
		printf("%c", *s--);
		//s--;
	}

	printf("\n");
}

/*
(1)使用“指针-指针”的方式计算整数数组元素的偏移值;
(2)使用“指针-指针”的方式计算字符串元素的偏移值;
(3)指针与指针没有加法
(4)指针-指针,适用场景:指向同一数组.得到的结果为两指针之间的元素数目
*/
void Operation() {
	int ages[] = {20,18,19,24,23,28,30,38,35,32};
	int ages1[] = {18,19,20,22};
	int len = sizeof(ages) / sizeof(ages[0]);
	int* martin = ages + 6;//30
	int* rock = ages + 9;//32
	printf("martin = %d\n",*martin);
	printf("rock - martin = %d\n",(rock-martin)) ;
	//两指针指向同数组,相减的结果为两指针之间的元素数目,而不是两指针之间相差的字节
	//当然*(类型),就能得出两指针相差字节
	printf("martin - rock = %d\n",(martin-rock)) ;

	martin = ages + 6;//指针指向不同数组得减法没有意义
	rock = ages1 + 3;//地址相减再除与类型才得出结果
	//结果=-9,地址相减得24,就转换为2*16+4=36,36/4(类型字节)=9.
	printf("martin地址:%p  rock地址:%p  rock-martin=%d\n", martin, rock, rock - martin);
}



int main(void) {
	Operation();
	system("pause");
	return 0;
}