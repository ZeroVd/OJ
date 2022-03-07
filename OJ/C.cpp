#include <bits/stdc++.h>
using namespace std;
bool vis[100005] = { 0 };
//int num[100005] = { 0 };
int primes[1000005] = { 0 };

void ols()
{
	vis[1] = 1;
	int cnt = 0;
	for (int i = 2; i <= 100005; i++) {
		if (!vis[i]) {
			primes[cnt++] = i;
			//num[i] = num[i - 1] + 1;
		}
		//if (!num[i]) num[i] = num[i - 1];
		for (int j = 0; j < cnt && i * primes[j] <= 100005; j++) {
			vis[i * primes[j]] = 1;
			if (i % primes[j] == 0) break;
		}
	}
}
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main()
{
	int n;
	cin >> n;
	ols();
	long long ans = 0;
	bool v[100005] = { 0 };
	while (n--) {
		int a, b, t = 0;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			if (!vis[i] && !v[i]) t++;
			v[i] = 1;
		}
		ans += t;
	}
	cout << ans;
	return 0;
}