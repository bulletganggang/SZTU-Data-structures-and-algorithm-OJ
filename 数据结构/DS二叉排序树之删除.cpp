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
    node *temp=new node();
    node *par=new node();
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
            if(find(root,x)) del(temp,x);
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
    int find(node *rr,int x)
    {
        if (x==rr->data)
        {
            temp=rr;
            return 1;
        }
        else if (x>rr->data)
        {
            if (!rr->r) return -1;
            if (rr->r->data==x)
            {
                if (!rr->r->l and !rr->r->r)
                {
                    par=rr;
                }
            }
            find(rr->r,x);
        }
        else if (x<rr->data)
        {
            if (!rr->l) return -1;
            if (rr->l->data==x)
            {
                if (!rr->l->l and !rr->l->r)
                {
                    par=rr;
                }
            }
            find(rr->l,x);
        }
        return 1;
    }
    void del(node *rr,int x)
    {
        node *p=new node();
        p=rr;
        if (!rr->l and !rr->r)
        {
            if(par->l->data==x) par->l=NULL;
            else par->r=NULL;
        }
        else if (!rr->l)
        {
            rr=rr->r;
        }
        else if (!rr->r)
        {
            rr=rr->l;
        }
        else
        {
            node *max=new node();
            max=rr->l;
            while (max->r)  //找到最大值
            {
                p=max;
                max=max->r;
            }
            rr->data=max->data;
            if (p!=rr)
            {
                p->r=max->l;
            }
            else p->l=max->l;  //没找到最大值，寻求的节点的左孩子没有右子树
            delete max,p;
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
        tt.create();
    }
    system("pause");
}