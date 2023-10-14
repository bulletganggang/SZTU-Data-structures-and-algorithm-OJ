#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> m;
vector<bool> used;
int minTime = INT_MAX;

//回溯  超时
void backtrack(int curRow, int curTime) 
{
    if (curRow == n) 
    {
        minTime = min(minTime, curTime);
        return;
    }

    for (int i = 0; i < n; i++) 
    {
        if (!used[i]) 
        {
            used[i] = true;
            backtrack(curRow + 1, curTime + m[curRow][i]);
            used[i] = false;
        }
    }
}

int main() 
{
    cin >> n;
    m.resize(n, vector<int>(n));
    used.resize(n, false);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> m[i][j];
        }
    }

    backtrack(0, 0);
    cout << minTime << endl;

    return 0;
}

//动态规划  AC

int n;
vector<vector<int>> m;
vector<vector<int>> dp;

int solve(int i, int mask) 
{
    if (i == n) 
    {
        return 0;
    }
    
    if (dp[i][mask] != -1) 
    {
        return dp[i][mask];
    }
    
    int minTime = INT_MAX;
    for (int j = 0; j < n; j++) 
    {
        if (!(mask & (1 << j))) 
        {
            int time = m[i][j] + solve(i + 1, mask | (1 << j));
            minTime = min(minTime, time);
        }
    }
    
    dp[i][mask] = minTime;
    return minTime;
}

int main() 
{
    cin >> n;
    m.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(1 << n, -1));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> m[i][j];
        }
    }
    
    cout << solve(0, 0) << endl;
    system("pause");
    return 0;
}
