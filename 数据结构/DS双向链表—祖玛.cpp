#include<iostream>
#include<string>
using namespace std;

class node
{
public:
 char ch;
 int data;
 node* next;
 node* prior;
};

void create(node* head, int n, string s)
{
    node* tail = head;
    head->data = 0;
    char ch;
    for (int i = 0; i < n; i++)
    {
        node* pnew = new node;
        pnew->next = NULL;
        pnew->prior = tail;
        pnew->ch = s[i];
        tail->next = pnew;
        tail = pnew;
        head->data++;
    }
}

void print(node* head)
{
    node* h = head->next;
    if (!head->data) cout << "-";
    else
    {
        for (int i = 0; i < head->data; i++)
        {
            cout << h->ch;
            h = h->next;
        }
    }
}

//插入
void insert(node* head, int index, char ch)
{
    node* p = head->next;
    if (index)
    {
        for (int i = 1; i < index; i++)
            p = p->next;
        
        node* pnew = new node;
        pnew->ch = ch;
        pnew->prior = p;
        pnew->next = p->next;
        p->next = pnew;
        
        if (pnew->next)
            pnew->next->prior = pnew;
        
        head->data++;
    }
    else if (head->data)
    {
        p = head;
        node *pnew = new node;
        
        pnew->ch = ch;
        pnew->prior = p;
        pnew->next = p->next;
        p->next = pnew;
        pnew->next->prior = pnew;
        
        head->data++;
    }
    else
    {
        p = head;
        node* pnew = new node;
        pnew->ch = ch;
        pnew->prior = p;
        pnew->next = p->next;
        p->next = pnew;
        head->data++;
    }
}

//遍历检查
void rearch(node* head)
{
 node* p = head->next;
 while (p)
 {
  if (!p->next) break;
  if (p->ch == p->prior->ch && p->ch == p->next->ch)
  {
   int sum = 3;
   node* d0 = p->prior->prior;
   node* d1 = p->next->next;
   if (d1)
    while (d1->ch == p->ch)
    {
     if (!d1->next) break;
     d1 = d1->next;
     sum++;
    }
   if (d1)
   {
    d0->next = d1;
    d1->prior = d0;
   }
   else d0->next = NULL;

   head->data -= sum;
   p = head->next;
  }
  else
   p = p->next;
 }
}

int main()
{
 string s;
 char ch;
 int index;
 cin >> s;
 int n = s.length();
 node *head = new node;
 create(head, n, s);
 int t;
 cin >> t;
 while (t--)
 {
  cin >> index >> ch;
     
  insert(head, index, ch);
  rearch(head);
  print(head);
     
  if (t)cout << endl;
 }
 return 0;
}
