#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int dp[220][11];

int main()
{
    int n, k;
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    while(cin>>n>>k)
    {
        for (int i = 1 ; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j<=k) dp[i][j]=dp[i - j][j]+dp[i - 1][j - 1];
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}