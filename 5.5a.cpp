#include<iostream>
#include<vector>
using namespace std;
struct edge
{
    int next;
    int weight;
};

int main()
{
    int n,m;
    const int inf=9999;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        int dist[n+1]={9999};
        int set[n+1]={0};
        for(int j=1;j<=n;j++)
        {
            dist[j]=9999;
            set[j]=0;
        }
        dist[1]=0;
        set[1]=1;
        vector<edge> list[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edge tmp;tmp.weight=c;
            tmp.next=b;
            list[a].push_back(tmp);
            tmp.next=a;
            list[b].push_back(tmp);
        }
        int newp=1;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<list[newp].size();j++)
            {
                int t=list[newp][j].next;
                if(((dist[newp]+list[newp][j].weight)<dist[t])&&(set[t]==0))
                {

                    dist[t]=dist[newp]+list[newp][j].weight;
                }

            }
            int min_weight=9999;
            int min_index=-1;
            for(int j=1;j<=n;j++)
            {
                if((set[j]==0)&&(dist[j]<min_weight))
                {

                    min_weight=dist[j];
                    min_index=j;
                }
            }
            set[min_index]=1;
            newp=min_index;
        }
        cout<<dist[n]<<endl;
    }
    return 0;
}
