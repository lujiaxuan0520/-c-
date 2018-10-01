#include<iostream>
#include<stdio.h>
using namespace std;
int buf[100000]={1};
void init()
{
    for(int i=0;i<100000;i++)
    {
        buf[i]=1;
    }
    for(int i=2;i<100000;i++)
    {
        if(buf[i]==1)
        {
            int tmp=2;
            while(i*tmp<100000)
            {
                buf[tmp*i]=0;
                tmp++;
            }
        }
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        int count=0;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0&&buf[i]==1)
            {
                count++;
                n=n/i;
                i--;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
