#include<iostream>
using namespace std;
const int maxx=20;

class map
{
public:
    int jz[maxx][maxx];
    bool visit[maxx];
    int vnum,sum;
    map(){}
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
            for (int j = 0; j < vnum; j++)
            {
                visit[j]=0;
            }
            
            sum=0;
            dfs(i);
        if (sum!=vnum)
        {
            cout<<"No\n";
            return;
        }
        }
        cout<<"Yes\n";
    }
    void dfs(int v)
    {
        int k=0,w=0,j=0;
        visit[v]=true;
        sum++;
        int *aj=new int[vnum];
        for (int i = 0; i < vnum; i++)
        {
            aj[i]=-1;
        }
        for (int i = 0; i < vnum; i++)
        {
            if (jz[v][i])
            {
                aj[k++]=i;
            }
        }
        while (1)
        {
            w=aj[j++];
            if (w==-1) break;
            if (!visit[w])
            {
                dfs(w);
            }
        }
        delete []aj;
    }

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