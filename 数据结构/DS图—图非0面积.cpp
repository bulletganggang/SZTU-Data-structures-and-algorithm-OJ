#include<iostream>
#include<queue>
using namespace std;
#define maxx 20

class Map
{
public:
    int graph[maxx][maxx];
    int m,n;
    void create()
    {
        for(int i=0;i<=m+1;i++)
        {
            for(int j=0;j<=n+1;j++)
            {
                graph[i][j]=0;
            }
        }
        cin >> m >> n;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin >> graph[i][j];
            }
        }
    }
    void BFS()
    {
        int x=0,y=0;
        queue<int> Qx,Qy;
        Qx.push(x);
        Qy.push(y);
        graph[x][y]=1;
        int nx[4]={-1,0,1,0};
        int ny[4]={0,1,0,-1};
        while(!Qx.empty()){
            for(int i=0;i<4;i++)
            {
                if(Qx.front()+nx[i]>=0&&Qx.front()+nx[i]<=m+1&&Qy.front()+ny[i]>=0&&Qy.front()+ny[i]<=n+1&&graph[Qx.front()+nx[i]][Qy.front()+ny[i]]==0)
                {
                    Qx.push(Qx.front()+nx[i]);
                    Qy.push(Qy.front()+ny[i]);
                    graph[Qx.front()+nx[i]][Qy.front()+ny[i]]=1;
                }
            }
            Qx.pop();
            Qy.pop();
        }
    }
    void print()
    {
        int num=0;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(graph[i][j]==0)num++;
            } 
        }
        cout<<num<<endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Map mygraph;
        mygraph.create();
        mygraph.BFS();
        mygraph.print();
    }
    return 0;
}