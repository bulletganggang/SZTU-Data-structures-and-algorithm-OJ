#include<iostream>
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
    void dfstt()
    {
        for (int i = 0; i < vnum; i++)
        {
            visit[i]=false;
        }
        for (int i = 0; i < vnum; i++)
        {
            if (visit[i]==false)
            {
                dfs(i);
            }
        }
        cout<<endl;
    }
    void dfs(int v)
    {
        int k=0,w=0,j=0;
        visit[v]=true;
        cout<<v<<" ";
        int *adj=new int[vnum];
        for (int i = 0; i < vnum; i++)
        {
            adj[i]=-1;  //初始化
        }
        for (int i = 0; i < vnum; i++)
        {
            if (jz[v][i])
            {
                adj[k++]=i;
            }
        }
        while (1)
        {
            w=adj[j++];
            if (w==-1)
            {
                break;
            }
            if (!visit[w])
            {
                dfs(w);
            }
        }
        delete []adj;
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
        m.dfstt();
    }
    system("pause");
}