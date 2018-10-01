#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    char b,a;
    while(cin>>n>>b>>a)
    {
        char l[n][n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                l[i][j]=' ';
            }
        }
        for(int j=1;j<n-1;j++)
        {
            l[0][j]=a;
            l[n-1][j]=a;
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=0;j<=n-1;j+=2)
            {
                l[i][j]=a;
            }
            for(int j=1;j<n-1;j+=2)
            {
                l[i][j]=b;
            }
        }
        for(int i=1;i<=n/2-1;i++)
        {
            for(int j=n/2-i;j<=n-1-(n/2-i);j++)
            {
                if(i%2==0)
                {
                    l[n/2-i][j]=b;
                    l[n/2+i][j]=b;
                }
                else
                {
                    l[n/2-i][j]=a;
                    l[n/2+i][j]=a;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",l[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
