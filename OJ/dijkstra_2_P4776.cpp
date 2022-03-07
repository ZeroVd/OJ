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
	int to,dis,next;
};
struct node
{
	int w, dis;
	friend bool operator<(const node& a, const node& b){
		return a.dis>b.dis;
	}
};

edge e[200005];
int head[maxn], dis[maxn], vis[maxn], cnt;
int n,m,s;

void addEdge(int u, int v, int d){
    cnt++;
    e[cnt].dis=d; e[cnt].to=v; e[cnt].next=head[u];
    head[u]=cnt;
}

void dijkstra(){
	memset(dis, INF, sizeof dis);
	priority_queue<node> q;
	q.push({s, 0});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().w, d=q.top().dis; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u]; i; i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].dis){
				dis[v]=dis[u]+e[i].dis;
				q.push({v, dis[v]});
			}
		}
	}
}

int main()
{
	int tt;
	cin >> n >> m >> s >> tt;
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		addEdge(a,b,c);
	}
	dijkstra();
	for(int i=1; i<=n; i++) cout << dis[i] << " ";
	return 0;
}