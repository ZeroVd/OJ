#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define N 2005
#define maxn 5005
const ll mod = 1e9+7;

struct edge{
    int v,w,next;
};
edge e[400005];
int head[maxn],dist[maxn],vis[maxn];
int idx,n,m;

void addEdge(int u, int v, int w){
    e[++idx].v=v; e[idx].w=w; e[idx].next=head[u]; head[u]=idx;
}

void prim(){
    memset(dist, INF, sizeof dist);
    for(int i=head[1];i; i=e[i].next)           //可能存在重边
        dist[e[i].v] = min(dist[e[i].v], e[i].w);
    int tot=0, now=1, ans=0;
    while(++tot<n){
        int mn=INF;
        vis[now]=1;
        for(int i=1; i<=n; i++)
            if(!vis[i] && mn>dist[i]){
                mn=dist[i];
                now = i;
            }
        if(mn==INF) {cout << "orz"; return;}
        ans+=mn;
        for(int i=head[now];i; i=e[i].next){
            int v=e[i].v;
            if(dist[v]>e[i].w && !vis[v]) dist[v]=e[i].w;
        }
    }
    cout << ans;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    prim();
    return 0;
}