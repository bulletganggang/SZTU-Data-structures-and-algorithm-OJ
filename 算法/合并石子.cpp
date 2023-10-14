#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int n;
    int dpmax[505][505],dpmin[505][505];
    int a[505],b[505];
    cin>>n;
	memset(dpmin, 0x7f7f7f, sizeof(dpmin));
	memset(dpmax, 0, sizeof(dpmax));
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		a[i + n] = a[i];
		dpmin[i][i] = 0;
		dpmin[i + n][i + n] = 0; 
	}
	b[0] = 0;
		
	for(int i = 1; i <= 2 * n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
	for(int x = 2; x <= n; x++)
	{
		for(int i = 1; x + i - 1 <= 2 * n; i++)
		{
			int j = x + i - 1;
			for(int k = i; k < j; k++)
			{
				dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + b[j] - b[i - 1]);
				dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + b[j] - b[i - 1]);
			}
		}
	}
	int amin = 0x7f7f7f,amax = -1;
	for(int i = 1; i <= n; i++)
	{
		amin = min(amin, dpmin[i][i+n-1]);
		amax = max(amax, dpmax[i][i+n-1]);
	}
	cout << amin << endl<< amax << endl;
    system("pause");
}