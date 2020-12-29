#include <stdio.h>
#include <stdlib.h>
#include <time.h>//为了让随机数的种子产生变化
#define NUM 1000

//求任意长度数组中出现次数最多的值
void main03()
{
	int number[NUM];
	srand(time(0));//播种
	for (int i = 0; i < NUM; i++)
	{
		number[i] = rand() % 1001;//产生值为0~1000的随机数
	}
	for (int i = 0; i < NUM; i++)//遍历数组元素
	{
		printf("%d\t", number[i]);//奇怪，为什么会有负数？？？
	}
	system("pause");
}