#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    string s;
    while (cin>>s)
    {
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for (int i=0;i<=s.length();i++) dp[i][i] = 1;
        for (int i=s.length()-2;i>=0;i--)
        {
            for (int j=i;j<s.length();j++)
            {
                dp[i][j] = dp[i+1][j] + 1;
                for (int k=i+1;k<=j;k++)
                {
                    if ((s[i] == '(' && s[k] == ')') || (s[i] == '[' && s[k] == ']') || (s[i] == '{' && s[k] == '}'))
                    {
                        dp[i][j] = min(dp[i+1][k-1]+dp[k+1][j],dp[i][j]);
                    }
                }
            }
        }

        sum = dp[0][s.length()-1];
        if(sum) cout<<sum<<endl;
        else cout<<"SZTU_WOD YYDS!"<<endl;
    }
}