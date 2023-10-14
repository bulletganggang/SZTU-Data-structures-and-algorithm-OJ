#include<iostream>
using namespace std;
#define maxx 20

class map
{
private:
    int jz[maxx][maxx];
    int n,sum;
    bool visit[maxx];
    int in[maxx];  //入度
public:
    map(){sum=0;}
    void create()
    {
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            visit[i]=0;
            in[i]=0;
            for (int j = 0; j < n; j++)
            {
                cin>>jz[i][j];
            }
        }
        scan();
    }
    void scan()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (jz[i][j])
                {
                    in[j]++;
                }
            }
        }
    }
    int find()
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i]==0 and !visit[i])
            {
                return i;
            }
        }
        return -1;
    }
    void cz()
    {
        int v=find();
        while (v!=-1)
        {
            cout<<v<<" ";
            visit[v]=1;
            for (int i = 0; i < n; i++)
            {
                if (jz[v][i])
                {
                    in[i]--;
                }
            }
            v=find();
        }
        cout<<endl;
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
        m.cz();
    }
    system("pause");
}