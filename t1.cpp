#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> S;
    S.insert(1);
    S.insert(2);
    set<int>::iterator iter=S.find(2);
    int count=0;
    for(set<int>::iterator it=S.begin();it!=iter;it++)
        count++;
    cout<<count;
    return 0;
}
