#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

const int maxn = 1e4 + 10;
int max(int x, int y) { return x > y ? x : y; }
int n, a;
int dp[maxn][2];

int main()
{
    while (cin>>n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 0;  //0不取  1取
        for (int i = 1; i <= n; i++)
        {
            cin>>a;
            // TODO: 完成状态转移
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if (i == 1) dp[i][1] = a;
            else dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a;
        }
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}
