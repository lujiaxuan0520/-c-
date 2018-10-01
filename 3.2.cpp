#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int prior(char a,char b)
{
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
       return false;
    else
        return true;
}
double yunsuan(char c,double a,double b)
{
    if(c=='+')
        return (double)a+b;
    if(c=='-')
        return (double)a-b;
    if(c=='*')
        return (double)a*b;
    if(c=='/'&&b!=0)
        return (double)a/(double)b;
}
int main()
{
    stack<char> cstack;
    stack<double> istack;
    double itmp;
    char ctmp;
    int newline=1;
    while(cin>>itmp)
    {
        while(scanf("%c",&ctmp)!=EOF)
        {
            if(ctmp==' ')
                continue;
            else
                break;
        }
        if(newline==1&&itmp==0&&ctmp=='\n')
            break;
        newline=0;
        istack.push((double)itmp);
        if(ctmp=='+'||ctmp=='-'||ctmp=='*'||ctmp=='/')
        {
            while(!cstack.empty()&&prior(cstack.top(),ctmp))
            {
                char c=cstack.top();
                cstack.pop();
                double b=istack.top();
                istack.pop();
                double a=istack.top();
                istack.pop();
                double result=yunsuan(c,a,b);
                istack.push(result);
            }
            cstack.push(ctmp);
        }
        else if(ctmp=='\n')
        {

            while(!cstack.empty())
            {
                char c=cstack.top();
                cstack.pop();
                double b=istack.top();
                istack.pop();
                double a=istack.top();
                istack.pop();
                double result=yunsuan(c,a,b);
                istack.push(result);
            }
            double result=istack.top();
            istack.pop();
            printf("%.2f\n",result);
            newline=1;
        }
    }
    return 0;
}
