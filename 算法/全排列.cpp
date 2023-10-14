#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> t;  //t存放路径
int n;
bool used[10]={0};

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void backtrack(vector<int>& nums)
{
    if (t.size()==n)
    {
        print(t);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(used[i]) continue;
        used[i]=1;
        t.push_back(nums[i]);
        backtrack(nums);
        t.pop_back();
        used[i]=0;
    }
}

int main()
{
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    backtrack(v);

    system("pause");
}