#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        stack<char> c;
        string op;
        cin>>op;
        int len=op.length();
        int flag=1;
        for (int i = 0; i < len; i++)
        {
            if (op[i]=='(' or op[i]=='{' or op[i]=='[')
            {
                c.push(op[i]);
            }
            if (op[i] ==')' or op[i] =='}' or op[i] ==']')
            {
                if (c.empty())
                {
                    flag=0;
                    break;
                }
            }
            if (op[i]==')')
            {
                if (c.top()=='(')
                {
                    c.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(op[i]=='}')
            {
                if (c.top()=='{')
                {
                    c.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if (op[i]==']')
            {
                if (c.top()=='[')
                {
                    c.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if (flag ==0 or !c.empty())
        {
            cout<<"error"<<endl;
        }
        if ((flag==1) and c.empty())
        {
            cout<<"ok"<<endl;
        }
    }
}