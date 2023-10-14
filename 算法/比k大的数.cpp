#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int a[2005];

int main()
{
    memset(a, 0, sizeof(a));
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[x+1000]++;
    }
    while (m--)
    {
        int x;
        cin>>x;
        int num=0;
        for (int i = 0; i <= x+1000; i++)
        {
            num+=a[i];
        }
        cout<<n-num<<endl;
    }
    system("pause");
}
