#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
vector<vector<int>> graph;
vector<int> colors;
int count = 0;

bool isSafe(int node, int color) 
{
    for (int i = 0; i < n; i++) 
    {
        if (graph[node][i] && colors[i] == color) 
        {
            return false;
        }
    }
    return true;
}

void backtrack(int node) 
{
    if (node == n) 
    {
        count++;
        return;
    }

    for (int color = 1; color <= m; color++) 
    {
        if (isSafe(node, color)) 
        {
            colors[node] = color;
            backtrack(node + 1);
            colors[node] = 0;
        }
    }
}

int main() 
{
    cin >> n >> m >> q;
    graph.resize(n, vector<int>(n, 0));
    colors.resize(n, 0);

    for (int i = 0; i < q; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    backtrack(0);

    cout << count << endl;
    system("pause");
    return 0;
}