#include<stdio.h>
#include<math.h>
bool IsPrime(int n)
{
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(IsPrime(a))
            printf("%s\n","yes");
        else
            printf("%s\n","no");
    }
    return 0;
}
