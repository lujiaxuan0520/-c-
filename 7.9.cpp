#include<stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;
struct item
{
    int p;
    int h;
    item(int pp=0,int hh=0)
    {
        p=pp;h=hh;
    }
};
vector<item> items;
unordered_map<int,int> dp;
int main()
{
    int C;
    scanf("%d",&C);
    for(register int ii=0;ii<C;ii++)
    {
        items.clear();
        item temp;
        items.push_back(temp);
        int n,m;
        scanf("%d %d",&n,&m);
        int cnt=0;
        for(register int i=1;i<=m;i++)
        {
            int q=1;
            int p,h,c;
            scanf("%d %d %d",&p,&h,&c);
            while(c>q)
            {
                cnt++;
                item tmp(q*p,q*h);
                items.push_back(tmp);
                c-=q;
                q*=2;
            }
            cnt++;
            item tmp(c*p,c*h);
            items.push_back(tmp);
        }
        for(register int i=0;i<=n;i++)
            dp[i]=0;
        for(register int i=1;i<=cnt;i++)
        {
            for(register int j=n;j>=items[i].p;j--)
            {
                dp[j]=max(dp[j],items[i].h+dp[j-items[i].p]);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
