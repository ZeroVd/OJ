#include <iostream>
using namespace std;

int n = 0, k = 0, m = 0;
int arr[20] = { 0 };

int go(int p, int d, int t)
{
	while (t--)
	{
		do
		{
			p = (p + d + n) % n;
		} while (arr[p] == 0);
	}
	return p;
}

int main()
{
	while (cin >> n >> k >> m)
	{
		int left = n;

		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
		}

		int p1 = n - 1, p2 = 0;

		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			cout << arr[p1];
			left--;
			if (p1 != p2)
			{
				cout << " " << arr[p2];
				left--;
			}

			arr[p1] = arr[p2] = 0;
			if (left)
				cout << ",";

		}
		cout << endl;

	}



	system("pause");
	return 0;
}