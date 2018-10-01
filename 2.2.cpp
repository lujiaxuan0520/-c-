#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
struct Student
{
    string name="";
    int age=0;
    double score=0;
};
bool cmp(Student x,Student y);
int main()
{
    int n;
    while(cin>>n)
    {
        Student a[1000];
        for(int i=0;i<n;i++)
        {
            Student stu;
            cin>>stu.name>>stu.age>>stu.score;
            a[i]=stu;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            cout<<a[i].name;
            printf(" %d %.f\n",a[i].age,a[i].score);
        }
    }
    return 0;
}

bool cmp(Student x,Student y)
{
    if(x.score<y.score)
        return true;
    else if(x.score==y.score)
    {
        if(x.name<y.name)
            return true;
        else if(x.name==y.name)
            return x.age<y.age;
        else
            return false;
    }
    else return false;
}


