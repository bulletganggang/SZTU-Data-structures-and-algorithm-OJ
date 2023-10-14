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
    void find()
    {
        node *p,*q;
        p=head->next;
        while (p)
        {
        q=p; 
        node *s=new node;
        s=q->next;
        while(s)
        {
            if ( s->data==p->data )
            {
                node *t=new node;
				t=q->next;
				q->next=t->next;
                s=q->next;
				free(t);
				len--;
            }
            else
            {
                q=q->next;
                s=q->next;
            } 
        }
        p=p->next;
        }
    }
    void show()
    {
    node *p;
    p=head->next;
    cout<<len<<": ";
    while (p)
    {
        cout <<p->data;
        if (p->next)
        {
            cout<<" ";
        }
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
    int t;
    cin>>t;
    while (t--)
    {
        list l;
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            l.insert(i,x);
        }
        l.find();
        l.show();
    }
    system("pause");
}