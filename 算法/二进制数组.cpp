#include <iostream>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <cstring>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
    int sum=0,maxx=0;
    vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a) sum++;
		else
		{
            v.push_back(sum);
            sum=0;
            v.push_back(0);
		}
	}
    v.push_back(sum);
    
    for(int i=0;i<v.size()-2;i++)
    {
        maxx=max(maxx,v[i]+v[i+1]+v[i+2]);
    }
    cout<<maxx<<endl;
    system("pause");
}
