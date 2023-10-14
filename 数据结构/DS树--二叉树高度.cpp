#include <iostream>
using namespace std;

class node
{
public:
    char data;
    int wei;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(char a) : data(a), l(NULL), r(NULL) {}
};

class tree
{
public:
    node *root;
    int max;
    tree() : root(NULL) {max=-1;}
    void create(node *&a,int w)
    {
    char c;
    cin >> c;
    if (c != '0')
    {
        a = new node(c);
        a->wei=w;
        if (w>max)
        {
            max=w;
        }
        create(a->l,w+1);
        create(a->r,w+1);
    }
    else a = NULL;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        tree tt;
        tt.create(tt.root,1);
        cout<<tt.max<<endl;
    }
    system("pause");
}