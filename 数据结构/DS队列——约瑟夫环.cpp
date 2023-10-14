#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        int m=0;
        cin>>n>>k;
        queue<int> q;  //1
        queue<int> p;  //2
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        int x=0;
        while (!q.empty() or !p.empty())
        {
            while (!q.empty())
            {
                x++;
                if (x%k==0)
                {
                    cout<<q.front();
                    m++;
                    if (m!=n)
                    {
                        cout<<" ";
                    }
                }
                else 
                {
                    p.push(q.front());
                } 
                q.pop();
            }
            while (!p.empty())
            {
                x++;
                if (x%k==0)
                {
                    cout<<p.front();
                    m++;
                    if (m!=n)
                    {
                        cout<<" ";
                    }
                }
                else 
                {
                    q.push(p.front());
                } 
                p.pop();
            }
        }
        cout<<endl;
    }
}