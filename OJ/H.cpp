#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

int main()
{
	int n, ans = 0, num = 0;
	cin >> n;
	int mp[1005][1005] = { 0 };
	char ch;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> ch;
			if (ch == '#') {
				mp[i][j] = 1;
				num++;
				q.push(i);
				q.push(j);
			}
		}
	while (!q.empty()) {
		//cout << q.size() << endl;
		ans++;
		int si = q.size() / 2;
		for (int i = 0; i < si; i++) {
			int r = q.front();
			q.pop();
			int c = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int rr = r + dr[k], cc = c + dc[k];
				if (rr < 1 || cc < 1 || rr > n || cc > n || mp[rr][cc] == 1) continue;
				mp[rr][cc] = 1;
				num++;
				q.push(rr);
				q.push(cc);
			}
		}
	}
	cout << ans - 1;
	return 0;
}