#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m==-1&&n==-1) break;
        int F[1000]={0};
        int J[1000]={0};
        double xingjia[1000]={0};
        int used[1000]={0};
        double ai[1000]={0};
        for(int i=0;i<n;i++)
        {
            cin>>J[i]>>F[i];
            xingjia[i]=double(J[i])/double(F[i]);
        }
        double zongliang=0;
        while(zongliang<m)
        {
            int maxIndex=-1;
            double currentMax=0;
            for(int i=0;i<n;i++)
            {
                if(xingjia[i]>currentMax&&used[i]==0)
                {
                    maxIndex=i;
                    currentMax=xingjia[i];
                }
            }
            if(zongliang+F[maxIndex]<=m)
            {
                used[maxIndex]=1;
                zongliang+=F[maxIndex];
                ai[maxIndex]=1;
            }
            else
            {
                double shengyu=m-zongliang;
                used[maxIndex]=1;
                ai[maxIndex]=shengyu/F[maxIndex];
                break;
            }
        }
        double sum=0;
        for(int i=0;i<n;i++)
        {
            if(ai[i]!=0)
                sum+=J[i]*ai[i];
        }
        printf("%.3f\n",sum);

    }
    return 0;
}
