#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
bool IsLunar(int y)
{
    if(y%4==0&&y%100!=0||y%400==0)
        return true;
    else
        return false;
}
int monCount(int m,int y)
{
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if(IsLunar(y))
            return 29;
        else
            return 28;
    }
}
int yearCount(int y)
{
    if(IsLunar(y))
        return 366;
    else
        return 365;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int a_y=stoi(a.substr(0,4));
        int a_m=stoi(a.substr(4,2));
        int a_d=stoi(a.substr(6,2));
        int b_y=stoi(b.substr(0,4));
        int b_m=stoi(b.substr(4,2));
        int b_d=stoi(b.substr(6,2));
        int result=(b_y-a_y)*yearCount(a_y)+
                    (b_m-a_m)*monCount(a_m,a_y)+
                    (b_d-a_d)+1;
        cout<<result<<endl;
    }
    return 0;
}
