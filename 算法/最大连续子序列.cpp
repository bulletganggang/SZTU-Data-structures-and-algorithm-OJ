#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    while (cin>>n)
    {
        if (n==0)
        {
            return 0;
        }
        
        int dp[10005],temp[10005];
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin>>temp[i];
        }

        dp[0]=temp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i]=max(temp[i],dp[i-1]+temp[i]);
        }

        int res=INT_MIN,right=0,left=0;  //最大值和最大值下标
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>res)
            {
                res=dp[i];
                right=i;
            }
            if (dp[i]>=0)
            {
                flag=1;
            }
        }
        
        if (res<=0 and flag==0)
        {
            cout<<0<<" "<<temp[0]<<" "<<temp[n-1]<<endl;
            continue;
        }

        // cout<<left<<" "<<right<<endl;

        int sum=0;
        for (int i = right; i >= 0 ; i--)
        {
            sum+=temp[i];
            if (sum==res)
            {
                left=i;
                break;
            }
        }

        // cout<<left<<" "<<right<<endl;

        cout<<res<<" "<<temp[left]<<" "<<temp[right]<<endl;
    }
    system("pause");
}