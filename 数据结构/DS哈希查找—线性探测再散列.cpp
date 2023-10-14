#include<iostream>
using namespace std;

int tab[105];

int hah(int key)
{
    return key%11;
}

void find(int x,int m)
{
    int key=hah(x);
    for (int i = 0; i < m; i++)
    {
        if (tab[(key+i)%m]==x)
        {
            cout<<"1 "<<i+1<<" "<<(key+i)%m+1<<endl;
            return;
        }
        else if(tab[(key+i)%m]==-1)
        {
            cout<<"0 "<<i+1<<endl;
            return;
        }
    }
}

void create()
{
    int m,n;
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        tab[i]=-1;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        int key=hah(x);
        while (tab[key]!=-1)
        {
            key++;
            key%=m;
        }
        tab[key]=x;
    }
    for (int i = 0; i < m; i++)
    {
        if (tab[i]!=-1)
        {
            cout<<tab[i];
        }
        else cout<<"NULL";
        if (i!=m-1) cout<<" ";
    }
    cout<<endl;
    int t;
    cin>>t;
    while (t--)
    {
        int x;
        cin>>x;
        find(x,m);
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        create();
    }
    system("pause");
}