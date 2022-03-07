#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


int main()
{
	int n, A[100005];
	while (cin >> n && n)
	{
		memset(A, 0, sizeof(A));
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];
		}

		for (int i = 1; i < n; i++)
		{
			ans += abs(A[i]);
			A[i + 1] += A[i];
		}

		cout << ans << endl;
	}

	return 0;
}