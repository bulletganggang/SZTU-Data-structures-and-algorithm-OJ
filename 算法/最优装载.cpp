#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v;
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int sum = 0, nsum = 0;
		for (int i = 0; i < m; i++)
		{
			sum += v[i];
			if (sum <= n)
			{
				nsum++;
			}
			else break;
		}
		cout << nsum << endl;
	}
}