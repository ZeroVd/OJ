/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll L, N, M;
	cin >> L >> N >> M;
	ll D[50005];
	vector<ll> d;
	D[0] = 0;
	d.push_back(0);
	for (int i = 1; i <= N; i++)
		cin >> D[i];
	for (int i = 1; i <= N; i++)
		d.push_back(D[i] - D[i - 1]);
	d.push_back(L - D[N]);
	vector<ll>::iterator it, itmn;
	for (int i = 0; i < M; i++) {
		itmn = min_element(d.begin() + 1, d.end());
		if (itmn == d.end() - 1)
			itmn--;
		it = itmn + 1;
		*it += *itmn;
		d.erase(itmn);
	}
	itmn = min_element(d.begin() + 1, d.end());
	cout << *itmn << endl;
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int, ll> a, pair<int, ll> b)
{
	return a.first > b.first;
}
int main()
{
	ll n;
	cin >> n;
	vector<pair<int, ll>> a(n);
	vector<int> f(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end(), cmp);
	ll gold, silver;
	gold = n / 10 * 2;
	silver = n / 10 * 3 + gold;
	ll i = 0;
	while (i < n && (i < gold || a[i].first == a[gold - 1].first)) {
		i++;
		f[a[i-1].second] = 0;
	}
	if (i < silver) {
		while (i < n && (i < silver || a[i].first == a[silver - 1].first)) {
			i++;
			f[a[i-1].second] = 1;
		}
		while (i++ < n)
			f[a[i-1].second] = 2;
	}
	else
		while(i++ < n)
			f[a[i-1].second] = 2;
	printf("%d", f[0]);
	for (ll i = 1; i < n; i++)
		printf(" %d", f[i]);

	return 0;
}


int main()
{
	double x;
	cin >> x;
	ll ans = 0;
	if (x == 0.5)
		cout << "3";
	else {
		ans += 3;
		x -= 0.5;
		ans += x / 0.2;
		cout << ans;
	}


	return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100005];
ll l, k, ansmn = 0, ansmx = 0;
ll judge(ll n)
{
	ll sum = 0, ans = 0;
	for (ll i = 0; i < l; i++) {
		sum += x[i];
		if (sum >= n) sum = 0, ans++;
		if (sum < 0) sum = 0;
	}
	return ans - k;
}

int main()
{
	cin >> l >> k;
	for (int i = 0; i < l; i++)
		cin >> x[i];
	ll l = 1, r = 1e13, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		ll a = judge(mid);
		if (a == 0) ansmn = mid;
		if (a > 0)  l = mid + 1;
		else r = mid - 1;
	}
	l = 1, r = 1e13;
	while (l <= r) {
		mid = (l + r) / 2;
		ll a = judge(mid);
		if (a == 0) ansmx = mid;
		if (a < 0)  r = mid - 1;
		else l = mid + 1;
	}

	if (ansmn == 0 && ansmx == 0) cout << "-1\n";
	else cout << ansmn << " " << ansmx << "\n";

	return 0;
}




int a, b;
	while (scanf("%d%d", &a, &b) == 2 && a != EOF) {
		int ans = 0;
		for (int i = 1; i <= b; i++) {
			if ((i ^ a) < a) ans++;
		}
		cout << ans << endl;
	}


*/