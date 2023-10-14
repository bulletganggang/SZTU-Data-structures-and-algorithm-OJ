#include<iostream>
using namespace std;

class graph
{
public:
    char type;  //类型  
    string *num;  //顶点集
    int n,t;  //顶点数  操作次数
    int jz[105][105];
    graph(){}
    void create()
    {
        cin>>type>>n;
        num=new string[n+1];
        init();
        for (int i = 1; i <= n; i++)
        {
            cin>>num[i];
        }
        cz();
    }
    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
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
            if (type=='U')
            {
                jz[i2][i1]=1;
            }
            
        }
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout<<jz[i][j];
                if (j!=n)
                {
                    cout<<" ";
                }
                
            }
            cout<<endl;
        }
        if (type=='D')
        {
            int sum1[n+1],sum2[n+1];
            for (int i = 1; i <= n; i++)
            {
                sum1[i]=0;
                sum2[i]=0;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    sum1[i]+=jz[i][j];
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    sum2[i]+=jz[j][i];
                }
            }
            for (int i = 1; i <= n; i++)
            {
                cout<<num[i];
                if (sum1[i] or sum2[i])
                {
                    cout<<": "<<sum1[i]<<" "<<sum2[i]<<" "<<sum1[i]+sum2[i]<<endl;
                }
            }
        }
        else
        {
            int sum[n+1];
            for (int i = 1; i <= n; i++)
            {
                sum[i]=0;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    sum[i]+=jz[i][j];
                }
            }
            for (int i = 1; i <= n; i++)
            {
                cout<<num[i];
                if (sum[i])
                {
                    cout<<": "<<sum[i]<<endl;
                }
                else cout<<endl;
            }
        }
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