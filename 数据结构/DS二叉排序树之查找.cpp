#include<iostream>
using namespace std;

class node
{
public:
    int data,wei;
    node *l;
    node *r;
    node():l(NULL),r(NULL){wei=-1;}
    node(int x):data(x),l(NULL),r(NULL){wei=1;}
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
        root->wei=1;
        for (int i = 0; i < n-1; i++)
        {
            int x;
            cin>>x;
            insert(root,x,root->wei+1);
        }
        zhong(root);
        cout<<endl;
        int m;
        cin>>m;
        while (m--)
        {
            int x;
            cin>>x;
            find(root,x);
        }
    }
    void insert(node *rr,int x,int w)
    {
        node *a=new node(x);
        a->wei=w;
        if (x>rr->data and !rr->r)
        {
            rr->r=a;
        }
        else if (x < rr->data and !rr->l)
        {
            rr->l=a;
        }
        else if (x>rr->data and rr->r)
        {
            insert(rr->r,x,w+1);
        }
        else if (x<rr->data and rr->l)
        {
            insert(rr->l,x,w+1);
        }
    }
    void zhong(node *rr)
    {
        if (rr->l) zhong(rr->l);
        cout<<rr->data<<" ";
        if (rr->r) zhong(rr->r);
    }
    void find(node *rr,int x)
    {
        if (!rr)
        {
            cout<<"-1\n";
            return ;
        }
        if (x==rr->data)
        {
            cout<<rr->wei<<endl;
            return;
        }
        else if (x<rr->data)
        {
            find(rr->l,x);
        }
        else find(rr->r,x);
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
}