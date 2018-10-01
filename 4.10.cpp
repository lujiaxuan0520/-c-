#include<iostream>
#include<math.h>
using namespace std;
int Pow(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2==0)
    {
        long long re=Pow(a,b/2)*Pow(a,b/2);
        return re%1000;
    }
    else
    {
        long long re=a*Pow(a,b-1);
        return re%1000;
    }
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        int ans=Pow(a,b);
        cout<<ans<<endl;
    }
    return 0;
}
