#include<stdio.h>
int time[1001];
int value[101];
int dp[101][1001];

int main()
{
    int T,M;
    while(scanf("%d %d",&T,&M)==2)
    {
        for(int i=1;i<=M;i++)
        {
            scanf("%d %d",&time[i],&value[i]);
        }
        for(int i=0;i<=T;i++)
            dp[0][i]=0;
        for(int i=0;i<=M;i++)
            dp[i][0]=0;
        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=T;j++)
            {
                if(time[i]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    int tmp1=dp[i-1][j-time[i]]+value[i];
                    int tmp2=dp[i-1][j];
                    dp[i][j]=(tmp1>tmp2)?tmp1:tmp2;
                }
            }
        }
        printf("%d\n",dp[M][T]);
    }
    return 0;
}
