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
    bool operator<(const Student &y) const
    {
        if(this->score<y.score)
            return true;
        else if(this->score==y.score)
        {
            if(this->name<y.name)
                return true;
            else if(this->name==y.name)
                return this->age<y.age;
            else
                return false;
        }
        else return false;
    }
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
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i].name;
            printf(" %d %.f\n",a[i].age,a[i].score);
        }
    }
    return 0;
}



