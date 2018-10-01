#include<stdio.h>
#include<iostream>
using namespace std;
struct Node
{
    Node *lchild;
    Node *rchild;
    int num;
}Tree[100];

void InOrder(Node *r)
{
    cout<<r->num<<" ";
    if(r->lchild!=NULL)
        InOrder(r->lchild);
    if(r->rchild!=NULL)
        InOrder(r->rchild);
}

void MiddleOrder(Node *r)
{
    if(r->lchild!=NULL)
        MiddleOrder(r->lchild);
    cout<<r->num<<" ";
    if(r->rchild!=NULL)
        MiddleOrder(r->rchild);
}
void PostOrder(Node *r)
{
    if(r->lchild!=NULL)
        PostOrder(r->lchild);
    if(r->rchild!=NULL)
        PostOrder(r->rchild);
    cout<<r->num<<" ";
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<100;i++)
        {
            Tree[i].lchild=NULL;
            Tree[i].rchild=NULL;
            Tree[i].num=-1;
        }
        int currentIndex=0;
        Node *root=Tree;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(currentIndex==0)
            {
                Tree[0].num=x;
                currentIndex+=1;
                continue;
            }
            Node *tmp=root;
            while(true)
            {
                if(x<tmp->num&&tmp->lchild!=NULL)
                {
                    tmp=tmp->lchild;
                }
                else if(x>tmp->num&&tmp->rchild!=NULL)
                {
                    tmp=tmp->rchild;
                }
                else
                    break;
            }
            if(x<tmp->num)
            {
                Tree[currentIndex].num=x;
                tmp->lchild=&Tree[currentIndex];
                currentIndex++;
            }
            else if(x==tmp->num)
                continue;
            else if(x>tmp->num)
            {
                Tree[currentIndex].num=x;
                tmp->rchild=&Tree[currentIndex];
                currentIndex++;
            }
        }
        InOrder(root);
        cout<<endl;
        MiddleOrder(root);
        cout<<endl;
        PostOrder(root);
        cout<<endl;
    }
    return 0;
}
