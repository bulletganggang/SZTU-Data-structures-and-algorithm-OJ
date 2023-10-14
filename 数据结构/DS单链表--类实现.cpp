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
    {
        int j=0;
	    node *p;
	    p=head;
	    while(p && j<i-1) 
        { 
		p=p->next;
		++j;
	    }
	    if(!p || j>i-1) 
        {
		    return NULL;
	    }  
        else return p; 
    }
    int insert2(int i,int item)
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
    int get(int i)
    {
        if (i<1 or i>len+1)
        {
            cout<<"error"<<endl;
            return error;
        }
        int j=0;
        node *p;
        p=head;
        while (p!=NULL and j<i)
        {
            p=p->next;
            j++;
        }
        if (p==NULL)
        {
            cout<<"error"<<endl;
            return error;
        }
        cout<<p->data<<endl;
        return ok;
    }
    int insert1(int i,int item)
    {
        if (i<1 or i>len+1)
        {
            cout<<"error"<<endl;
            return error;
        }
        int j=0;
        node *p;
        p=head;
        while (p!=NULL and j<i-1)
        {
            p=p->next;
            j++;
        }
        if (p==NULL or p->next==NULL)
        {
            cout<<"error"<<endl;
            return false;
        }
        node *q=new node;
        q->data=item;
        q->next=p->next;
        p->next=q;
        len++;
        show();
        return ok;
    }
    int del(int i)
    {
        if (i<1 or i>len+1)
        {
            cout<<"error"<<endl;
            return error;
        }
        int j=0;
        node *p;
        p=head;
        while (p!=NULL and j<i-1)
        {
            p=p->next;
            j++;
        }
        if (p==NULL or p->next==NULL)
        {
            cout<<"error"<<endl;
            return false;
        }
        node *q=new node;
        q=p->next;
        p->next=q->next;
        len--;
        free(q);
        show();
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
        l.insert2(i,x);
    }
    
    l.show();
    for (int i = 0; i < 2; i++)
    {
        int a,b;
        cin>>a>>b;
        l.insert1(a,b);
    }
    for (int i = 0; i < 2; i++)
    {
        int a;
        cin>>a;
        l.del(a);
    }
    for (int i = 0; i < 2; i++)
    {
        int a;
        cin>>a;
        l.get(a);
    }
    system("pause");
}