#include <bits/stdc++.h>
using namespace std;
//#define long long  ll
//#define inf 0x3f3f3f3f

/*
* P3956
	使用优先队列（小顶堆，使用代价作为权值）来进行bfs，开一个数组来存储当前最小代价，每次进行
下一步搜索时，（该步合法）首先判断该步的代价是否超过了当前最小代价，若为超过则加入到优先队
列中，每次取出代价最小的某一步来进行搜索，（可能类似Dijkstra算法）。

对魔法进行等价代换思路；
	理解位需要多用两个代价来走两步，因此，在懒惰搜索时，需要搜索12个方向。
*/
struct node {
	int x, y, c, w;
	bool operator < (node a) const {
		return w > a.w;
	}
};


int dx[] = { 0,1,0,-1,-1,-1,1,1,0,2,0,-2 };
int dy[] = { -1,0,1,0,-1,1,1,-1,-2,0,2,0 };
int dw[] = { 0,0,0,0,2,2,2,2,2,2,2,2 };
priority_queue<node> q;
int a[105][105] = { 0 }, dis[105][105];		//a存储当前方块颜色, dis 存储当前位置最优解
int n, m;

void bfs()
{
	memset(dis, 0x3f3f, sizeof(dis)); 
	dis[1][1] = 0;
	q.push({ 1, 1, a[1][1], dis[1][1] });
	node cur, nxt;
	while (!q.empty()) {
		cur = q.top(); q.pop();
		if (dis[cur.x][cur.y] < cur.w) continue;
		for (int i = 0; i < 12; i++) {
			nxt.x = cur.x + dx[i];
			nxt.y = cur.y + dy[i];
			nxt.w = cur.w + dw[i];
			if (nxt.x < 1 || nxt.x > m || nxt.y < 1 || nxt.y > m) continue;
			nxt.c = a[nxt.x][nxt.y];
			if (!nxt.c) continue;
			if (nxt.c != cur.c) nxt.w++;
			if (nxt.w < dis[nxt.x][nxt.y]) {
				dis[nxt.x][nxt.y] = nxt.w;
				q.push(nxt);
			}
		}
	}
}

int main()
{
	int x, y, c;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> c;
		a[x][y] = c + 1;
	}
	bfs();
	if (!a[m][m]) {
		int ans = min(dis[m - 1][m], dis[m][m - 1]) + 2;
		if (ans >= 0x3f3f) cout << "-1\n";
		else cout << ans << endl;
	}
	else {
		if (dis[m][m] == 0x3f3f) cout << "-1\n";
		else cout << dis[m][m] << endl;
	}

	return 0;
}
