#include<iostream>
using namespace std;
#define ok 0
#define error -1

class node
{
public:
    int data;
    node *next;
    node(){next = NULL;}
};

class list
{
public:
    node *head;
    int len;
    list();
    ~list();
    node * index(int i)
    {return ok;}
    int swap(int a,int b)
    {
        if (a<1 or b>len)
        {
            cout<<"error"<<endl;
            return error;
        }
        int j=0,k=0;
        node *p,*q; //pa  qb
        p=head,q=head;
        while (p and j<a)
        {
            p=p->next;
            j++;
        }
        while (q and k<b)
        {
            q=q->next;
            k++;
        }
        int t;
        t=p->data;
        p->data=q->data;
        q->data=t;
        show();
        return ok;
    }
    int insert(int i,int item)
    {
        int j=0;
        node *p;
        p=head;
        while (p!=NULL and j<i-1)
        {
            p=p->next;
            j++;
        }
        node *q=new node;
        q->data=item;
        q->next=p->next;
        p->next=q;
        len++;
        return ok;
    }
    void show()
    {
    node *p;
    p=head->next;
    while (p)
    {
        cout <<p->data <<" ";
        p=p->next;
    }
    cout<<endl;
    }
};

list::list()
{
    head = new node();
    len=0;
}

list::~list()
{
    node *p,*q;
    p=head;
    while (p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head = NULL;
}

int main()
{
    list l;
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        int x;
        cin>>x;
        l.insert(i,x);
    }
    l.show();
    int a,b;
    cin>>a>>b;
    l.swap(a,b);
    cin>>a>>b;
    l.swap(a,b);
    system("pause");
}