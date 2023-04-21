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

int main() {
	int* p = (int*)malloc(10 * sizeof(int));
		if (p == NULL) 
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			int i = 0;
			for (i = 0; i < 10; i++)
			{
				*(p + i) = i;
			}
			//使用malloc开辟的40个字节空间
			//假设这里40个字节不能满足我们的使用了
			//希望我们能有60个字节的空间
			//这里我们能够使用realloc来调整动态开辟的内存
			//
			// realloc注意事项
			// 1.如果使用p指向的空间之后有足够的内存空间可以追加，则直接追加然后返回p
			// 2.如果使用p指向的空间之后没有足够的内存空间可以追加，则reallco函数则会重新找一个新的内存区域
			// 开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放掉旧的内存空间
			// 最后返回新开辟的内存空间的地址
			// 3.得用一个新的变量来接受realloc的返回值
			//
			int* ptr = (int*)realloc(p, 60);
			if (ptr != NULL)
			{
				ptr = p;
				int i = 0;
				for (i = 10; i < 15; i++)
				{
					*(p + i) = i;
				}
				for (i = 0; i < 15; i++)
				{
					printf("%d ", *(p + i));
				}
			}
		}
		free(p);
		p == NULL;
	return 0;
}
//int main() {
//
//	int* p = malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 1; i < 5; i++)
//		{
//			*p++ = i;
//		}
//	}
//	
//	//free(p);---这是不允许的，因为p的位置已经变化了，free不能释放动态内存开辟的空间的一部分
//	//p = NULL;
//
//
//	return 0;
//
//} 

void GetMemory(char **p)
{
	*p = (char*)malloc(100);
}

void test(void) 
{
	char* ptr = NULL;
	GetMemory(&ptr);
	strcpy(ptr, "hello,world");
	printf(ptr);

	free(ptr);
	ptr = NULL;
}

int main() {
	test();
	return 0;
}
