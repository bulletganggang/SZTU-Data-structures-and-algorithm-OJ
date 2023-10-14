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
    }
    len=0;
    head = NULL;
}

node* hb(node *a, node *b)
    {
        node* preHead = new node();
        node *head = preHead;
        while (a and b)
        {
            if (a->data < b->data)
            {
                head->next=a;
                a=a->next;
            }
            else 
            {
                head->next=b;
                b=b->next;
            }
            head=head->next;
        }
            while (a)
            {
                head->next=a;
                a=a->next;
                head=head->next;
            }
            while (b)
            {
                head->next=b;
                b=b->next;
                head=head->next;
            }
            return preHead->next->next;
    }

int main()
{
    list l1,l2;
    int t1,t2;
    cin>>t1;
    for (int i = 1; i <= t1; i++)
    {
        int x;
        cin>>x;
        l1.insert(i,x);
    }
    cin>>t2;
    for (int i = 1; i <= t2; i++)
    {
        int x;
        cin>>x;
        l2.insert(i,x);
    }
    l1.head= hb(l1.head,l2.head);
    l1.show();
    system("pause");
}