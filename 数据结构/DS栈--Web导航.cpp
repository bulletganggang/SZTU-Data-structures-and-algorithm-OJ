#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string op,x;
    stack<string> a1,a2;  //1qian 2hou 
    x="http://www.acm.org/";
    while (cin>>op)
    {
        if (op=="QUIT")
        {
            break;
        }
        if(op=="VISIT")
        {
            string url;
            cin>>url;
            a1.push(x);
            x=url;
            cout<<x<<endl;
            while (!a2.empty())
            {
                a2.pop();
            }
            continue;
        }
        if (op=="BACK")
        {
            if (!a1.empty())
            {
                a2.push(x);
                x=a1.top();
                a1.pop();
                cout<<x<<endl;
            }
            else
            {
                cout<<"Ignored\n";
            }
        }
        if (op=="FORWARD")
        {
            if (!a2.empty())
            {
                a1.push(x);
                x=a2.top();
                a2.pop();
                cout<<x<<endl;
            }
            else
            {
                cout<<"Ignored\n";
            }
        }
    }
}