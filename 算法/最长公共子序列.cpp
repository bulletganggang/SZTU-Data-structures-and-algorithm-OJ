#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

//a max

int main()
{
	string n, m;
	while (cin >> n >> m)
	{
		int dp[1005][1005];
		int len1 = n.length(), len2 = m.length();
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++) 
			{
				if (n[i - 1] == m[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[len1][len2] << endl;
	}
}
