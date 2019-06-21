#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n;
int visited[18];
vector<int> S;
bool isPrime(int x)
{
    if(x==1)
        return true;
    for(int i=2;i<sqrt(x)+1;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void dfs(int index)
{
    if(S.size()==n && isPrime(1+index))
    {
        for(int i=0;i<S.size();i++)
            cout<<S[i]<<" ";
        cout<<endl;
        int pop_index=S[S.size()-1];
        visited[pop_index]=0;
        S.pop_back();
        return;
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(visited[i]==1)
                continue;
            else if(!isPrime(index+i))
                continue;
            else
            {
                visited[i]=1;
                S.push_back(i);
                dfs(i);
            }
        }
        visited[index]=0;
        S.pop_back();
        return;
    }
}

int main()
{
    int case_num=1;
    while(cin>>n)
    {
        printf("Case %d:\n",case_num);
        case_num++;
        visited[1]=1;
        for(int i=2;i<=n;i++)
            visited[i]=0;
        S.clear();
        S.push_back(1);
        dfs(1);

        printf("\n");

    }
    return 0;
}

