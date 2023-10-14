#include<iostream>
using namespace std;
long long a[1000005];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    int l,r;
    while (m--)
    {
        scanf("%d %d",&l,&r);
        printf("%lld\n",a[r]-a[l-1]);
    }
    system("pause");
    return 0;
}
