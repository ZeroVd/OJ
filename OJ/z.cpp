/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		ll hp, A, B, n, ans = 0;
		cin >> hp >> A >> B >> n;
		ll a[100005];
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (A * n * 2 < hp) {
			cout << "-1\n";
			continue;
		}
		sort(a + 1, a + n + 1);
		int whert = ceil(hp / (double)A ) - n;
		for (int i = n; i > 0; i--) {
			if (whert < i && a[i] > 2 * B) ans += a[i] / 2, whert++;
			else {
				n = i;
				break;
			}
		}
		cout << whert << endl;
		for (int i = 1; i <= n; i++) {
			if (i <= whert) ans += a[i] + B;
			else ans += a[i];
		}
		cout << ans << endl;
	}

	return 0;
}

1
11 2 2
5 
1 1 6 6 6
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if (n < 3) {
		if (n == 0) {
			if (m & 1)
				cout << "whrnb\n";
			else
				cout << "zynb\n";
		}
		else {
			if (m & 1) cout << "zynb\n";
			else cout << "whrnb\n";
		}
		return 0;
	}
	if (m == 0 && n % 4 == 0) {
		cout << "zynb\n";
		return 0;
	}
	if (n >= 3 && n % 3 != 0) {
		if (m & 1) cout << "zynb\n";
		else cout << "whrnb\n";
	}
	else {
		if (m & 1) cout << "whrnb\n";
		else cout << "zynb\n";
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int a, b, cnt = 0;
		cin >> a >> b;
		ll ans = 1;
		for (int i = a; i <= b; i++) {
			ans *= i;
			ans %= MOD;
		}
		for (int i = 0;; i++) {
			if (ans % 10 != 0) break;
			cnt++;
			ans /= 10;
		}
		cout << cnt << endl;
	}

	return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int a, b, c;
};
node d[105];
bool cmp(const node& a, const node& b) {
	return (double)a.c / (double)a.b > (double)b.c / (double)b.b;
}

int main()
{
	int n, h;
	cin >> n >> h;
	ll sum1 = 0, sum2 = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].a;
		sum1 += d[i].a;
	}
	for (int i = 1; i <= n; i++) cin >> d[i].b;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].c;
		sum2 += d[i].c;
	}
	if (sum1 + sum2 < h) {
		cout << "-1\n";
		return 0;
	}
	if (sum1 >= h) {
		cout << "0\n";
		return 0;
	}
	sort(d + 1, d + n + 1, cmp);
	h -= sum1;
	

	return 0;
}
*/



/*
typedef pair<int, int> pii;
ll sum = 0;
pii t[1000005];
pii a[1000005];

void merge(int l, int r)
{
	if (l >= r - 1) return;
	
	int mid = (l + r) / 2;
	int p = l, q = mid, i = l;
	while(q<mid && q<r) {
		if (p < mid && a[p].first < a[q].first) {
			t[i] = a[p++];
		}
		else if(q<r) {
			t[i] = a[q++];
			for (int j = p; j < q - 1; j++) {
				sum += a[j].second + a[q-1].second;
				//cout << sum << endl;
			}
		}
	}
	while (p < mid) t[i++] = a[p++];
	while (q < r) t[i++] = a[q++];
	for (int i = l; i < r; i++) {
		a[i] = t[i];
	}
	merge(l, mid);
	merge(mid, r);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;

	merge(0, n);
	cout << sum;
	return 0;
}


*/