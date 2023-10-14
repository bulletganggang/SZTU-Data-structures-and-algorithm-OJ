#include<iostream>
using namespace std;
#define ok 0
#define error -1

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(){next = NULL;pre=NULL;}
};

class list
{
public:
    node *head;
    int len;
    list();
    ~list();
    void Create(int n) 
    {
		len = n;
		int k;
		node* p = head;
		for (int i = 1;i <= len;i++) 
        {
			node* q = new node();
			cin >> k;
			q->data = k;
			p->next = q;
			q->pre = p;
			p = q;
		}
    }
    node* find(int k) 
    {
		node* p = head;
 
		while (p->next != NULL) 
        {
			p = p->next;
			if (p->data == k) 
            {
				return p;
			}
		}
        return NULL;
	}
	void print(int k) 
    {
		find(k);
		if ((find(k)->next != NULL) && (find(k)->pre != head)) 
        {
			cout << find(k)->pre->data << " " << find(k)->next->data << endl;
		}
		else if (find(k)->pre ==head) 
        {
			
			cout << find(k)->next->data << endl;
		}
		else 
        {
			cout << find(k)->pre->data << endl;
		}
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
    int n,m;
    cin>>n>>m;
    l.Create(n);
    while (m--)
    {
        int x;
        cin>>x;
        l.print(x);
    }
    system("pause");
}