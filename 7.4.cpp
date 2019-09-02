#include<stdio.h>
#include<string>
#include<iostream>
int dp[101][101];
using namespace std;
int main()
{
    string x,y;
    cin>>x>>y;
    for(int i=0;i<=y.size();i++)
        dp[0][i]=0;
    for(int i=0;i<x.size();i++)
        dp[i][0]=0;
    for(int i=1;i<=x.size();i++)
    {
        for(int j=1;j<=y.size();j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                int tmp_a=dp[i-1][j];
                int tmp_b=dp[i][j-1];
                dp[i][j]=(tmp_a>tmp_b)?tmp_a:tmp_b;
            }
        }
    }
    cout<<dp[x.size()][y.size()];
    return 0;
}
