#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#include<stdio.h>
#include<algorithm>
#define INF 0x7fffffff
int dp[10001];
using namespace std;
struct coin
{
    int p;
    int w;
};
coin coins[500];
int main()
{
    int T;
    scanf("%d",&T);
    for(register int iii=0;iii<T;++iii)
    {
        int E,F;
        scanf("%d %d",&E,&F);
        int rongliang=F-E;
        dp[0]=0;
        for(register int i=1;i<=rongliang;++i)
        {
            dp[i]=INF;
        }
        int N;
        scanf("%d",&N);
        for(register int i=1;i<=N;i++)
        {
            scanf("%d",&coins[i].p);
            scanf("%d",&coins[i].w);
        }
        for(register int i=1;i<=N;++i)
        {
            for(register int j=coins[i].w;j<=rongliang;++j)
            {
                int a=dp[j];
                int b=dp[j-coins[i].w];
                if(a==INF && b==INF)
                    dp[j]=INF;
                else
                    dp[j]=min(dp[j],coins[i].p+dp[j-coins[i].w]);
            }
        }
        if(dp[rongliang]==INF)
        {
            printf("This is impossible.\n");
        }
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[rongliang]);

    }
    return 0;
}
