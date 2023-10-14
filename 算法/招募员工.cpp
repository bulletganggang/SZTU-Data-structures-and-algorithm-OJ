#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3fffffff
#define N 26

int repairTime[N], teams[N], first[N], top, T, num, dist[N], cnt[N], used[N];

struct Edge {
    int y, next, weight;
} edges[1000];

void addEdge(int x, int y, int weight) {
    edges[top].y = y;
    edges[top].weight = weight;
    edges[top].next = first[x];
    first[x] = top++;
}

void createGraph(int mid) {
    top = 0;
    memset(first, -1, sizeof(first));
    
    for (int i = 1; i < 24; i++) {
        addEdge(i - 1, i, 0);
        addEdge(i, i - 1, -teams[i]);
    }
    
    addEdge(24, 0, 0);
    addEdge(0, 24, -teams[0]);
    
    for (int i = 8; i < 24; i++) {
        addEdge(i - 8, i, repairTime[i]);
    }
    
    for (int i = 0; i < 8; i++) {
        addEdge(i + 16, i, repairTime[i] - mid);
    }
    
    addEdge(24, 23, mid);
}

int relax(int x, int y, int weight) {
    if (dist[y] < dist[x] + weight) {
        dist[y] = dist[x] + weight;
        return 1;
    }
    return 0;
}

int spfa(int source, int target, int value) {
    queue<int> q;
    
    for (int i = 0; i <= 24; i++) {
        dist[i] = -INF;
    }
    
    dist[source] = 0;
    q.push(source);
    memset(used, 0, sizeof(used));
    used[source] = 1;
    memset(cnt, 0, sizeof(cnt));
    
    while (!q.empty()) {
        int current = q.front();
        used[current] = 0;
        q.pop();
        
        for (int i = first[current]; i != -1; i = edges[i].next) {
            if (relax(current, edges[i].y, edges[i].weight) && !used[edges[i].y]) {
                q.push(edges[i].y);
                used[edges[i].y] = 1;
                cnt[edges[i].y]++;
                
                if (cnt[edges[i].y] == 25) {
                    return 0;
                }
            }
        }
    }
    
    return dist[target] == value;
}

int main() {
    scanf("%d", &T);
    
    while (T--) {
        int low, high, mid;
        memset(teams, 0, sizeof(teams));
        
        for (int i = 0; i < 24; i++) {
            scanf("%d", &repairTime[i]);
        }
        
        scanf("%d", &num);
        
        high = num;
        
        for (int j = 1; j <= num; j++) {
            int i;
            scanf("%d", &i);
            teams[i]++;
        }
        
        low = 1;
        
        while (low <= high) {
            mid = (low + high) >> 1;
            createGraph(mid);
            int result = spfa(24, 23, mid);
            
            if (result) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (low == num + 1) {
            printf("No Solution\n");
        } else {
            printf("%d\n", low);
        }
    }
    system("pause");
    
    return 0;
}
