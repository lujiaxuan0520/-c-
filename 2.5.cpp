#include<iostream>
#include<stdio.h>
using namespace std;
int score[101]={0};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=0;i<101;i++)
        {
            score[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            score[num]++;
        }
        int d;
        cin>>d;
        cout<<score[d]<<endl;
    }
    return 0;
}
