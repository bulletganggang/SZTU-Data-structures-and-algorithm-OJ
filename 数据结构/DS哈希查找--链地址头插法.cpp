#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *s[11];

void add(int key)  //头插法
{
    node *p=new node;
    p->data=key;
    p->next=s[key%11];
    s[key%11]=p;
}

int main()
{
    int n;
    while (cin>>n)
    {
    for (int i = 0; i < 11; i++)
    {
        s[i]=NULL;
    }
    while (n--)
    {
        int key;
        cin>>key;
        add(key);
    }
    int t;
    cin>>t;
    while (t--)
    {
        int key;
        cin>>key;
        node *p=s[key%11];
        int k=0;
        while(p)
        {
            k++;
            if (p->data==key)
            {
                break;
            }
            p=p->next;
        }
        if (!p)
        {
            cout<<"error\n";
            add(key);
        }
        else cout<<key%11<<" "<<k<<endl;
    }
    }
}