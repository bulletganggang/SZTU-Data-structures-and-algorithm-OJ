#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#define MAX_NODES 1050
#define MAX_EDGES (MAX_NODES << 4)
#define INF 0x7f7f7f
using namespace std;
typedef long long LL;
typedef long double LD;

struct Node {
    int v, c, w;
    Node *next, *rev;
} edgePool[MAX_EDGES], *head[MAX_NODES << 2], *prevEdge[MAX_NODES << 2];

int n, m, k, edgeCount, weights[MAX_NODES], source, sink, maxFlow, minCost, inQueue[MAX_NODES << 2], dist[MAX_NODES << 2], cost[MAX_NODES << 2], q[MAX_NODES << 5];

inline void addEdge(int u, int v, int c, int w) {
    Node* p = &edgePool[edgeCount++];
    Node* q = &edgePool[edgeCount++];
    *p = {v, c, w, head[u], q};
    head[u] = p;
    *q = {u, 0, -w, head[v], p};
    head[v] = q;
}

bool SPFA() {
    int front = 0, rear = 1;

    for (int i = source; i <= sink; ++i) {
        cost[i] = inQueue[i] = 0;
        dist[i] = -2e9;
    }

    q[0] = source;
    dist[source] = 0;
    cost[source] = INF;

    while (front < rear) {
        int u = q[front++];
        inQueue[u]--;

        for (Node* p = head[u]; p; p = p->next) {
            if (p->c && dist[p->v] < dist[u] + p->w) {
                prevEdge[p->v] = p;
                cost[p->v] = min(p->c, cost[u]);
                dist[p->v] = dist[u] + p->w;
                if (!inQueue[p->v]) {
                    inQueue[p->v]++;
                    q[rear++] = p->v;
                }
            }
        }
    }

    if (dist[sink] <= -2e9) {
        return false;
    }

    maxFlow += dist[sink];
    minCost += dist[sink] * cost[sink];

    int u = sink;

    while (u != source) {
        prevEdge[u]->c -= cost[sink];
        prevEdge[u]->rev->c += cost[sink];
        u = prevEdge[u]->rev->v;
    }

    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    sink = n + 1;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &weights[i]);
    }

    addEdge(source, 1, k, 0);

    for (int i = 1; i <= n; ++i) {
        addEdge(i, min(i + m, n + 1), 1, weights[i]);
    }

    for (int i = 1; i <= n; ++i) {
        addEdge(i, i + 1, INF, 0);
    }

    while (SPFA());

    printf("%d", minCost);

    system("pause");
    return 0;
}
