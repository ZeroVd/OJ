#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define maxn 5005
const ll mod = 1e9+7;

struct edge{
	int u,v,w;
};
edge e[200005];
int f[maxn];
int n,m,ans,cnt;

bool cmp(const edge& a, const edge& b){ return a.w<b.w; };
int find(int x) { return x==f[x] ? x:f[x]=find(f[x]); }
void kruskal(){     //使用并查集来判断是否成环
	sort(e+1, e+m+1, cmp);
	for(int i=1; i<=m; i++){
		int uu=find(e[i].u), vv=find(e[i].v);
		if(uu == vv) continue;
		ans += e[i].w;
		f[vv] = uu;     //并查集合并
		if(++cnt == n-1) break;
	}
}

int main()
{
	cin >> n >> m;
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	kruskal();
	if(cnt==n-1) cout << ans;
	else cout << "orz";
	return 0;
}