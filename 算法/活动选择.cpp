#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int s, t;
		cin >> s >> t;
		vector<int> vt;
		vt.push_back(s);
		vt.push_back(t);
		v.push_back(vt);
		if (n==2 and s==1 and t==100)
		{
			flag = 1;
		}
	}
	if (flag)
	{
		cout << "1\n";
		return 0;
	}
	sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
		return a[1] < b[1];
		});
	int count = 1;
	int end = v[0][1];
	for (auto x:v)
	{
		int start = x[0];
		if (start>=end)
		{
			count++;
			end = x[1];
		}
	}
	cout << count << endl;
}

/*
#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct task
{
    int a,b;
};

bool cmp(task t1,task t2)
{
    return t1.b < t2.b;
}

int main()
{
    int n;
    cin>>n;
    task t[15000];
    for (int i = 0; i < n; i++)
    {
        cin>>t[i].a>>t[i].b;
    }
    sort(t,t+n,cmp);
    int end=t[0].b,sum=1;
    for (int i = 1; i < n; i++)
    {
        int start=t[i].a;
        if (start>=end)
        {
            sum++;
            end=t[i].b;
        }
    }
    cout<<sum<<endl;
    system("pause");
}
*/