#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int a_i[9]={0},a_size=0;
        int b_i[9]={0},b_size=0;
        for(int i=8;i>=0;i--)
        {
            if(a!=0) a_size++;
            else break;
            a_i[i]=a%10;
            a=a/10;
        }
        for(int i=a_size-1;i>=0;i--)
        {
            if(b!=0) b_size++;
            else break;
            b_i[i]=b%10;
            b=b/10;
        }
        int sum=0;
        for(int i=b_size-1;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                sum+=a_i[i]*b_i[j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
