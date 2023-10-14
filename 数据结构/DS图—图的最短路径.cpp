#include<iostream>
using namespace std;
#define maxx 105
#define inf 100000
class map
{
private:
    int n;  //顶点数
    string num[maxx];  //顶点
    int jz[maxx][maxx],start;
    int path[maxx];  //路径
    int dist[maxx];  //距离
    bool visit[maxx];
public:
    map(){}
    void create()
    {
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
            visit[i]=0;
            dist[i]=0;
            path[i]=-1;
        }
        for (int i = 0; i < n; i++)
        {   
            for (int j = 0; j < n; j++)
            {
                cin>>jz[i][j];
                if (jz[i][j]==0 and i!=j)
                {
                    jz[i][j]=inf;
                }
            }
        }
        string op;
        cin>>op;
        start=find(op);
    }
    int find(string a)
    {
        for (int i = 0; i < n; i++)
        {
            if (num[i]==a)
            {
                return i;
            }
        }
        return -1;
    }
    int findmin()
    {
        int min=100000,k=-1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i]<min and !visit[i])
            {
                min=dist[i];
                k=i;
            }
        }
        return k;
    }
    void dj()
    {
        for (int i = 0; i < n; i++)
        {
            dist[i]=jz[start][i];
            if (dist[i]) path[i]=start;
            else path[i]=-1;
        }
        visit[start]=1;
        int sum=1;
        while (sum<n)
        {
            int min=findmin();
            visit[min]=1;
            for (int i = 0; i < n; i++)
            {
                if (!visit[i] and (dist[i]>dist[min]+jz[min][i]))
                {
                    dist[i]=dist[min]+jz[min][i];
                    path[i]=min;
                }
            }
            sum++;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            if (i==start)
            {
                continue;
            }
            cout<<num[start]<<"-"<<num[i]<<"-";
            if (dist[i]!=inf)
            {
                int temp[maxx],top=0,t=path[i];
                cout<<dist[i]<<"----[";
                while (t!=-1)
                {
                    temp[top++]=t;
                    t=path[t];
                }
                for (int i = top-1; i >= 0; i--)
                {
                    cout<<num[temp[i]]<<" ";
                }
                cout<<num[i]<<" ";
                cout<<"]\n";
            }
            else cout<<"-1\n";
        }
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
        m.dj();
        m.print();
    }
    system("pause");
}