#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int wife = 24;
	int girl = 18;

	//第一种 渣男型
	int* zha_nan = &wife;
	*zha_nan = 25;
	zha_nan = &girl;
	*zha_nan = 19;
	printf("wife:%d  girl:%d\n", wife, girl);

	//第二种 直男型
	//const int* zhi_nan = &wife;
	int const *zhi_nan = &wife;
	//*zhi_nan = 26;他老婆不喜欢直男,不让他修改
	printf("直男老婆的年龄:%d\n", *zhi_nan);
	if (wife != 24) { printf("咦,有顶绿帽子\n"); }
	zhi_nan = &girl;
	printf("直男情人的年龄:%d\n", *zhi_nan);
	if (girl != 18) { printf("女朋友送我的帽子,我很喜欢.\n"); }

	//第三种 暖男型
	int* const nuan_nan = &wife;
	*nuan_nan = 26;
	//nuan_nan = &girl;//不允许指向别的地址
	printf("暖男老婆年龄:%d\n", *nuan_nan);
	
	//第四种 超级暖男型
	const int* const super_nuan_nan = &wife;
	//super_nuan_nan = &girl;//不能指向别的女孩(地址)
	//*super_nuan_nan = 27;//一切以老婆为主,不能修改老婆



	system("pause");
	return 0;
}