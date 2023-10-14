#include<iostream>
using namespace std;

class node
{
public:
    int p;
    node(){p=0;}
};

int main()
{
    int n;
    cin>>n;
    int t=n*(n-1)*(n-2);
    node tree[n+1];
    while (t--)
    {
        int i,j,k,type;
        cin>>i>>j>>k>>type;
        if (type==1)
        {
            tree[i].p=k;
            tree[j].p=k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!tree[i].p)
        {
            cout<<i<<endl;
            break;
        }
    }
    system("pause");
}