#include<iostream>
using namespace std;

class node
{
public:
    char data;
    int wei;
    node *l,*r;
    node():l(NULL),r(NULL){}
    node(char op):data(op),l(NULL),r(NULL){}
};

class tree
{
public:
    node *root;
    tree():root(NULL){sum=0,k=0;}
    int *num,sum,k;
    void create1(node *&a,int w)
    {
        char op;
        cin>>op;
        if (op!='0')
        {
            a=new node(op);
            a->wei=w;
            create1(a->l,w+1);
            create1(a->r,w+1);
        }
        else a=NULL;
    }
    void create2()
    {
        int n;
        cin>>n;
        num=new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
        }
    }
    void bianli(node *t)
    {
        if (t)
        {
            if (t->data>='A' and t->data<='Z')
            {
                sum+=t->wei*num[k++];
                return;
            }
            bianli(t->l);
            bianli(t->r);
        }
        else return;
    }
    void print()
    {
        cout<<sum<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        tree tt;
        tt.create1(tt.root,0);
        tt.create2();
        tt.bianli(tt.root);
        tt.print();
    }
    system("pause");
}