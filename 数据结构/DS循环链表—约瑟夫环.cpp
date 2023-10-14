#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;
    friend class LinkList;
};

class LinkList 
{
    int len;
    node *head;
public:
    int n, k, s;
    LinkList();
    ~LinkList();
    void CreateList();
    void Test();
};

LinkList::LinkList()
{
    head = new node;
}

LinkList::~LinkList()
{
    delete head;
}

void LinkList::CreateList()
{
    len = n;
    node *p = head;
    node *q;
    for(int i=1; i<=n; i++)
    {
        q = new node;
        q->data = i;
        p->next = q;
        p = p->next;
    }
    p->next = head;
} 

void LinkList::Test()
{
    int i;
    node *p = head;
    for(i=0; i<s-1; i++)
        p = p->next;
    while(len)
    {
    	if(p->next==head)
                p = p->next;
        for(i=0; i<k-1; i++)
        {
            p = p->next;
            if(p->next==head)
                p = p->next;
        }
        node *q = p->next;
        cout<<q->data;
        len--;
        if (len>0)
        {
            cout<<" ";
        }
        p->next = q->next;
        delete q;
    }
    cout<<endl;
}

int main()
{
    int N, K, S;
    while(scanf("%d%d%d", &N, &K, &S)!=EOF)
    {
        LinkList list;
        list.n = N;
        list.k = K;
        list.s = S;
        list.CreateList();
        list.Test();
    }
    system("pause");
    return 0;
}