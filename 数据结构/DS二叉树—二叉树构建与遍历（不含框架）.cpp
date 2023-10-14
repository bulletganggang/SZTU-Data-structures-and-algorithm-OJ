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
    node *root;
    tree() : root(NULL) {}
    void qian(node *a)
    {
        if (a)
        {
            cout << a->data;
            qian(a->l);
            qian(a->r);
        }
    }
    void zhong(node *a)
    {
        if (a)
        {
            zhong(a->l);
            cout << a->data;
            zhong(a->r);
        }
    }
    void hou(node *a)
    {
        if (a)
        {
            hou(a->l);
            hou(a->r);
            cout << a->data;
        }
    }
    void create(node *&a)
    {
    char c;
    cin >> c;
    if (c != '#')
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
        tt.qian(tt.root);
        cout<<endl;
        tt.zhong(tt.root);
        cout<<endl;
        tt.hou(tt.root);
        cout<<endl;
    }
    system("pause");
    return 0;
}