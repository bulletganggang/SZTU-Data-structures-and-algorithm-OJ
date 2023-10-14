#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> s;
    int t;
    cin>>t;
    while (t--)
    {
        string op;
        cin>>op;
        int len=op.length();
        for (int i = 0; i < len; i++)
        {
            char x=op[i];
            s.push(x);
        }
        for (int i = len-1; i >=0; i--)
        {
            char x=s.top();
            cout<<x;
            s.pop();
        }
        cout<<endl;
    }
    system("pause");
}