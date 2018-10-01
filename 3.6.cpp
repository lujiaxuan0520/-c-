#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct Node
{
    Node *lchild;
    Node *rchild;
    int num;
}Tree[10];
int loc;

Node *Insert(Node *r,int i)
{
    if(r==NULL&&loc==0)
    {
        Tree[loc].num=i;
        loc++;
        return &Tree[0];
    }
    else if(r==NULL)
    {
        Tree[loc].num=i;
        loc++;
        return &Tree[loc-1];
    }
    else if(i<r->num)
        r->lchild=Insert(r->lchild,i);
    else if(i>r->num)
        r->rchild=Insert(r->rchild,i);
    return r;
}

string preOrder(Node *r,string& pre)
{
    char a=r->num+'0';
    pre+=a;
    if(r->lchild!=NULL)
        pre=preOrder(r->lchild,pre);
    if(r->rchild!=NULL)
        pre=preOrder(r->rchild,pre);
    return pre;
}

string inOrder(Node *r,string& in)
{
    if(r->lchild!=NULL)
        in=inOrder(r->lchild,in);
    char a=r->num+'0';
    in+=a;
    if(r->rchild!=NULL)
        in=inOrder(r->rchild,in);
    return in;
}

string postOrder(Node *r,string& post)
{
    if(r->lchild!=NULL)
        post=postOrder(r->lchild,post);
    if(r->rchild!=NULL)
        post=postOrder(r->rchild,post);
    char a=r->num+'0';
    post+=a;
    return post;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        loc=0;
        for(int i=0;i<10;i++)//clear
        {
            Tree[i].lchild=NULL;
            Tree[i].rchild=NULL;
            Tree[i].num=-1;
        }
        Node *root=NULL;
        string s;
        cin>>s;
        for(auto &_:s)//遍历每个数
        {
            int i=_-'0';
            root=Insert(root,i);
        }
        string pre="";
        string in="";
        string post="";
        pre=preOrder(root,pre);
        in=inOrder(root,in);
        post=postOrder(root,post);
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            if(str==pre||str==in||str==post)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
