#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

//a max
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int s[105][105],dp[105][105];
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		int mx = 0;
		int n;
		cin >> n;  //high
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> s[i][j];
			}
		}
		dp[0][0] = s[0][0];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				dp[i][j] = max(dp[i - 1][j] + s[i][j], dp[i - 1][j - 1] + s[i][j]);
				mx = max(dp[i][j], mx);
			}
		}
		/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << mx << endl;
	}
}
