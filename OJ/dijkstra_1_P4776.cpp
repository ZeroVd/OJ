#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define maxn 100005
const ll mod = 1e9+7;

struct edge{
	int from,to,dis;
};
struct node
{
	int w, dis;
	friend bool operator<(const node& a, const node& b){
		return a.dis>b.dis;
	}
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
int n,m,s;

void dijkstra(){
	memset(dis, INF, sizeof dis);
	priority_queue<node> q;
	q.push({s, 0});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().w, d=q.top().dis; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0; i<e[u].size(); i++){
			int v=e[u][i].to;
			if(dis[v]>dis[u]+e[u][i].dis){
				dis[v]=dis[u]+e[u][i].dis;
				if(!vis[v]) q.push({v, dis[v]});
			}
		}
	}
}

int main()
{
	cin >> n >> m >> s;
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		e[a].pb({a,b,c});
	}
	dijkstra();
	for(int i=1; i<=n; i++) cout << dis[i] << " ";
	return 0;
}