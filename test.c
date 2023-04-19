#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	//向内存（堆区）申请10个整形的空间
	int* p = (int*)malloc(10 * sizeof(int));
	//申请成功返回该空间的地址
	//否则返回空指针
	if (p == NULL) 
	{
		//错误码报错
		printf("%s\n", strerror(errno));
	}
	else
	{
		//正常使用空间
		int i = 0;
		for (i =0;i<10;i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ",*(p+i));
		}

	}
	//当动态申请的空间不再使用时
	//就应该把该空间返回给操作系统
	free(p);
	//即使p把该空间返回给操作系统了，但是通过p指针仍能找到该空间
	//因此需要把该指针写成空指针
	p = NULL;
	return 0;
}
