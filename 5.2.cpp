#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int index=-1;
    int count=1;
};

node _list[10000001];

int findRoot(int x)
{
    if(_list[x].index==-1)
        return x;
    else
    {
        int tmp=findRoot(_list[x].index);
        _list[x].index=tmp;
        return tmp;
    }
}

void merge(int a,int b)
{
    int root_a=findRoot(a);
    int root_b=findRoot(b);
    _list[root_b].index=root_a;
    _list[root_a].count+=_list[root_b].count;
    _list[root_b].count=1;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<10000001;i++)
        {
            _list[i].index=-1;
            _list[i].count=1;
        }
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        int maxcount=0;
        for(int i=0;i<10000001;i++)
        {
            if(_list[i].index==-1)
            {
                if(_list[i].count>maxcount)
                    maxcount=_list[i].count;
            }
        }
        printf("%d\n",maxcount);

    }
    return 0;
}
