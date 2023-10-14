#include <iostream>
using namespace std;

class node
{
    char data;
    node *l, *r;

public:
    node() : l(NULL), r(NULL) {}
    node(char a) : data(a), l(NULL), r(NULL) {}
    friend class tree;
};

class tree
{
public:
    int sum=0;
    tree() : root(NULL) {}
    node *root;
    void bianli(node *root)
    {
        if (root->l!=NULL )
        {
            bianli(root->l);
        }
        if (root->r!=NULL )
        {
            bianli(root->r);
        }
        if (root->r==NULL and root->l==NULL)
        {
            sum++;
            return;
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
        tt.bianli(tt.root);
        cout<<tt.sum<<endl;
    }
    system("pause");
    return 0;
}