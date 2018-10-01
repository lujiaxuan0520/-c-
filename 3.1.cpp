#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        stack<char> cstack;
        stack<int> istack;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            str+=" ";
            if(s[i]=='(')
            {
                cstack.push('$');
                istack.push(i);
            }
            else if(s[i]==')')
            {
                if(!cstack.empty()&&cstack.top()=='$')
                {
                    cstack.pop();
                    istack.pop();
                }
                else
                {
                    cstack.push('?');
                    istack.push(i);
                }
            }
        }
        while(!cstack.empty())
        {
            char ch=cstack.top();
            cstack.pop();
            int index=istack.top();
            istack.pop();
            str[index]=ch;
        }
        cout<<str<<endl;
    }
    return 0;
}
