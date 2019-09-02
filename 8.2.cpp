#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int in[1000];
int out[1000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        map<string,int> M;
        int cur=0;
        for(register int i=0;i<n;i++)
        {
            char ca[100];
            char cb[100];
            scanf("%s %s\n",&ca,&cb);
            string a=ca;
            string b=cb;
            if(M.find(a)==M.end())
            {
                M[a]=cur;
                cur++;
            }
            if(M.find(b)==M.end())
            {
                M[b]=cur;
                cur++;
            }
            out[M[a]]++;
            in[M[b]]++;
        }
        int _count=0;
        for(register int i=0;i<cur;i++)
        {
            if(in[i]==0 && out[i]!=0)
                _count++;
        }
        if(_count==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
