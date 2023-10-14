#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[105];
    char b[105];
    bool yes[105];  //是否为乘号
    long long num=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        yes[i]=0;
    }
    for (int i = 0; i < n-1; i++)
    {
        cin>>b[i];
    }
    int a1=1,b1=0;
    for (int i = 0; i < n-1; i++)
    {
        if (b[b1]=='+')
        {
            b1++;
            a1++;
        }
        else if (b[b1]=='-')
        {
            b1++;
            a[a1]*=-1;
            a1++;
        }
        else if(b[b1]=='*')
        {
            yes[a1]=1;
            b1++;
            a1++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (yes[i])
        {
            int j=i-1;
            while (a[j]==0)
            {
                j--;
            }
            a[j]=a[i]*a[j];
            a[i]=0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        num+=a[i];
    }
    cout<<num<<endl;
    system("pause");
}