#include<iostream>
using namespace std;

void pre(int i,int *tree)
{
    if (tree[i] and i<=tree[0])
    {
    cout<<tree[i]<<" ";
    pre(2*i,tree);
    pre(2*i+1,tree);
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int tree[n+1];
        tree[0]=n;
        for (int i = 1; i <= n; i++)
        {
            cin>>tree[i];
        }
        pre(1,tree);
        cout<<endl;
    }
    system("pause");
}