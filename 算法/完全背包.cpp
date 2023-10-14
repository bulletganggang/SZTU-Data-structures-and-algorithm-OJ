#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;
//a max

int main()
{
	int n, b;
	while (cin >> n >> b)
	{
		int q[1005], w[10005];
		memset(q, 0, sizeof(q));
		memset(w, 0, sizeof(w));
		for (int i = 1; i <= n; i++)
		{
			cin >> q[i] >> w[i];
		}
		int dp[10005];
		memset(dp, 0, sizeof(dp));
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = q[i]; j <= b; j++)
			{
				dp[j] = max(dp[j - q[i]] + w[i], dp[j]);
			}
		}
		cout << dp[b] << endl;
	}
}

/*
int n,w;
int wt[1010],val[1010];
int dp[1010][1010];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&wt[i],&val[i]);
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=w; j++)
        {
            dp[i][j]=dp[i-1][j];//继承上一个背包
            if(j>=wt[i])
            {  //完全背包状态转移方程
                dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i]]+val[i]);
            }
        }
    printf("%d",dp[n][w]);
    system("pause");
    return 0;
}

*/