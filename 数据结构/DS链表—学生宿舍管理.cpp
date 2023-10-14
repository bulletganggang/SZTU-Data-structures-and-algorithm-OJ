#include <iostream>
using namespace std;
#define ok 0

class node 
{
	public:
		int data;	//房间号 
		string name;	//住户名 
		node *next;
		node() 
        {
			next = NULL;
		}
};

class LinkList 
{
	public:
		node *head;
		int len;
		LinkList() 
        {
			head = new node;
			len = 0;
		}
		~LinkList() 
        {
			node *p,*q;
			p=head;
			while(p != NULL) {
				q = p;
				p = p->next;
				delete q;
			}
			len = 0;
			head = NULL;
		}
		node * index(int i) 
        {
			node *p = head;
			for(int j = 1; j <= i; j++ ) 
            {
				p = p->next;
			}
			return p;
		}
		node push_back(int num,string na = "") 
        { 
			node *p = new node;
			node *q = index(len);
			p->data = num;
			p->name = na;
			q->next = p;
			len++;
			return *p;
		}
		int get(int i) 
        {
            node *p = index(i);
			return p->data;
		}
		int insert(int i, string na, int item) 
        {
            node *p = index(i-1);
			node *temp;
			temp = p->next;
			node *q = new node;
			q->data = item;
			q->name = na;
			p->next = q;
			q->next = temp;
			len++;
            return ok;
		}
		int del(int i) 
        {
            node *p = index(i-1);
			node *temp = p->next;
			p->next = p->next->next;
			len--;
			temp->next=NULL;
			delete temp;
            return ok;
		}
		void display_free() 
        {
			node *p;
			p = head->next;
			while(p) 
            {
				cout<< p->data;
				if(p->next != NULL)
                {
					cout<<"-";
				}
				p = p->next;
			}
			cout<<endl;
		}
		void display_used() 
        {
			node *p;
			p = head->next;
			while(p) 
            {
				cout<<p->name<<"("<< p->data <<")";
				if(p->next != NULL) 
                {
					cout<<"-";
				}
				p = p->next;
			}
			cout<<endl;
		}
};

int main() 
{
	int n, room;
	string name;
	LinkList free;
	for(int i = 101; i <= 120; i++) 
    { 
		free.push_back(i,"1");
	}
	LinkList used;	
	cin>>n;
	while(n--) 
    {
		cin>>name>>room;
		used.push_back(room, name); 
		for(int i = 1; i <=free.len; i++) 
        {
			if(free.get(i) == room) 
            {
				free.del(i);
				break;
			}
		}
	}
	cin>>n;
	while(n--) 
    {
        string op;
		cin>>op;
		if(op == "assign") 
        {	
			cin>>name;
			room=free.get(1);	 
			free.del(1);	
			for(int i = 1; i <= used.len; i++) 
            {	
				if(used.get(i) > room) 
                {		 
					used.insert(i, name, room); 
					break;
				}
			}
		}
		if(op == "return") 
        {
			cin>>room;
			for(int i = 1; i <= used.len; i++) 
            {	
				if(used.get(i) == room) 
                {	
					used.del(i);
				}
			
			}
			free.push_back(room);
		
		}
		if(op == "display_used") 
        {
			used.display_used();
		}
		if(op == "display_free") 
        {
			free.display_free();
		}
	}
}
