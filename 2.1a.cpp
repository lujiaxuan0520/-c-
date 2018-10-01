#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int temp;
		int a[100] = {};
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n,cmp);
		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		cout<<endl;
	}
	return 0;
}

bool cmp(int x,int y)
{
    return x>y;
}
