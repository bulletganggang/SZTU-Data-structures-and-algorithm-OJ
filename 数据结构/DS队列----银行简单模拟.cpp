#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    queue<int> a,b;//a ji b ou
    while (t--)
    {
        int x;
        cin>>x;
        if (x%2==0)
        {
            b.push(x);
        }
        else a.push(x);
    }
    while (!a.empty() and !b.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
        cout<<a.front()<<" ";
        a.pop();
        cout<<b.front()<<" ";
        b.pop();
    }
    while (!a.empty())
    {
        cout<<a.front();
        a.pop();
        if (a.empty())
        {
            cout<<endl;
        }
        else cout<<" ";
    }
    while (!b.empty())
    {
        cout<<b.front();
        b.pop();
        if (b.empty())
        {
            cout<<endl;
        }
        else cout<<" ";
    }
    system("pause");
}