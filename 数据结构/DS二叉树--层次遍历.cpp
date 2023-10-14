#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    char data;
    node *l,*r;
    node():l(NULL),r(NULL){}
    node(char a):data(a),l(NULL),r(NULL){}
};

class tree
{
public:
    node *root;
    tree():root(NULL){}
    void create(node *&a)
    {
        char op;
        cin>>op;
        if (op!='0')
        {
            a=new node(op);
            create(a->l);
            create(a->r);
        }
        else a=NULL;
    }
    void level(node *t)
    {
        queue<node*> q;
        node *p=t;
        q.push(t);
        while(!q.empty())
        {
            p=q.front();
            cout<<p->data;
            q.pop();
            if (p->l)
            {
                q.push(p->l);
            }
            if (p->r)
            {
                q.push(p->r);
            }
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
        tree tr;
        tr.create(tr.root);
        tr.level(tr.root);
    }
    system("pause");
}