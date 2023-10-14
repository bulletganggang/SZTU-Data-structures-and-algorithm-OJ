#include<iostream>
using namespace std;
const int mod = 100003;
int n, k;
long long ans[1111111];

int main()
{
    while(cin>>n>>k)
    {
        ans[0] = 1;
        ans[1] = 1;
        if (k>n)
        {
            k=n;               
        }
        for (int i = 2; i <= n; i++)
        {
            ans[i]=0;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i-j<0)
                {
                    break;
                }
                ans[i]+=ans[i-j];
            }
            ans[i]%=mod;
        }
        cout<<ans[n]%mod<<endl;
    }
    return 0;
}