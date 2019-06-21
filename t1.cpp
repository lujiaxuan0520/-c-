#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int N=1000;//需要到多少
    for(int i=1;i<=N;i++)
    {
        if(i%3==1 && i!=1)
            cout<<i<<" "<<i<<" ";
        else
            cout<<i<<" ";
    }
    return 0;
}
