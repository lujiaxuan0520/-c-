#include<iostream>
#include<algorithm>
using namespace std;
struct edge
{
    int start;
    int end;
    int weight;
    bool operator <(const edge &b) const
    {
        return weight<b.weight;
    }
};
int tree[100];
int findRoot(int x)
{
    if(tree[x]==-1)
        return x;
    int tmp=findRoot(tree[x]);
    tree[x]=tmp;
    return tmp;
}

int main()
{
    int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        edge list[N+1];
        tree[0]=-2;
        list[0].start=-1;list[0].end=-1;list[0].weight=0;
        int res=0;
        for(int i=1;i<=N;i++)
        {
            cin>>list[i].start>>list[i].end>>list[i].weight;
            tree[i]=-1;
        }
        sort(list,list+N+1);
        for(int i=1;i<=N;i++)
        {
            int r_a=findRoot(list[i].start);
            int r_b=findRoot(list[i].end);
            if(r_a!=r_b)
            {
                tree[r_b]=r_a;
                res+=list[i].weight;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
