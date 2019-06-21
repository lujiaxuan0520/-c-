#include<stdio.h>
#include<queue>
using namespace std;
struct Node
{
    int a=0,b=0,c=0;
    int t=0;
};
int edge[50][50][50];
bool mark[50][50][50];
int main()
{
    int K;
    int A,B,C,T;
    scanf("%d",&K);
    for(int q=0;q<K;q++)
    {
        scanf("%d%d%d%d",&A,&B,&C,&T);
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<B;j++)
            {
                for(int k=0;k<C;k++)
                {
                    scanf("%d",&edge[i][j][k]);
                    mark[i][j][k]=false;
                }
            }
        }
        Node first_node;
        first_node.a=0;first_node.b=0;first_node.c=0;first_node.t=0;
        mark[0][0][0]=true;
        queue<Node> Q;
        Q.push(first_node);
        while(!Q.empty())
        {
            Node cur_node=Q.front();
            Q.pop();
            if(cur_node.a==A-1&&cur_node.b==B-1 && cur_node.c==C-1)
            {
                if(cur_node.t<=T)
                    printf("%d\n",cur_node.t);
                else
                    printf("-1\n");
                break;
            }
            if(cur_node.a-1>=0 && cur_node.a-1<=A-1 && mark[cur_node.a-1][cur_node.b][cur_node.c]==false && edge[cur_node.a-1][cur_node.b][cur_node.c]==0)
            {
                mark[cur_node.a-1][cur_node.b][cur_node.c]=true;
                Node new_node;
                new_node.a=cur_node.a-1;new_node.b=cur_node.b;new_node.c=cur_node.c;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
            if(cur_node.a+1>=0 && cur_node.a+1<=A-1 && mark[cur_node.a+1][cur_node.b][cur_node.c]==false && edge[cur_node.a+1][cur_node.b][cur_node.c]==0)
            {
                mark[cur_node.a+1][cur_node.b][cur_node.c]=true;
                Node new_node;
                new_node.a=cur_node.a+1;new_node.b=cur_node.b;new_node.c=cur_node.c;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
            if(cur_node.b-1>=0 && cur_node.b-1<=B-1 && mark[cur_node.a][cur_node.b-1][cur_node.c]==false && edge[cur_node.a][cur_node.b-1][cur_node.c]==0)
            {
                mark[cur_node.a][cur_node.b-1][cur_node.c]=true;
                Node new_node;
                new_node.a=cur_node.a;new_node.b=cur_node.b-1;new_node.c=cur_node.c;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
            if(cur_node.b+1>=0 && cur_node.b+1<=B-1 && mark[cur_node.a][cur_node.b+1][cur_node.c]==false && edge[cur_node.a][cur_node.b+1][cur_node.c]==0)
            {
                mark[cur_node.a][cur_node.b+1][cur_node.c]=true;
                Node new_node;
                new_node.a=cur_node.a;new_node.b=cur_node.b+1;new_node.c=cur_node.c;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
            if(cur_node.c-1>=0 && cur_node.c-1<=C-1 && mark[cur_node.a][cur_node.b][cur_node.c-1]==false && edge[cur_node.a][cur_node.b][cur_node.c-1]==0)
            {
                mark[cur_node.a][cur_node.b][cur_node.c-1]=true;
                Node new_node;
                new_node.a=cur_node.a;new_node.b=cur_node.b;new_node.c=cur_node.c-1;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
            if(cur_node.c+1>=0 && cur_node.c+1<=C-1 && mark[cur_node.a][cur_node.b][cur_node.c+1]==false && edge[cur_node.a][cur_node.b][cur_node.c+1]==0)
            {
                mark[cur_node.a][cur_node.b][cur_node.c+1]=true;
                Node new_node;
                new_node.a=cur_node.a;new_node.b=cur_node.b;new_node.c=cur_node.c+1;new_node.t=cur_node.t+1;
                Q.push(new_node);
            }
        }

    }
    return 0;
}
