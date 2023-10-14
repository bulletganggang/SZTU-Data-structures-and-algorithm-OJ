#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class map
{
public:
    vector<vector<int>>  jz;
    int vnum;
    vector<bool> visit;
    void create()
    {
        cin>>vnum;
        for (int i = 0; i < vnum; i++)
        {
            visit.push_back(false);
            vector<int> row;
            for (int j = 0; j < vnum; j++)
            {
                int edge;
                cin>>edge;
                row.push_back(edge);
            }
            jz.push_back(row);
        }
    }
    void up(queue<int>& q,int rootno)
    {
        for (int i = 0; i < vnum; i++)
        {
            if (visit[i])
            {
            }
            else if (!jz[rootno][i])
            {
            }
            else
            {
                visit[i]=true;
                q.push(i);
            }
        }
    }
    void bfs(int v)
    {
        queue<int> q;
        q.push(v);
        visit[v]=true;
        while (!q.empty())
        {
            int root=q.front();
            q.pop();
            cout<<root<<" ";
            up(q,root);
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