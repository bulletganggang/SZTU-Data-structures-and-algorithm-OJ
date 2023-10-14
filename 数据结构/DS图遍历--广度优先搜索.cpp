#include<iostream>
#include<queue>
using namespace std;
const int maxx=20;

class map
{
public:
    int jz[maxx][maxx];
    int vnum;
    bool visit[maxx];
    void create()
    {
        cin>>vnum;
        for (int i = 0; i < maxx; i++)
        {
            for (int j = 0; j < maxx; j++)
            {
                jz[i][j]=0;
            }
        }
        for (int i = 0; i < vnum; i++)
        {
            for (int j = 0; j < vnum; j++)
            {
                cin>>jz[i][j];
            }
        }
    }
    void bfs(int v)
    {
        int k=0,w=0,j=0;
        int *aj=new int [vnum];
        queue<int> q;
        for (int i = 0; i < vnum; i++)
        {
            visit[i]=false;
        }
        if (!visit[v])
            {
                visit[v]=true;
                q.push(v);
            while (!q.empty())
            {
                int u=q.front();
                q.pop();
                cout<<u<<" ";
                for (int i = 0; i < vnum; i++)
                {
                    if (jz[u][i] and !visit[i])
                    {
                        q.push(i);
                        visit[i]=true;
                    }
                }
            }
            }
        cout<<endl;
    }
    map(){}
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        map m;
        m.create();
        m.bfs(0);
    }
    system("pause");
}