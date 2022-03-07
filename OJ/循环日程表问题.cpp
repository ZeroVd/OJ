#include <iostream>

using namespace std;
const int maxn = 1000;
int table[maxn][maxn];

void circulateSchedule(int tr, int tc, int n)
{
	if (n == 1)
		return;
	int t = n / 2;

	table[tr + t][tc + t] = table[tr][tc];
	table[tr][tc + t] = table[tr + t][tc] = table[tr][tc] + t;

	circulateSchedule(tr, tc, t);
	circulateSchedule(tr + t, tc, t);
	circulateSchedule(tr, tc + t, t);
	circulateSchedule(tr + t, tc + t, t);
}


int main()
{
	memset(table, 0, sizeof(table));
	int k;
	cin >> k;
	table[0][0] = 1;

	circulateSchedule(0, 0, (1 << k));

	for (int i = 0; i < (1 << k); i++)
	{
		for (int j = 0; j < (1 << k); j++)
			printf("%2d ", table[i][j]);
		printf("\n");
	}
		
	return 0;
}

