#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, k = 1;
int mnans = 10;

void bfs()
{
	queue<int> q;
	q.push(a);
	q.push(0);
	while (!q.empty()) {
		cout << k++ << "   ----------------\n";
		int num = q.front();
		q.pop();
		cout << num << endl;
		int step = q.front();
		q.pop();
		if (num == b) {
			mnans = step;
			return;
		}
		if (step >= 7 || step > mnans) return;
		if (num == 1) continue;
		int t = 1;
		for (int i = 2; i <= num; i++) t *= i;
		q.push(t);
		cout << t << endl;
		q.push(step + 1);
		q.push(ceil(sqrt(num)));
		cout << ceil(sqrt(num)) << endl;
		q.push(step + 1);
		q.push(int(sqrt(num)));
		cout << int(sqrt(num)) << endl;
		q.push(step + 1);

	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		mnans = 10;
		cin >> a >> b;
		bfs();
		if (mnans != 10) cout << mnans << endl;
		else cout << "-1\n";
	}

	return 0;
}