#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Ϊ��������������Ӳ����仯
#define NUM 1000

//�����ⳤ�������г��ִ�������ֵ
void main03()
{
	int number[NUM];
	srand(time(0));//����
	for (int i = 0; i < NUM; i++)
	{
		number[i] = rand() % 1001;//����ֵΪ0~1000�������
	}
	for (int i = 0; i < NUM; i++)//��������Ԫ��
	{
		printf("%d\t", number[i]);//��֣�Ϊʲô���и���������
	}
	system("pause");
}