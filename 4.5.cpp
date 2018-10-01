#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0&&a==0)
        return 0;
    else if(b==0)
        return a;
    else if(a==0)
        return b;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int mul=a*b;
        printf("%d\n",mul/gcd(a,b));
    }
    return 0;
}
