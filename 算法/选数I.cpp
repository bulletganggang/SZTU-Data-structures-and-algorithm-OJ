#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k;
int target=0;
int res=0;

bool sushu(int n)
{
    for (int i=2; i<=sqrt(n); i++ )    
    {
        if(n%i==0)
        {
           return 0;
        }
    }
    return 1;
}

void backtrack(vector<int>& v,int start,int cur)
{
    if (sushu(target) and cur==k)
    {
        res++;
        return;
    }
    for (int i = start; i < n; i++)
    {
        target+=v[i];
        backtrack(v,i+1,cur+1);
        target-=v[i];
    }
}

int main()
{
    vector<int> v;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    backtrack(v,0,0);
    cout<<res<<endl;
    system("pause");
}