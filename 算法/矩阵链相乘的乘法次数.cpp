#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

//a max

int main()
{
	int n;
	while (cin>>n)
	{
		int jz[305];
		for (int i = 0; i < n+1; i++)
		{
			cin >> jz[i];
		}
		int dp[305][305];
		//memset(dp, 0x7f7f7f, sizeof(dp));
		for (int i = 0; i < n + 1; i++)
		{
			dp[i][i] = 0;
		}
		for (int len = 2; len <= n; len++)
		{
			for (int l = 1; l <= n-len+1; l++)
			{
				int r = l + len - 1;
				dp[l][r] = dp[l][l]+dp[l + 1][r] + 1LL * jz[l - 1] * jz[l] * jz[r];
				for (int i = l+1; i < r; i++)
				{
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + jz[l - 1] * jz[i] * jz[r]);
				}
			}
		}
		cout << dp[1][n]<< endl;
	}
}