#include <iostream>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	long long m, n;
	cin >> m >> n;
	long long dp[30][30];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[m][n] << endl;
}