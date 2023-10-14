#include <iostream>
#include <stdio.h>
using namespace std;

int wei(int n)
{
	int k = 0;
	while (n>1)
	{
		n /= 2;
		k++;
	}
	return k;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int mar[35][35];
		int t = 1;
		int k = wei(n);  //位数
        int nn=n;
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= n + 1; j++)
			{
				mar[i][j] = 0;
			}
		}

		for (int i = 1; i < n+1; i++)
		{
			mar[1][i] = i;
		}

		for (int s = 0; s < k; s++)
		{
			n /= 2;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1+t; j <= 2*t; j++)
				{
					for (int k = 1+t; k <= 2*t; k++)
					{
					    mar[j][k + (i-1)*t*2] = mar[j - t][k + (i-1)*t*2 - t];
					    mar[j][k + (i-1)*t*2 - t] = mar[j - t][k + (i-1)*t*2];
					}
				}
			}
			t *= 2;
		}
		for (int i = 1; i <= nn; i++)
		{
			for (int j = 2; j <= nn; j++)
			{
				cout << mar[i][j] << " ";
			}
			cout << endl;
		}
	}
}
