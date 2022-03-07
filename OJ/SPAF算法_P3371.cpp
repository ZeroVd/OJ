#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define maxn 10005
const ll mod = 1e9+7;
//SPFA
vector<pii> E[maxn];
int dis[maxn], inq[maxn];
int n,m,s;

int main()
{
	memset(dis, INF, sizeof(dis));
	cin >> n >> m >> s;
	int u,v,w;
	for(int i=1; i<=m; i++){
		cin >> u >> v >> w;
		E[u].push_back(make_pair(v,w));
	}
	dis[s] = 0; inq[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int k=q.front(); q.pop();
		inq[k]=0;	//出队
		for(int i=0; i<E[k].size(); i++){
			if(dis[k]+E[k][i].second<dis[E[k][i].first]) {
				dis[E[k][i].first]=dis[k]+E[k][i].second; 
				if(!inq[E[k][i].first]) {inq[E[k][i].first]=1; q.push(E[k][i].first);}	//若未在队列内，则入队
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(dis[i]==INF) cout << "2147483647 ";		//输出2^31-1
		else cout << dis[i] << " ";
	}
	return 0;
}