#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> a;
    queue<int> b;
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        char op;
        cin>>op;
        a.push(op);
    }
    for (int i = 0; i < t; i++)
    {
        int op;
        cin>>op;
        b.push(op);
    }
    int A=0,B=0,C=0,A1=0,B1=0,C1=0;
    while (!a.empty())
    {
        if (a.front()=='A')
        {
            A+=b.front();
            a.pop();
            b.pop();
            A1++;
        }
        if (a.front()=='B')
        {
            B+=b.front();
            a.pop();
            b.pop();
            B1++;
        }
        if (a.front()=='C')
        {
            C+=b.front();
            a.pop();
            b.pop();
            C1++;
        }
    }
    if (A!=0)
    {
        cout<<A/A1<<endl;
    }
    if (B!=0)
    {
        cout<<B/B1<<endl;
    }
    if (C!=0)
    {
        cout<<C/C1<<endl;
    }
    system("pause");
}