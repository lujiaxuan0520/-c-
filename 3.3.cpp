#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        priority_queue<int,vector<int>,greater<int>> Q;
        while(!Q.empty())
            Q.pop();
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            Q.push(tmp);
        }
        int sum=0;
        while(Q.size()>1)
        {
            int b,a;
            b=Q.top();
            Q.pop();
            a=Q.top();
            Q.pop();
            sum+=a+b;
            Q.push(a+b);
        }
        int tmp=Q.top();
        Q.pop();
        cout<<sum<<endl;
    }
    return 0;
}
