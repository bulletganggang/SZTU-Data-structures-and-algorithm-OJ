#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;

const int maxn = 2e2 + 10;
const int maxm = 1e4 + 10;
const int inf = 0x3f3f3f3f;

int fst[maxn], nex[maxm], v[maxm], cap[maxm], tp;
int ly[maxn], work[maxn], n, m, so, te;

void AddEdge(int s, int e, int w)
{
    v[tp] = e; 
    cap[tp] = w; 
    nex[tp] = fst[s]; 
    fst[s] = tp ++;
}

void DbEdge(int s, int e, int w)
{
    AddEdge(s,e,w);
    AddEdge(e,s,0);
} 

bool DiBFS()
{
    queue<int> q;
    memset(ly,-1,sizeof(ly));
    q.push(so);
    ly[so] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = fst[now]; i != -1; i = nex[i])
        {
            if(ly[v[i]] >=0 || !cap[i]) continue;
            ly[v[i]] = ly[now] + 1;
            if(v[i] == te) return true;
            q.push(v[i]);
        }
    }
    return false;
}

int DiDFs(int cur, int inc) 
{
    int tinc;
    if(cur == te) return inc;
    for(int &i = work[cur]; i != -1; i = nex[i])
    {
        if(cap[i] && ly[v[i]] == ly[cur] + 1 && (tinc = DiDFs(v[i], min(inc, cap[i]))))
        {
            cap[i] -= tinc;
            cap[i ^ 1] += tinc;
            return tinc;
        }
    }
    return 0;
}

int Dinic() 
{
    int ret = 0, tinc;
    while(DiBFS()) 
    {
        for(int i = 0; i <= n; i ++) work[i] = fst[i];
        while(tinc = DiDFs(so, inf)) ret += tinc;
    }
    return ret;
}

int main()
{
    int a, b, w;
    while(scanf("%d%d%d%d",&n,&m,&so,&te) != EOF)
    {
        memset(fst,-1,sizeof(fst));
        tp = 0;
        for(int i = 0; i < m; i ++) 
        {
            scanf("%d%d%d",&a, &b ,&w);
            DbEdge(a,b,w);
        }
    printf("%d\n",Dinic());
    }
    return 0;
}