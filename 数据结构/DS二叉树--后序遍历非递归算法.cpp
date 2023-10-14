#include<iostream>
#include<stack>
using namespace std;

class node
{
public:
    char data;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(char a) : data(a), l(NULL), r(NULL) {}
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
        if (t==NULL) return;
        stack<node*> s;
        node *cur=t,*last=NULL;
        while (cur)
        {
            s.push(cur);
            cur=cur->l;
        }
        while (!s.empty())
        {
            cur=s.top();
            s.pop();
            if (cur->r==NULL or cur->r==last ) 
            {
                cout<<cur->data;
                last=cur;
            }
            else
            {
                s.push(cur);
                cur=cur->r;
                while (cur)
                {
                    s.push(cur);
                    cur=cur->l;
                }
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
        tree tt;
        tt.create(tt.root);
        tt.level(tt.root);
    }
    system("pause");
}