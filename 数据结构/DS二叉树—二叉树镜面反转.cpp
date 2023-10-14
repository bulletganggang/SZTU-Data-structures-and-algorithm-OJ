#include<iostream>
using namespace std;
#define maxx 105

class node
{
public:
    char data;
    node *l,*r;
    node() : l(NULL), r(NULL) {}
    node(char a) : data(a), l(NULL), r(NULL) {}
};

class tree
{
public:
    node *root;
    tree() : root(NULL) {}
    void create(node *&r)
    {
        char op;
        cin>>op;
        if (op!='#')
        {
            r=new node(op);
            create(r->l);
            create(r->r);
        }
        else r=NULL;
    }
    void dui(node *r)
    {
        if (r)
        {
            if (r->l or r->r)
            {
                node *temp;
                temp=r->r;
                r->r=r->l;
                r->l=temp;
            }
            dui(r->l);
            dui(r->r);
        }
    }
    void qian(node *a)
    {
        if (a)
        {
            cout << a->data<<" ";
            qian(a->l);
            qian(a->r);
        }
    }
    void zhong(node *a)
    {
        if (a)
        {
            zhong(a->l);
            cout << a->data<<" ";
            zhong(a->r);
        }
    }
    void hou(node *a)
    {
        if (a)
        {
            hou(a->l);
            hou(a->r);
            cout << a->data<<" ";
        }
    }
    void bianli(node* a)
    {
        if(a)
        {
            node* b[100];
            b[0] = a;
            int first = 0;
            int rear = 1;
            while(first < rear)
            {
                cout<<b[first]->data<<" ";
                if(b[first]->l)
                {
                    b[rear++] = b[first]->l;
                }
                if(b[first]->r)
                {
                    b[rear++] = b[first]->r;
                }
                first++;
            }
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
        if (!tt.root)
        {
            cout<<"NULL\nNULL\nNULL\nNULL\n";
            continue;
        }
        tt.dui(tt.root);
        tt.qian(tt.root);
        cout<<endl;
        tt.zhong(tt.root);
        cout<<endl;
        tt.hou(tt.root);
        cout<<endl;
        tt.bianli(tt.root);
        cout<<endl;
    }
    system("pause");
}