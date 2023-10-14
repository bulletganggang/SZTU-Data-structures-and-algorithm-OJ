#include<iostream>
using namespace std;
#define maxx 20
#define inf 1000000

struct edge1
{
    int aj,wei;
};

struct edge2
{
    int from,to;
    int wei;
};

class map
{
private:
    bool visit[maxx];
    int jz[maxx][maxx],dist[maxx];
    int n,m; //顶点数  边数
    edge1 e1[maxx];
    edge2 e2[maxx*maxx];
    string start;
    int pos;
    string num[maxx];  //顶点 
public:
    map(){}
    void init()
    {
        for (int i = 0; i < n; i++)
        {
            visit[i]=false;
            for (int j = 0; j < n; j++)
            {
                jz[i][j]=inf;
            }
        }
    }
    void create()
    {
        cin>>n;
        init();
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
        }
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            string a,b;
            int w;
            cin>>a>>b>>w;
            int i1=find(a),i2=find(b);
            e2[i].from=i1,e2[i].to=i2,e2[i].wei=w;
            jz[i1][i2]=jz[i2][i1]=w;
        }
        cin>>start;
        pos=find(start);
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
    void prim()
    {
        //输出sum总权重
        int sum=0;
        for (int i = 0; i < n; i++)  //初始化辅助数组
        {
            e1[i].aj=pos;
            e1[i].wei=jz[pos][i];
        }
        e1[pos].wei=0;
        for (int i = 0; i < n-1; i++)
        {
            int k=-1,temp=inf;
            for (int q = 0; q < n; q++)
            {
                if (e1[q].wei<temp and e1[q].wei)
                {
                    temp=e1[q].wei;
                    k=q;
                }
            }
            sum+=e1[k].wei;
            e1[k].wei=0;
            for (int j = 0; j < n; j++)
            {
                if (jz[k][j]<e1[j].wei)
                {
                    e1[j].wei=jz[k][j];
                    e1[j].aj=k;
                }
            }
        }
        cout<<sum<<endl;
        cout<<"prim:\n";
        
        //输出各个边
        for (int i = 0; i < n; i++)  //初始化辅助数组
        {
            e1[i].aj=pos;
            e1[i].wei=jz[pos][i];
        }
        e1[pos].wei=0;
        for (int i = 0; i < n-1; i++)
        {
            int k=-1,temp=inf;
            for (int q = 0; q < n; q++)
            {
                if (e1[q].wei<temp and e1[q].wei)
                {
                    temp=e1[q].wei;
                    k=q;
                }
            }
            cout<<num[e1[k].aj]<<" "<<num[k]<<" "<<e1[k].wei<<endl;
            e1[k].wei=0;
            for (int j = 0; j < n; j++)
            {
                if (jz[k][j]<e1[j].wei)
                {
                    e1[j].wei=jz[k][j];
                    e1[j].aj=k;
                }
            }
        }
    }
    int findroot(int p[],int v)
    {
        int t=v;
        while (p[t]>-1)
        {
            t=p[t];
        }
        return t;
    }
    void sort()
    {
        for (int i = 0; i < m-1; i++)
        {
            for (int j = i+1; j < m; j++)
            {
                if (e2[j].wei<e2[i].wei)
                {
                    edge2 temp=e2[i];
                    e2[i]=e2[j];
                    e2[j]=temp;
                }
            }
        }
    }
    void kruskal()
    {
        sort();
        cout<<"kruskal:\n";
        int parent[n],sum=0;  //根节点  操作次数
        for (int i = 0; i < n; i++)
        {
            parent[i]=-1;
        }
        for (int i = 0; i < m; i++)
        {
            int v1=findroot(parent,e2[i].from);
            int v2=findroot(parent,e2[i].to);
            if (v1!=v2)
            {
                if(e2[i].from<e2[i].to) cout<<num[e2[i].from]<<" "<<num[e2[i].to]<<" "<<e2[i].wei<<endl;
                else cout<<num[e2[i].to]<<" "<<num[e2[i].from]<<" "<<e2[i].wei<<endl;
            
            parent[v2]=v1;
            sum++;
            }
            if (sum==n-1) return;
        }
    }
};

int main()
{
    map m;
    m.create();
    m.prim();
    m.kruskal();
    system("pause");
}