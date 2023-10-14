#include <iostream>
using namespace std;
#define ok 0

class node 
{
public:
    int data; // 系数
    int index; 	//指数
    node *next;
    node() 
	{
        next = NULL;
    }
};
class LinkList 
{
private:
    node *head;
    int len;
public:
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
    node create(int n) 
	{
        len = n;
        node* pnew = NULL;
        node* tail = NULL;
        head->data = 0;
        head->next = NULL;
        tail = head;
        for ( int i = 1; i < len + 1; i++) 
		{
            pnew = new node();
            cin >> pnew->data >> pnew->index;
            pnew->next = NULL;
            tail->next = pnew;
            tail = pnew;
        }
        return *head;
    }

	 void display() {
        node* p = head->next;
        if (head->next == NULL) 
		{
            cout << "0" << endl;
            return;
        }
        while (p) 
		{
            if (p->data >= 0) 
			{
                if (p->data == 0) 
				{
                    while (p->next&&p->next->data == 0) { p = p->next; }
                    if (p->next&&p->next->index == 0) { cout << p->next->data; p = p->next; }
                    else if (p->next && p->next->data != 0) {NULL; }
                    else { cout << "0"; }
				}
                else 
				{
                    if (p->index == 1) 
					{
                        if (p->data == 1) { cout << "x"; }
 
                        else { cout << p->data << "x"; }
                    }
                    if (p->index == 0) 
					{
                        cout << p->data;
                    }
                    if (p->index > 1) 
					{
                        if (p->data == 1) { cout << "x^" << p->index;}
                        else{cout << p->data << "x^" << p->index;}
                    }
                    if (p->index < 0) 
					{
                        if (p->data == 1) { cout << "x^(" << p->index << ")"; }
                        else{cout << p->data << "x^(" << p->index<<")";}
                    }
                    while (p->next && p->next->data == 0) { p = p->next; }                
                    if (p->next&&p->data==0&& p->next->data != 0) { cout << "+"; }
 
                }
                if (p->next && p->next->data > 0&&p->data!=0) { cout << "+"; }
            }
            else 
			{
                if (p->index == 1) 
				{
                    if (p->data == -1) { cout << "-x"; }
                    else { cout << p->data << "x"; }
                }
                if (p->index == 0) 
				{
                    cout << p->data;
                }
                if (p->index > 1) 
				{
                    if (p->data == -1) { cout << "-x^" << p->index; }
                    else { cout << p->data << "x^" << p->index; }
                }
                if (p->index < 0) 
				{
                    if (p->data == -1) { cout << "-x^(" << p->index << ")"; }
                    else { cout << p->data << "x^(" << p->index << ")"; }
                }
                if (p->next && p->next->data == 0) { p = p->next; }
                if (p->next && p->next->data > 0) { cout << "+"; }
            }
            p = p->next;
        }
        cout << endl;
        return;
    }
 
    LinkList* add(LinkList* b) 
	{
        LinkList* temp = new LinkList();
        node* t = (*temp).head;
        node* p = head->next;
        node* q = b->head->next;
        while (p && q) 
		{
            node* m = new node;
            if (p->index == q->index) 
			{
                m->data = p->data + q->data;
                if (m->data != 0) 
				{
                    m->index = p->index;
                    t->next = m;
                    t = m;
                    m->next = NULL;
                    temp->len++;
                }
                p = p->next;
                q = q->next;
                continue; 
            }
            if (p->index < q->index) 
			{
                m->data = p->data;
                m->index = p->index;
                t->next = m;
                t = m;
                p = p->next;
                temp->len++;
                continue;
            }
            if (p->index > q->index) 
			{
                m->data = q->data;
                m->index = q->index;
                t->next = m;
                t = m;
                q = q->next;
                temp->len++;
            }
        }
        while (p) 
		{
            node* m = new node;
            m->data = p->data;
            m->index = p->index;
            t->next = m;
            t = m;
            p = p->next;
        }
        while (q) 
		{
            node* m = new node;
            m->data = q->data;
            m->index = q->index;
            t->next = m;
            t = m;
            q = q->next;
        }
        return temp;
    }
    LinkList* sub(LinkList* b) 
	{
        LinkList* temp = new LinkList();
        node* t = (*temp).head;
        node* p = head->next;
        node* q = b->head->next;
        while (p && q) 
		{
            node* m = new node;
            if (p->index == q->index) 
			{
                m->data = p->data - q->data;
                if (m->data != 0) 
				{
                    m->index = p->index;
                    t->next = m;
                    t = m;
                    temp->len++;
                }
                p = p->next;
                q = q->next;
                continue;
            }
            if (p->index < q->index) 
			{
                m->data = p->data;
                m->index = p->index;
                t->next = m;
                t = m;
                p = p->next;
                temp->len++;
                continue;
            }
            if (p->index > q->index) 
			{
                m->data = -q->data;
                m->index = q->index;
                t->next = m;
                t = m;
                q = q->next;
                temp->len++;
            }
        }
        while (p) 
		{
            node* m = new node;
            m->data = p->data;
            m->index = p->index;
            t->next = m;
            t = m;
            p = p->next;
            temp->len++;
        }
        while (q) 
		{
            node* m = new node;
            m->data = -q->data;
            m->index = q->index;
            t->next = m;
            t = m;
            q = q->next;
            temp->len++;
        }
        return temp;
    }
 
    LinkList* mul(LinkList* b) 
	{
        LinkList* temp1 = new LinkList();
        node* p = head->next;
        while (p) 
		{
            LinkList* temp2 = new LinkList();
            node* t2 = (*temp2).head; 
            node* q = (*b).head->next; 
            while (q) {
                node* m = new node;
                m->data = q->data * p->data;
                m->index = q->index + p->index;
                t2->next = m;
                t2 = m;
                q = q->next;
            }
            temp1 = temp1->add(temp2); //把每一个第i项相乘的答案temp2 相加到一起就是最终结果
            p = p->next;
        }
        return temp1;
    }
};

int main() 
{
    int data, index, n, n1 ,n2;
    cin>>n;
    while(n--) 
	{
        LinkList *a = new LinkList();
        cin>>n1;
        a->create(n1);
		a->display();
        LinkList *b = new LinkList();
        cin>>n2;
        b->create(n2);
		b->display();
        LinkList *c;
        c = a->add(b);
        c->display();
        c = a->sub(b);
        c->display();
        c = a->mul(b);
        c->display();
		cout<<endl;
    }
	system("pause");
}
