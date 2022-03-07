#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int x[5005], y[5005];

struct Node {
	int l, r, id;
};

Node sx[5005], sy[5005];

bool compare(Node &one, Node &two)
{
	if (one.r == two.r)
		return one.l < two.l;
	return one.r < two.r;
}
bool compareId(Node& one, Node& two)
{
	return one.id < two.id;
}

bool find(Node &tx, Node &ty)
{
	while (x[tx.l] != -1)
	{
		tx.l++;
		if (tx.l > tx.r)
			return false;
	}
	x[tx.l] = 1;

	while (y[ty.l] != -1)
	{
		ty.l++;
		if (ty.l > ty.r)
			return false;
	}
	y[ty.l] = 1;
	return true;
}

int main()
{
	while (cin >> n && n != 0)
	{
		int ok = 1;
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));
		for (int i = 1; i <= n; i++)
		{
			cin >> sx[i].l >> sy[i].l >> sx[i].r >> sy[i].r;
			sx[i].id = i;
			sy[i].id = i;
		}

		sort(sx + 1, sx + n + 1, compare);
		sort(sy + 1, sy + n + 1, compare);

		for (int i = 1; i <= n; i++)
		{
			if (!find(sx[i], sy[i]))
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			sort(sx + 1, sx + n + 1, compareId);
			sort(sy + 1, sy + n + 1, compareId);

			for (int i = 1; i <= n; i++)
			{
				printf("%d %d\n", sx[i].l, sy[i].l);
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
