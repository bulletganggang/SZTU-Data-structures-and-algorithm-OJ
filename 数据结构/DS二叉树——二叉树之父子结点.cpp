#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    char data;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(char a) : data(a), l(NULL), r(NULL) {}
    friend class tree;
};

class tree
{
public:
    queue<char> q;
    tree() : root(NULL) {}
    node *root;
    void leaf(node *rr,int data)
    {
        if (rr)
        {
            if (!rr->l and !rr->r)
            {
                cout<<rr->data<<" ";
                q.push(data);
            }
            leaf(rr->l,rr->data);
            leaf(rr->r,rr->data);
        }
    }
    void create(node *&a)
    {
    char c;
    cin >> c;
    if (c != '0')
    {
        a = new node(c);
        create(a->l);
        create(a->r);
    }
    else a = NULL;
    }
    ~tree()
    {
        delete root;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        tree tt;
        tt.create(tt.root);
        tt.leaf(tt.root,tt.root->data);
        cout<<endl;
        while (!tt.q.empty())
        {
            cout<<tt.q.front()<<" ";
            tt.q.pop(); 
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}