#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
char s[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int buf[1000];

int main()
{
    int a,b;
    string str;
    while(cin>>a>>str>>b)
    {
        long sum=0;
        int weight=1;
        for(int i=str.size()-1;i>=0;i--)
        {
            str[i]=toupper(str[i]);
            int num=0;
            for(int j=0;j<16;j++)
            {
                if(s[j]==str[i])
                {
                    num=j;
                    break;
                }
            }
            sum+=weight*num;
            weight=weight*a;
        }
        for(int i=0;i<1000;i++)
            buf[i]=0;
        int index=999;
        while(sum!=0)
        {
            buf[index]=sum%b;
            sum=sum/b;
            index--;
        }
        for(int i=index+1;i<1000;i++)
        {
            char c=s[buf[i]];
            printf("%c",c);
        }
        printf("\n");

    }
    return 0;
}
