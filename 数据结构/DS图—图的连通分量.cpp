#include<iostream>
#include<algorithm>
using namespace std;

class graph
{
public:
    string *num;  //顶点集
    int n,t,sum;  //顶点数  操作次数
    bool visit[20];
    int jz[20][20];
    graph(){}
    void create()
    {
        cin>>n;
        init();
        num=new string[n];
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
        }
        cz();
    }
    void init()
    {
        sum=0;
        for (int i = 0; i < n; i++)
        {
            visit[i]=false;
            for (int j = 0; j < n; j++)
            {
                jz[i][j]=0;
            }
        }
    }
    void cz()
    {
        cin>>t;
        while (t--)
        {
            string op1,op2;
            int i1,i2;
            cin>>op1>>op2;
            for (int i = 1; i <= n; i++)
            {
                if (op1==num[i])
                {
                    i1=i;
                }
                if (op2==num[i])
                {
                    i2=i;
                }
            }
            jz[i1][i2]=1;
            jz[i2][i1]=1;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            if(i==0) cout<<num[i];
            else cout<<" "<<num[i];
        }
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(j==0) cout<<jz[i][j];
                else cout<<" "<<jz[i][j];
            }
            cout<<endl;
        }
        dfstt();
        cout<<sum<<endl<<endl;
    }
    void dfstt()
    {
        for(int i=0;i<n;i++)
            visit[i]=false;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(i);
                sum++;
            }
        }
    }
    void dfs(int v)
    {
        visit[v]=true;
        int* temp=new int[n];
        int pos=0;
        for(int i=0;i<n;i++)
            if(jz[v][i])temp[pos++]=i;

        for(int i=0;i<pos;i++)
            if(!visit[temp[i]])dfs(temp[i]);    
            
        delete[] temp;
    }
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        graph g;
        g.create();
        g.print();
    }
    system("pause");
}