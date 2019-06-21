#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
vector<int> edge[501];
int InDegree[501];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=0;i<n;i++)
        {
            InDegree[i]=0;
            edge[i].clear();
        }
        queue<int> Q;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            InDegree[y]++;
            edge[x].push_back(y);
        }
        for(int i=0;i<n;i++)
        {
            if(InDegree[i]==0)
                Q.push(i);
        }
        int cnt=0;
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            cnt++;
            for(int i=0;i<edge[x].size();i++)
            {
                int y=edge[x][i];
                InDegree[y]--;
                if(InDegree[y]==0)
                    Q.push(y);
            }
            edge[x].clear();
        }
        if(cnt==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
