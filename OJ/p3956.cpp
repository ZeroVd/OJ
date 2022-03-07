#include <bits/stdc++.h>
using namespace std;
//#define long long  ll
//#define inf 0x3f3f3f3f

/*
* P3956
	ʹ�����ȶ��У�С���ѣ�ʹ�ô�����ΪȨֵ��������bfs����һ���������洢��ǰ��С���ۣ�ÿ�ν���
��һ������ʱ�����ò��Ϸ��������жϸò��Ĵ����Ƿ񳬹��˵�ǰ��С���ۣ���Ϊ��������뵽���ȶ�
���У�ÿ��ȡ��������С��ĳһ������������������������Dijkstra�㷨����

��ħ�����еȼ۴���˼·��
	���λ��Ҫ������������������������ˣ�����������ʱ����Ҫ����12������
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
int a[105][105] = { 0 }, dis[105][105];		//a�洢��ǰ������ɫ, dis �洢��ǰλ�����Ž�
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
