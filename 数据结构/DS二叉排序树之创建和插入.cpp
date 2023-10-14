#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *l;
    node *r;
    node():l(NULL),r(NULL){}
    node(int x):data(x),l(NULL),r(NULL){}
};

class tree
{
public:
    node *root;
    tree(){}
    void create()
    {
        int n;
        cin>>n;
        root=new node();
        cin>>root->data;
        for (int i = 0; i < n-1; i++)
        {
            int x;
            cin>>x;
            insert(root,x);
        }
        zhong(root);
        cout<<endl;
        int m;
        cin>>m;
        while (m--)
        {
            int x;
            cin>>x;
            insert(root,x);
            zhong(root);
            cout<<endl;
        }
    }
    void insert(node *rr,int x)
    {
        node *a=new node(x);
        if (x>rr->data and !rr->r)
        {
            rr->r=a;
        }
        else if (x<rr->data and !rr->l)
        {
            rr->l=a;
        }
        else if (x>rr->data and rr->r)
        {
            insert(rr->r,x);
        }
        else if (x<rr->data and rr->l)
        {
            insert(rr->l,x);
        }
        
    }
    void zhong(node *rr)
    {
        if (rr->l) zhong(rr->l);
        cout<<rr->data<<" ";
        if (rr->r) zhong(rr->r);
    }
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        tree tt;
        tt.create();
    }
    system("pause");
}