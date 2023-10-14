#include<iostream>
using namespace std;

int main()
{
    int n,m[1005];
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        m[i]=0;
    }
    m[1]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i/2; j++)
        {
            m[i]+=m[j];
        }
        if (i!=1) m[i]++;
    }
    cout<<m[n]<<endl;
    system("pause");
}