#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int m;
    long long a,b;
    while(scanf("%d%lld%lld",&m,&a,&b)!=EOF)
    {
        if(m==0) break;
        long long sum=a+b;
        int s[10]={0};
        int i=9;
        while(sum!=0)
        {
            s[i]=sum%m;
            sum=sum/m;
            i--;
        }
        for(int j=i+1;j<10;j++)
        {
            printf("%d",s[j]);
        }
        printf("\n");
    }
    return 0;
}
