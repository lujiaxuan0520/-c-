#include<stdio.h>
int Tree[1001];
int findRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==0)
        {
            printf("%d",n==0?0:n-1);
            return 0;
        }
        for(int i=1;i<=n;i++)
            Tree[i]=-1;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int aRoot=findRoot(a);
            int bRoot=findRoot(b);
            if(a!=b)
                Tree[bRoot]=aRoot;
        }
        int count=0;
        for(int i=1;i<=n;i++)
            if(Tree[i]==-1)
                count++;
        printf("%d\n",count==0?0:count-1);
    }
    return 0;
}
