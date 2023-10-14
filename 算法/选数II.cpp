#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int INF = 0x7f7f7f;
const int MAXN = 10010;

int head[MAXN], mcnt = 1;
int S, T, SS, TT;
int a[MAXN];
int cost = 0;
queue<int> q;
int dis[MAXN];
bool inq[MAXN];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct Edge
{
    int v, nxt, f, w;
} edges[MAXN << 3];

void addEdge(int u, int v, int f, int c)
{
    edges[++mcnt].v = v;
    edges[mcnt].nxt = head[u];
    edges[mcnt].f = f;
    edges[mcnt].w = c;
    head[u] = mcnt;
    return;
}

void insert(int u, int v, int f, int c)
{
    addEdge(u, v, f, c);
    addEdge(v, u, 0, -c);
    return;
}

bool SPFA()
{
    memset(inq, 0, sizeof(inq));
    for (int i = SS; i <= TT; i++)
        dis[i] = INF;
    q.push(SS);
    dis[SS] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = head[u], v; i; i = edges[i].nxt)
        {
            v = edges[i].v;
            if (edges[i].f && dis[v] > dis[u] + edges[i].w)
            {
                dis[v] = dis[u] + edges[i].w;
                if (!inq[v])
                {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[TT] < INF;
}

int DFS(int u, int lim)
{
    if (u == TT)
    {
        inq[u] = 1;
        return lim;
    }
    int f = 0, tmp;
    inq[u] = 1;
    for (int i = head[u]; i; i = edges[i].nxt)
    {
        int v = edges[i].v;
        if (!inq[v] && edges[i].f && dis[u] + edges[i].w == dis[v])
        {
            tmp = DFS(v, min(lim, edges[i].f));
            cost += tmp * edges[i].w;
            edges[i].f -= tmp;
            edges[i ^ 1].f += tmp;
            f += tmp;
            lim -= tmp;
            if (!lim)
                return f;
        }
    }
    return f;
}

int minCostFlow()
{
    int res = 0;
    while (SPFA())
    {
        inq[TT] = 1;
        while (inq[TT])
        {
            for (int i = SS; i <= TT; i++)
                inq[i] = 0;
            res += DFS(SS, INF);
        }
    }
    return res;
}

void solve()
{
    minCostFlow();
    printf("%d\n", -cost);
    return;
}

int main()
{
    int n = read();
    int K = read();
    SS = 0;
    S = 1;
    T = 2 * n + 2;
    TT = T + 1;
    int ed = 3 * n;
    for (int i = 1; i <= ed; i++)
    {
        a[i] = read();
    }
    insert(SS, S, K, 0);
    insert(T, TT, K, 0);
    for (int i = 1; i <= n; i++)
    {
        insert(S, i + 1, 1, -a[i]);
        insert(i + 1, i + n + 1, 1, -a[i + n]);
        insert(i + n + 1, n + n + 2, 1, -a[i + n + n]);
    }
    for (int i = 2 * n + 1; i; i--)
    {
        insert(i, i + 1, INF, 0);
    }
    solve();
    system("pause");
    return 0;
}
