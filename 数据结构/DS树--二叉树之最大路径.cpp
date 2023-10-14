#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    char data;
    int wei;
    node *l,*r;
    node():l(NULL),r(NULL){}
    node(char op):data(op),l(NULL),r(NULL){}
};

class tree
{
public:
    node *root;
    queue<int> q;
    int maxw;
    tree():root(NULL){maxw=0;}
    void create1(node *&t)
    {
        char a;
        cin>>a;
        if (a!='0')
        {
            t=new node(a);
            create1(t->l);
            create1(t->r);
        }
        else t=NULL;
    }
    void create2()
    {
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            q.push(x);
        }
    }
    void set(node *t,int r)
    {
        if (t)
        {
            t->wei=q.front()+r;
            q.pop();
            set(t->l,t->wei);
            set(t->r,t->wei);
            if (!t->r and !t->l)
            {
                if (t->wei >maxw)
                {
                    maxw=t->wei;
                }
            }
        }
        else return;
    }
    void print()
    {
        cout<<maxw<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        tree tt;
        tt.create1(tt.root);
        tt.create2();
        tt.set(tt.root,0);
        tt.print();
    }
    system("pause");
}