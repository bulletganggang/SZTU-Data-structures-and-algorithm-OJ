#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Block 
{
    int l, w, h;
    bool operator<(const Block& other) const 
    {
        return l > other.l || (l == other.l && w > other.w);
    }
};

int main() {
    int n;
    while(cin >> n)
    {
    vector<Block> blocks(n * 6);

    int len = 0;
    for (int i = 0; i < n; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        blocks[len++] = {a, b, c};
        blocks[len++] = {a, c, b};
        blocks[len++] = {b, a, c};
        blocks[len++] = {b, c, a};
        blocks[len++] = {c, a, b};
        blocks[len++] = {c, b, a};
    }

    sort(blocks.begin(), blocks.end());

    vector<int> dp(n * 6, 0);
    int ans = 0;
    for (int i = 0; i < len; i++) 
    {
        dp[i] = blocks[i].h;
        for (int j = 0; j < i; j++) 
        {
            if (blocks[j].l > blocks[i].l && blocks[j].w > blocks[i].w) 
            {
                dp[i] = max(dp[i], dp[j] + blocks[i].h);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    }
    
    system("pause");
    return 0;
}
