#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    if(x==0&&y==0)
        return 0;
    else if(x==0)
        return y;
    else if(y==0)
        return x;
    else
        return gcd(y,x%y);
}

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        printf("%d\n",gcd(x,y));
    }
    return 0;
}
