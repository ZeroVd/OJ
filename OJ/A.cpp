#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll quick(string n)
{
	ll base = 1, ans = 0;
	reverse(n.begin(), n.end());
	for(int i = 0; i < n.size(); i++) {
		if (n[i] == '1') ans += base;
		base *= 2;
	}
return ans;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string n;
		cin >> n;
		cout << quick(n) << endl;
	}

	return 0;
}