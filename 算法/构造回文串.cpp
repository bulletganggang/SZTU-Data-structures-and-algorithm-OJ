#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    while (n%10==0)
    {
        n/=10;
    }
    int t=n,wei=0,num=0,temp=n;
    while (t>9)
    {
        t/=10;
        wei++;
    }
    while (n>9)
    {
        int a=n%10;
        n/=10;
        num+=a*pow(10,wei--);
    }
    num+=n;
    if (temp==num)
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    system("pause");
}