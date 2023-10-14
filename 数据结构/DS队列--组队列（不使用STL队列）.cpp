#include<iostream>
using namespace std;
#define MAX 1005

struct xdata
{
    string data[MAX];
};

class queue
{
public:
    xdata *x;
    int q=1,w=0;
    int m,k[MAX];  //k储存每一组多少个数
    queue()
    {
        m=1;
        for (int i = 0; i < MAX; i++)
        {
            k[i]=0;
        }
    }
    void setl(int len)
    {
        x=new xdata[len+1];
    }
    void setq(int t)
    {
        for (int i = 0; i < t; i++)
        {
            string n;
            cin>>n;
            x[m].data[k[m]++]=n;
        }
        m++;
    }
    void move(string op)
    {
        if (op=="ENQUEUE")
        {
            string n;
            int flag=0;
            cin>>n;
            char o=n[0];
            for (int i = 1; i <= m; i++)
            {
                if (o==x[i].data[0][0])  //说明有组，插入尾巴就行了
                {
                    int j=0;
                    while (x[i].data[j][0]==o)
                    {
                        j++;
                    }
                    x[i].data[j]=n;
                    k[i]++;
                    flag=1;
                    break;
                }
            }
            if (flag==0)  //meiyou
            {
                x[++m].data[0]=n;
                k[m]++;
            }
        }
        else if (op=="DEQUEUE")
        {
            cout<<x[q].data[w]<<" ";
            w++;
            k[q]--;
            if (k[q]==0)
            {
                q++;
                w=0;
            }
        }
    }
};

int main()
{
    int t;
    cin>>t;
    queue q;
    q.setl(t);
    while (t--)
    {
        int n;
        cin>>n;
        q.setq(n);
    }
    string op;
    while (cin>>op)
    {
        if (op=="STOP")
        {
            break;
        }
        q.move(op);
    }
    system("pause");
}