#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    char data;
    node *l, *r;
    node(char op):data(op),l(NULL),r(NULL){}
};

class tree
{
public:
    node *root;
    string a;
    tree():root(NULL){cin>>a;}
    void create(node *&a)
    {
        char op;
        cin>>op;
        if (op!='#')
        {
            a=new node(op);
            create(a->l);
            create(a->r);
        }
        else
        {
            a=new node('#');
            a->l=NULL;
            a->r=NULL;
        }
    }
    void test()
    {
        int i=0;
        node *p;
        queue<node*> q;
        q.push(root);
        while (i!=a.length())
        {
            p=q.front();
            q.pop();
            if (p)
            {
                if (p->data!=a[i])
                {
                    cout<<"NO"<<endl;
                    return;
                }
                q.push(p->l);
                q.push(p->r);
            }
            i++;
        }
        cout<<"YES"<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        tree tt;
        tt.create(tt.root);
        tt.test();
    }
}