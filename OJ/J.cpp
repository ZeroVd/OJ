#include <bits/stdc++.h>
using namespace std;
//typedef pair<int, int> pii;
typedef long long ll;

int main()
{
	int n, x;
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
	}
	if (sum & 1) cout << "ddd\n";
	else cout << "bqp\n";
	return 0;
}