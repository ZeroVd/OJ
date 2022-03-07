#include <iostream>
#include <ctime>
using namespace std;

const int maxn = 1000;
int chess[maxn][maxn];
int bx, by;
int title = 1;

void chessBoard(int tx, int ty, int dx, int dy, int size)
{
	if (size == 1)
		return;
	
	int s = size / 2;
	int t = title++;

	if (dx < tx + s && dy < ty + s)
		chessBoard(tx, ty, dx, dy, s);
	else {
		chess[tx + s - 1][ty + s - 1] = t;
		chessBoard(tx, ty, tx + s - 1, ty + s - 1, s);
	}

	if (dx >= tx + s && dy < ty + s)
		chessBoard(tx + s, ty, dx, dy, s);
	else {
		chess[tx + s][ty + s - 1] = t;
		chessBoard(tx + s, ty, tx + s, ty + s - 1, s);
	}

	if (dx < tx + s && dy >= ty + s)
		chessBoard(tx, ty + s, dx, dy, s);
	else {
		chess[tx + s - 1][ty + s] = t;
		chessBoard(tx, ty + s, tx + s - 1, ty + s, s);
	}

	if (dx >= tx + s && dy >= ty + s)
		chessBoard(tx + s, ty + s, dx, dy, s);
	else {
		chess[tx + s][ty + s] = t;
		chessBoard(tx + s, ty + s, tx + s, ty + s, s);
	}
}

int main()
{
	int k;
	cin >> k;
	srand((int)time(NULL));
	int position = rand() % ((1 << k) * (1 << k));
	bx = position / (1 << k);
	by = position % (1 << k);
	memset(chess, 0, sizeof(chess));
	chess[bx][by] = -1;

	chessBoard(0, 0, bx, by, (1 << k));

	for (int i = 0; i < (1 << k); i++)
	{
		for (int j = 0; j < (1 << k); j++)
		{
			printf("%3d  ", chess[i][j]);
		}
		printf("\n");
	}

	return 0;
}