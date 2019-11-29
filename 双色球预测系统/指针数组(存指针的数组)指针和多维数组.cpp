#include <stdio.h>
#include <stdlib.h>

//选美擂台赛
void Beauty_contest() {

	int girl[4][3] = { {173,158,166},
						{168,155,171},
						{163,164,165},//各个美女身高
						{163,164,172} };
	//int x1,y1, x2,y2;//选美排名
	//int Beauty_pageant[2];[0]冠军,[1]亚军
	int* Beauty_pageant[2];//定义一个有两个元素的指针数组,每个元素都是指针变量

	//各位美女为了能拿到冠军,从而进行了擂台比试,
	//先把一号和二号分别定为冠亚军
	if (girl[0][0] > girl[0][1]) {
		Beauty_pageant[0] = &girl[0][0];//冠军
		Beauty_pageant[1] = &girl[0][1];
	}
	else {
		Beauty_pageant[0] = &girl[0][1];//冠军
		Beauty_pageant[1] = &girl[0][1];
	}

	//这后面的选手不服,开始挑战,先挑亚军再挑冠军,
	//赢则好吃好住,吃成大胖子,输了当个矮子
	for (int i = 2; i < (sizeof(girl) / sizeof(girl[0][0])); i++) {
		//取整4/3=1;5/3=1;6/3=2;取余3%3=0;4%3=1;5%3=2;6%3=0;7%3=1;
		//girl[i / 3][i % 3];
		if (*Beauty_pageant[1] >= girl[i / 3][i % 3]) {
			continue;
		}
		//候选者高于亚军.1:低于冠军
		if (girl[i / 3][i % 3] <= *Beauty_pageant[0]) {
			//亚军替换成新候选者
			Beauty_pageant[1] = &girl[i / 3][i % 3];
		}
		else {//2:高于冠军,把冠军踢到亚军位,成为新冠军
			//把亚军的数据更新为前冠军
			Beauty_pageant[1] = Beauty_pageant[0];
			//把冠军数据更新为现在的候选者
			Beauty_pageant[0] = &girl[i / 3][i % 3];
		}

	}
	//printf("%d\n", sizeof(girl) / sizeof(girl[0][0]));
	printf("冠军选手:%d  亚军选手:%d\n", *Beauty_pageant[0], *Beauty_pageant[1]);

}


/*
据同学们报告，A栋学生楼有学生用高倍望眼镜偷看别人洗澡，
宿管办领导决定逐个宿舍排查，得到的线报是A0到A3宿舍的
某个子最矮的男生。
*/
void Find_out_the_bad_students() {
	int A[4][3] = { {173, 158, 166},  //A0宿舍
					 {168,155, 171},  //A1宿舍
					 {163, 164, 165}, //A2宿舍
					 {163, 164, 172}};//A3宿舍
	//因为宿舍之间行程太远,无法一下子排查,所以
	//把一个宿舍的人先叫来办公室比对一下
	//定义一个能指向数组里三个成员的指针
	//数组一行元素,嗯,很好~,这指针就是指向那行
	//(*p)这是指向的行数,[]这是指向数组元素的指针元素
	int (*p)[3];//定义了一个指向三个成员的数组的指针

	p = &A[0];

	int* short_boy = NULL;
	short_boy = &(*p)[0];
	//short_boy = *p;
	
	//用数组下标法访问办公室
	/*
	for (int i = 0; i < 4; i++) {
		//p = &A[i];
		for (int j = 0; j < 3; j++) {
			printf(" %d", (*p)[j]);//*p==A[0];A[0][0]==(*p)[0];直观吧
		}
		p++;//哎呦神奇.这能很好的让别人看不懂
		printf("\n");
	}
	*/

	//用指针访问法(访问办公室)
	for (int i = 0; i < 4; i++) {
		//p = &A[i];
		for (int j = 0; j < 3; j++) {
			//*((*p)+j)=A[0][0]+j=A[][]前进j位;看不懂吧,反正我是知道意思了
			//就像访问a[]={0,1,2,3,4,5,6,7,8,9,10,11};这样
			printf(" %d", *((*p)+j));//*p==A[0];A[0][0]==(*p)[0];直观吧
			if (*short_boy > * (*p) + j) {
				short_boy = (*p) + j;//啊哈,知道这矮个子在哪张床了
			}
		}
		p++;//哎呦神奇.这能很好的让别人看不懂
		printf("\n");
	}
	printf("偷窥学生的是:%d", *short_boy);

}

int main(void) {
	
	Find_out_the_bad_students();
	system("pause");
	return 0;
}