#include<iostream>
using namespace std;
#define maxx 105

struct edge  //边表
{
    int in;  //位置下标
    edge* next;  //指向下一个邻接点
};

struct ding
{
    char data;  //存储信息
    edge *next;  //边表头指针
};

class graph
{
public:
    ding list[maxx];
    int numd,nume;  //当前定点数和边数
    void create()
    {
        cin>>numd>>nume; 
        for (int i = 0; i < numd; i++)
        {
            cin>>list[i].data;
            list[i].next=new edge;
            list[i].next->next=NULL;
        }
        for (int i = 0; i < nume; i++)
        {
            char a,b;
            cin>>a>>b;
            int i1=find(a);
            int i2=find(b);
            edge *e=new edge;
            e->in=i2;
            e->next=NULL;
            edge *q=list[i1].next;
            while (q->next)
            {
                q=q->next;
            }
            q->next=e;
        }
    }
    int find(char a)
    {
        for (int i = 0; i < numd; i++)
        {
            if (list[i].data == a)
            {
                return i;
            }
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i < numd; i++)
        {
            cout<<i<<" "<<list[i].data<<"-";
            edge *e=list[i].next->next;
            while (e)
            {
                cout<<e->in;
                e=e->next;
                cout<<"-";
            }
            cout<<"^\n";
        }
    }
    graph(){}
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