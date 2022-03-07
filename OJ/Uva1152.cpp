#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 4000;
int n;
int p[maxn * maxn], q[maxn * maxn];


int main()
{
	int T, ans;
	cin >> T;
	int A[maxn], B[maxn], C[maxn], D[maxn];
	while (T--)
	{
		//读入数据
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		//处理数据
		int m = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				p[m] = A[i] + B[j];
				q[m++] = -C[i] - D[j];
			}
		//排序
		sort(q, q + m);

		//查找
		ans = 0;
		for (int i = 0; i < m; i++)
		{
			ans += upper_bound(q, q + m, p[i]) - lower_bound(q, q + m, p[i]);
		}
		cout << ans << endl;
		if (T)
			cout << endl;
	}

	return 0;
}