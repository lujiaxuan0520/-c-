#include<stdio.h>
#include<iostream>
using namespace std;
int buffer[10000]={0};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        buffer[2]=1;
        for(int i=2;i<n;i++)
        {
            buffer[i]=1;
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(buffer[i]==1)
            {
                if(i%10==1)
                {
                    cout<<i<<" ";
                    count++;
                }
                int tmp=2;
                while(tmp*i<=n)
                {
                    buffer[tmp*i]=0;
                    tmp++;
                }
            }
        }
        if(count==0) cout<<-1<<endl;
        else cout<<endl;
    }
    return 0;
}
