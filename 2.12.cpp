#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct program
{
    int start;
    int end;
    int mark=0;
    bool operator<(const program& b)
    {
        return end<b.end;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        program list[100];
        for(int i=0;i<n;i++)
        {
            cin>>list[i].start>>list[i].end;
            list[i].mark=0;
        }
        sort(list,list+n);
        int lasttime=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(list[i].start>=lasttime)
            {
                count++;
                list[i].mark=1;
                lasttime=list[i].end;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
