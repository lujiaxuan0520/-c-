#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int toMonth(string a)
{
    if(a=="January")
        return 1;
    if(a=="February")
        return 2;
    if(a=="March")
        return 3;
    if(a=="April")
        return 4;
    if(a=="May")
        return 5;
    if(a=="June")
        return 6;
    if(a=="July")
        return 7;
    if(a=="August")
        return 8;
    if(a=="September")
        return 9;
    if(a=="October")
        return 10;
    if(a=="November")
        return 11;
    if(a=="December")
        return 12;
}
int isLunar(int y)
{
    if(y%4==0&&y%100!=0||y%400==0)
        return 1;
    else
        return 0;
}
int monthMap[13][2]={
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31};
string week[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
struct Day
{
    int year;
    int month;
    int day;
    void nextDay()
    {
        day++;
        if(day>monthMap[month][isLunar(year)])
        {
            day=1;
            month++;
        }
        if(month>12)
        {
            month=1;
            year++;
        }
    }
};
int days[3001][13][32];
int main()
{
    Day tmp;
    tmp.year=1000;tmp.month=1;tmp.day=1;
    int count=0;
    while(tmp.year<=3000)
    {
        days[tmp.year][tmp.month][tmp.day]=count;
        tmp.nextDay();
        count++;
    }
    int now_days=days[2018][7][30];
    int day,year;
    string month_s;
    while(cin>>day>>month_s>>year)
    {
        int month=toMonth(month_s);
        int suoqiu=days[year][month][day];
        int jiange=suoqiu-now_days;
        int result=(jiange%7+8)%7;
        cout<<week[result]<<endl;
    }
    return 0;
}
