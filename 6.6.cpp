#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
int go[8][2]={0,1,0,-1,1,0,1,1,1,-1,-1,0,-1,1,-1,-1};
int maze[101][101];
int visited[101][101];
int _count;
int m,n;

void dfs(int x,int y)
{
    visited[x][y]=1;
    for(int q=0;q<8;q++)
    {
        int newx=x+go[q][0];
        int newy=y+go[q][1];
        if(newx>0 && newx<m && newy>0 && newy<n)
        {
            if(maze[newx][newy]==1 && visited[newx][newy]==0)
                dfs(newx,newy);
        }

    }
}

int main()
{
    ifstream in;
    in.open("6.6_1.txt");
    while(in>>m>>n)
    {
        _count=0;
        if(m==0)
            break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char tmp;
                in>>tmp;
                if(tmp=='*')
                {
                    maze[i][j]=0;
                }
                else if(tmp=='@')
                    maze[i][j]=1;
                visited[i][j]=0;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j]==1 && visited[i][j]==0)
                {
                    _count++;
                    visited[i][j]=1;
                    dfs(i,j);
                }
            }
        }
        cout<<_count<<endl;
    }
    in.close();
    return 0;
}
