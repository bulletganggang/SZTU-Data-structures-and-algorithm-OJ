#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const char f[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

queue<char> a;  //xiao
stack<char> b;  //zheng

void sol(double item,int i2)
{
	int k = i2;
	int zheng;  //zhengshu
	double xiao;  //xiaoshu
	for (int i = 0; i < 2; i++)
	{
		zheng = (int)item;
		xiao = item - zheng;
	}
		int yu;
		while (zheng)  //zheng
		{
			yu = zheng % k;
			b.push(f[yu]);
			zheng /= k;
		}
		for (int j = 0; j < 3; j++)  //xiao
		{
			int z;
			z = xiao * k;
			xiao = xiao * k - z;
			a.push(f[z]);
		}
		while (b.size())
		{
			cout << b.top();
			b.pop();
		}
		cout << ".";
		while (a.size())
		{
			cout << a.front();
			a.pop();
		}
		cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double number;
		int k;
        cin >> number >> k;
		sol(number, k);
	}
	return 0;
}
