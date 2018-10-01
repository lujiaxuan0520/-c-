#include<iostream>
#include<stdio.h>
#define N 500000
using namespace std;
int a[1000001]={0};
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<1000001;i++)
        {
            a[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            a[num+N]++;
        }
        int count=0;
        for(int i=1000000;i>=0;i--)
        {
            if(a[i]>0&&count<=m)
            {
                cout<<i-N<<" ";
                count++;
                a[i]--;
                i++;
            }
            if(count>=m) break;
        }
        cout<<endl;
    }
    return 0;
}
