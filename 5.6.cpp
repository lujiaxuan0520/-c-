#include<stdio.h>
using namespace std;
struct Node
{
    int distance;
    int cost;
};
Node edge[1001][1001];
int dist[1001];
int cost[1001];
int S[1001];

int main()
{
    int n,m;
    int inf=9999999;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            dist[i]=inf;
            cost[i]=inf;
            S[i]=0;
            for(int j=1;j<=n;j++)
            {
                edge[i][j].distance=inf;
                edge[i][j].cost=inf;
            }
        }
        for(int i=0;i<m;i++)
        {
            int a,b,d,p;
            scanf("%d%d%d%d",&a,&b,&d,&p);
            edge[a][b].distance=d;
            edge[a][b].cost=p;
            edge[b][a].distance=d;
            edge[b][a].cost=p;
        }
        int s,t;
        scanf("%d%d",&s,&t);
        dist[s]=0;
        S[s]=1;
        cost[s]=0;
        int newp=s;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(edge[newp][j].distance>=inf || S[j]==1)
                    continue;
                if(dist[newp]+edge[newp][j].distance<dist[j])
                {
                    dist[j]=dist[newp]+edge[newp][j].distance;
                    cost[j]=cost[newp]+edge[newp][j].cost;
                    continue;
                }
                if((dist[newp]+edge[newp][j].distance==dist[j])&&(cost[newp]+edge[newp][j].cost<cost[j]))
                {
                    cost[j]=cost[newp]+edge[newp][j].cost;
                    continue;
                }
            }
            int min_dist=inf;
            int min_cost=inf;
            int min_index=-1;
            for(int j=1;j<=n;j++)
            {

                if(S[j]==1)
                    continue;
                if(edge[newp][j].distance>=inf)
                    continue;
                if(dist[j]<min_dist || (dist[j]==min_dist && cost[j]<min_cost))
                {
                    min_index=j;
                }
            }
            S[min_index]=1;
            newp=min_index;
        }
        printf("%d %d\n",dist[t],cost[t]);

    }
    return 0;
}
