#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct Node
{
    int x;
    int y;
    int z;
    int t;
    Node(int _x,int _y,int _z,int _t)
    {
        x=_x;
        y=_y;
        z=_z;
        t=_t;
    }
};
bool visited[101][101][101];
//char seq[6][2]={'x','y',
//            'x','z',
//            'y','x',
//            'y','z',
//            'z','x',
//            'z','y'};
int main()
{
    int S,N,M;

    while(scanf("%d%d%d",&S,&N,&M)!=EOF)
    {
        if(S==0 && N==0 && M==0)
            break;
        for(int i=0;i<S;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<M;k++)
                    visited[i][j][k]=false;
        Node fir(S,0,0,0);
        queue<Node> Q;
        Q.push(fir);
        visited[S][0][0]=true;
        while(!Q.empty())
        {
            Node cur=Q.front();
            int cx=cur.x;int cy=cur.y;int cz=cur.z;int ct=cur.t;
            Q.pop();
            if((cx==S/2 && cy==S/2) || (cy==S/2 && cz==S/2) || (cx==S/2 && cz==S/2))
            {
                printf("%d\n",ct);
                break;
            }

//            for(int i=0;i<6;i++)
//            {
                //1
            if(cx>0)
            {
                if(cx<=N-cy)
                {
                    if(visited[0][cy+cx][cz]==false)
                    {
                        Node new_n(0,cy+cx,cz,ct+1);
                        Q.push(new_n);
                        visited[0][cy+cx][cz]=true;
                    }
                }
                else
                {
                    if(visited[cx-(N-cy)][N][cz]==false)
                    {
                        Node new_n(cx-(N-cy),N,cz,ct+1);
                        Q.push(new_n);
                        visited[cx-(N-cy)][N][cz]=true;
                    }
                }

                if(cx<=M-cz)
                {
                    if(visited[0][cy][cz+cx]==false)
                    {
                        Node new_n(0,cy,cz+cx,ct+1);
                        Q.push(new_n);
                        visited[0][cy][cz+cx]==true;
                    }
                }
                else
                {
                    if(visited[cx-(M-cz)][cy][M]==false)
                    {
                        Node new_n(cx-(M-cz),cy,M,ct+1);
                        Q.push(new_n);
                        visited[cx-(M-cz)][cy][M]==true;
                    }
                }
            }

            //2
            if(cy>0)
            {
                if(cy<=S-cx)
                {
                    if(visited[cx+cy][0][cz]==false)
                    {
                        Node new_n(cx+cy,0,cz,ct+1);
                        Q.push(new_n);
                        visited[cx+cy][0][cz]=true;
                    }
                }
                else
                {
                    if(visited[S][cy-(S-cx)][cz]==false)
                    {
                        Node new_n(S,cy-(S-cx),cz,ct+1);
                        Q.push(new_n);
                        visited[S][cy-(S-cx)][cz]=true;
                    }
                }

                if(cy<=M-cz)
                {
                    if(visited[cx][0][cz+cy]==false)
                    {
                        Node new_n(cx,0,cz+cy,ct+1);
                        Q.push(new_n);
                        visited[cx][0][cz+cy]==true;
                    }
                }
                else
                {
                    if(visited[cx][cy-(M-cz)][M]==false)
                    {
                        Node new_n(cx,cy-(M-cz),M,ct+1);
                        Q.push(new_n);
                        visited[cx][cy-(M-cz)][M]==true;
                    }
                }
            }

            //3
            if(cz>0)
            {
                if(cz<=S-cx)
                {
                    if(visited[cx+cz][cy][0]==false)
                    {
                        Node new_n(cx+cz,cy,0,ct+1);
                        Q.push(new_n);
                        visited[cx+cz][cy][0]=true;
                    }
                }
                else
                {
                    if(visited[S][cy][cz-(S-cx)]==false)
                    {
                        Node new_n(S,cy,cz-(S-cx),ct+1);
                        Q.push(new_n);
                        visited[S][cy][cz-(S-cx)]=true;
                    }
                }

                if(cz<=N-cy)
                {
                    if(visited[cx][cy+cz][0]==false)
                    {
                        Node new_n(cx,cy+cz,0,ct+1);
                        Q.push(new_n);
                        visited[cx][cy+cz][0]==true;
                    }
                }
                else
                {
                    if(visited[cx][N][cz-(N-cy)]==false)
                    {
                        Node new_n(cx,N,cz-(N-cy),ct+1);
                        Q.push(new_n);
                        visited[cx][N][cz-(N-cy)]==true;
                    }
                }
            }


        }
    }
    return 0;
}
