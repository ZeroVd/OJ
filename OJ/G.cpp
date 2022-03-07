#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
bool cmp(pii& a, pii& b)
{
	return a.second > b.second;
}
int main()
{
	int vis[24] = { 0 };
	int n, x;
	cin >> n >> x;
	pii a[200005];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
		if (a[i].first < 8) a[i].first = 8;
	}
	sort(a + 1, a + n + 1, cmp);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i].first; j <= 22; j++) {
			if (!vis[j]) {
				if (j >= 19) {
					if (a[i].second - x > 0) {
						ans += a[i].second - x;
						vis[j] = 1;
					}
					break;
				}
				else ans += a[i].second;
				vis[j] = 1;
				break;
			}
		}
	}
	if (!ans) cout << "zxnbbjtqsl\n";
	else cout << ans;
	return 0;
}