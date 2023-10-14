#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODES 2000
#define MAX_nodeS 50000
#define LL long long
#define INF 0x3f3f3f3f

struct node 
{
    LL to, next, flow, cost;
} 
nodes[MAX_nodeS];

LL head[MAX_NODES], dist[MAX_NODES], last[MAX_NODES], visited[MAX_NODES], a[MAX_NODES];
LL nodeCnt = -1, n, m, source, sink;
queue<LL> q;

void addnode(LL u, LL v, LL w, LL c) {
    nodes[++nodeCnt] = {v, head[u], w, c};
    head[u] = nodeCnt;
    nodes[++nodeCnt] = {u, head[v], 0, -c};
    head[v] = nodeCnt;
}

bool findEnteringColumn() {
    memset(last, -1, sizeof(last));
    memset(dist, 0x3f, sizeof(dist));
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        visited[u] = 0;

        for (LL i = head[u]; ~i; i = nodes[i].next) {
            LL v = nodes[i].to;
            if (dist[v] > dist[u] + nodes[i].cost && nodes[i].flow) {
                dist[v] = dist[u] + nodes[i].cost;
                last[v] = i;
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    return ~last[sink];
}

LL simplex() {
    LL ans = 0;

    while (findEnteringColumn()) {
        LL flow = INF;

        for (LL i = last[sink]; ~i; i = last[nodes[i ^ 1].to]) {
            flow = min(flow, nodes[i].flow);
        }

        for (LL i = last[sink]; ~i; i = last[nodes[i ^ 1].to]) {
            nodes[i ^ 1].flow += flow;
            nodes[i].flow -= flow;
            ans += flow * nodes[i].cost;
        }
    }

    return ans;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%lld %lld", &n, &m);
    source = 0;
    sink = n + 2;

    for (LL i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (LL i = 1; i <= n; i++) {
        addnode(i + 1, i, INF, 0);
    }

    for (LL i = 1, u, v, w; i <= m; i++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        addnode(u, v + 1, INF, w);
    }

    for (LL i = 1; i <= n + 1; i++) {
        if (a[i] - a[i - 1] > 0) {
            addnode(source, i, a[i] - a[i - 1], 0);
        } else {
            addnode(i, sink, a[i - 1] - a[i], 0);
        }
    }

    printf("%lld\n", simplex());
    system("pause");
    return 0;
}
