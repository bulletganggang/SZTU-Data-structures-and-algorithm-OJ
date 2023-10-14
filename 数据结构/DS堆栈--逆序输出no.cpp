#include<iostream>
#include<cstring>
using namespace std;

class stack
{
public:
    char *s;
    int top=-1;
    stack(int len){s=new char[len];}
    void push(char x)
    {
        top++;
        s[top]=x;
    }
    void pop()
    {
        cout<<s[top];
        top--;
    }
};


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string op;
        cin>>op;
        int len=op.size();
        stack c(len);
        for (int i = 0; i < len; i++)
        {
            c.push(op[i]);
        }
        for (int i = 0; i < len; i++)
        {
            c.pop();
        }
        cout<<endl;
    }
    system("pause");
}