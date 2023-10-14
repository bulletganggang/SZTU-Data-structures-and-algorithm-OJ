#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    queue<int> q;
    int a[105];
    int n=0;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin>>m;
        a[i]=m;
        if (q.empty())
        {
            q.push(m);
            n++;
        }
        else if (m>q.back() and n<5)
        {
            q.push(m);
            n++;
        }
        else if (n==5 and m>q.back())
        {
            q.pop();
            q.push(m);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int m=q.front();
        q.pop();
        for (int i = 0; i < t; i++)
        {
            if (m==a[i])
            {
                cout<<i+1<<" ";
                break;
            }
        }
    }
    system("pause");
}