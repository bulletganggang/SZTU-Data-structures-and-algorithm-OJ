#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,sum;
int Pay[3005];
bool dp[3005][3005];  //i为物品种类 j为物品金额

int main()
{
    while (cin>>n)
    {
        //初始化变量
        memset(Pay,0,sizeof(Pay));
        memset(dp,0,sizeof(dp));
        sum=0;
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%d",&Pay[i]);
            sum+=Pay[i];
        }
        if (sum%2)
        {
            cout<<"False"<<endl;
            continue;
        }
        sum/=2;
        //动态规划
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - Pay[i - 1] < 0) 
                {
                    // 背包容量不足，不能装入第 i 个物品
                    dp[i][j] = dp[i - 1][j];
                } 
                else 
                {
                    // 不装入或装入背包
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - Pay[i - 1]];
                }
            }
        }

        if (dp[n][sum]==1)
        {
            cout<<"True"<<endl;
        }
        else cout<<"False"<<endl;

    }
    return 0;
}