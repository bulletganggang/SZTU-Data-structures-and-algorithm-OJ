#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> s;
    stack<char> p;
    int t;
    cin>>t;
    while (t--)
    {
        string op;
        cin>>op;
        int len=op.length();
        int t=0;
        for (int i = 0; i < len; i++)
        {
            if (op[i]=='#' and t!=0)
            {
                t--;
                s.pop();
                continue;
            }
            if (op[i]=='#' and t==0)
            {
                continue;
            }
            s.push(op[i]);
            t++;
        }
        if (t==0)
        {
            cout<<"NULL"<<endl;
            continue;
        }
        int q=t;
        while (t--)
        {
            char x=s.top();
            p.push(x);
            s.pop();
        }
        while (q--)
        {
            char x=p.top();
            cout<<x;
            p.pop();
        }
        cout<<endl;
    }
}