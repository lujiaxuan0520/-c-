#include<iostream>
using namespace std;
int main()
{
    int m,n;
    const int inf=99999;
    while(cin>>n>>m)
    {
        if(m==0 && n==0)
            break;
        int edge[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                edge[i][j]=inf;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edge[a][b]=c;
            edge[b][a]=c;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if((edge[i][k]+edge[k][j])<edge[i][j])
                        edge[i][j]=edge[i][k]+edge[k][j];
                }
            }

        }
        cout<<edge[1][n]<<endl;
    }
    return 0;
}
