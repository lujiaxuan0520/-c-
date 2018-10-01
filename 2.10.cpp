#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Student
{
    string num;
    string name,sex;
    int age;
    bool operator<(const Student &b)
    {
        return this->num<b.num;
    }
};
int main()
{
    int n;
    cin>>n;
    Student students[1000];
    for(int i=0;i<n;i++)
    {
        Student tmp;
        cin>>tmp.num>>tmp.name>>tmp.sex>>tmp.age;
        students[i]=tmp;
    }
    sort(students,students+n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string a;
        cin>>a;
        int p=0,q=n-1,mid=(p+q)/2;
        while(1)
        {
            if(p>q)
            {
                cout<<"No Answer!"<<endl;
                break;
            }
            if(a==students[mid].num)
            {
                cout<<students[mid].num<<" "<<students[mid].name<<" "<<students[mid].sex<<" "<<students[mid].age<<endl;
                break;
            }
            else if(students[mid].num>a)
            {
                q=mid-1;
                mid=(p+q)/2;
            }

            else
            {
                p=mid+1;
                mid=(p+q)/2;
            }

        }
    }
    return 0;
}
