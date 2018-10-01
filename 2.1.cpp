#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#define N 100

using namespace std;
int main()
{
	int num;
	while (scanf("%d",&num)!=EOF)
	{
		int a[N] = {};
		for (int i = 0; i < num; i++)
		{
			cin >> a[i];
		}
		int temp;
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num-1-i; j++)
			{
				if (a[j] > a[j+1])
				{
					temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");

	}
	return 0;
}