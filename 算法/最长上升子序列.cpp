#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;
const int mod=1000000007;

//a max

int ef(int* s, int r, int x)
{
	int l = 1;
	while (l<=r)
	{
		int mid = l + (r - l) / 2;
		if (s[mid] <= x)
		{
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return l;
}

int main()
{
	int n, b;
	while (cin >> n >> b)
	{
		int s[1000005],low[1000005];
		memset(s, 0, sizeof(s));
		memset(low, 0x7f7f7f, sizeof(low));
		//memset(dp, 0, sizeof(dp));
		s[1] = b;
		low[1] = s[1];
		for (int i = 2; i <= n; i++) 
		{
			s[i] = 1LL * (s[i - 1] + 1) * (s[i - 1] + 1) % mod;
		}
		int sum = 1;
		for (int i = 2; i <= n; i++)
		{
			if (s[i] > low[sum])
			{
				low[++sum] = s[i];
			}
			else low[ef(low, sum, s[i])] = s[i];
		}
		cout << sum << endl;
	}
}
