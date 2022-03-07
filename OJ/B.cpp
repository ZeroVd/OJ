#include <bits/stdc++.h>
using namespace std;

int mxans;

int main()
{
	queue<int> q;
	int x;
	for (int i = 0; i < 4; i++) {
		cin >> x;
		q.push(x - 1);
	}
	//bfs
	q.push(0);
	int ans = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		int c = q.front();
		q.pop();
		int d = q.front();
		q.pop();
		int step = q.front();
		q.pop();
		//cout << a << " " << b << " " << c << " " << d << endl;
		int tt = a;
		if (tt == b && tt == c && tt == d) {
			mxans = step;
			break;
		}

		q.push((a + 1) % 3);
		q.push((b + 1) % 3);
		q.push(c);
		q.push(d);
		q.push(step + 1);

		q.push((a + 1) % 3);
		q.push((b + 1) % 3);
		q.push((c + 1) % 3);
		q.push(d);
		q.push(step + 1);

		q.push(a);
		q.push((b + 1) % 3);
		q.push((c + 1) % 3);
		q.push((d + 1) % 3);
		q.push(step + 1);

		q.push(a);
		q.push(b);
		q.push((c + 1) % 3);
		q.push((d + 1) % 3);
		q.push(step + 1);
	}

	cout << mxans;
	return 0;
}