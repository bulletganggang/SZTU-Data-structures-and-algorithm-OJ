#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    char data;
    node *l,*r;
    node(): l(NULL), r(NULL){}
    node(char op):data(op),l(NULL), r(NULL){}
    friend class tree;
};

class tree
{
public:
    node *root;
    int sum=0;
    queue<char> q;
    tree(): root(NULL){}
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
    void leaf1(node *rt,int data)
    {
        if (rt)
        {
            if (!rt->l and !rt->r)
            {
                q.push(data);  //保存 parent data
                return;
            }
        leaf1(rt->l,rt->data);
        leaf1(rt->r,rt->data);
        }
    }
    void leaf2(node *rt)
    {
        if (rt)
        {
        if (rt->data==q.front())
        {
            q.pop();
            if (rt->l)
            {
                sum++;
            }
            return;
        }
        leaf2(rt->l);
        leaf2(rt->r);
        }
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
        tt.leaf1(tt.root,tt.root->data);
        tt.leaf2(tt.root);
        cout<<tt.sum<<endl;
    }
    system("pause");
}