#include<iostream>
#include<math.h>
using namespace std;

long long solve(long long x,long long n,long long &num)
{
    if (n==0) return num;
    num=num*x+num;
    n--;
    return solve(x,n,num);
}

int main()
{
    long long x,n,num=1;
    while(cin>>x>>n)
    {
        cout<<solve(x,n,num)<<endl;
    }
    return 0;
}