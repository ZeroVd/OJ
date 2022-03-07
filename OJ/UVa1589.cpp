/*
存在问题：黑将移动后可以吃到红方棋子的情况为实现

2021/8/2           By Zero
*/

#include <iostream>
using namespace std;

#define ROW 11
#define COLUMN 10

struct C
{
	char name;
	int x;
	int y;
}chesses[7];
struct C general;		//黑方将军
int n;

char d[ROW][COLUMN];		//棋盘


void RSetN(int c)
{
	int x = chesses[c].x, y = chesses[c].y;

	//处理行
	x -= 1;
	while (x > 0 && d[x][y] != 'R' && d[x][y] != 'H' && d[x][y] != 'C' && d[x][y] != 'G')
	{
		d[x][y] = 'N';
		x -= 1;
	}
	x = chesses[c].x;
	x += 1;
	while (x < 11 && d[x][y] != 'R' && d[x][y] != 'H' && d[x][y] != 'C' && d[x][y] != 'G')
	{
		d[x][y] = 'N';
		x += 1;
	}
	//处理列
	y -= 1;
	while (y > 0 && d[x][y] != 'R' && d[x][y] != 'H' && d[x][y] != 'C' && d[x][y] != 'G')
	{
		d[x][y] = 'N';
		y -= 1;
	}
	y = chesses[c].y;
	y += 1;
	while (y < 11 && d[x][y] != 'R' && d[x][y] != 'H' && d[x][y] != 'C' && d[x][y] != 'G')
	{
		d[x][y] = 'N';
		y += 1;
	}
}
void HSetN(int c)
{
	int x = chesses[c].x, y = chesses[c].y;
	if (y - 2 > 0 && (d[x][y - 1] == 'N' || d[x][y - 1] == '#'))
	{
		if (x - 1 > 0)
			d[x - 1][y - 2] = 'N';
		if (x + 1 < 11)
			d[x + 1][y - 2] = 'N';
	}
	if (y + 2 < 11 && (d[x][y + 1] == 'N' || d[x][y + 1] == '#'))
	{
		if (x - 1 > 0)
			d[x - 1][y + 2] = 'N';
		if (x + 1 < 11)
			d[x + 1][y + 2] = 'N';
	}
	if (x - 2 > 0 && (d[x - 1][y] == 'N' || d[x - 1][y] == '#'))
	{
		if (y - 1 > 0)
			d[x - 2][y - 1] = 'N';
		if (y + 1 < 11)
			d[x - 2][y + 1] = 'N';
	}
	if (x + 2 > 0 && (d[x + 1][y] == 'N' || d[x + 1][y] == '#'))
	{
		if (y - 1 > 0)
			d[x + 2][y - 1] = 'N';
		if (y + 1 < 11)
			d[x + 2][y + 1] = 'N';
	}
}
void CSetN(int c)
{
	int x = chesses[c].x, y = chesses[c].y;

	while ( x < 11 && d[++x][y] != '#' && d[x][y] != 'N' );
	if (x < 10)
	{
		while (x < 11 && (d[++x][y] == '#' || d[x][y] == 'N'))
			d[x][y] = 'N';
	}

	x = chesses[c].x;
	while (y < 11 && d[x][--y] != '#' && d[x][y] != 'N');
	if (y < 10)
	{
		while (y < 11 && (d[x][--y] == '#' || d[x][y] == 'N'))
			d[x][y] = 'N';
	}
	y = chesses[c].y;
	while (y < 11 && d[x][++y] != '#' && d[x][y] != 'N');
	if (y < 10)
	{
		while (y < 11 && (d[x][++y] == '#' || d[x][y] == 'N'))
			d[x][y] = 'N';
	}
}

bool isCheckmate()
{
	for (int i = 0; i < n; i++)
	{
		if (chesses[i].name == 'G' || chesses[i].name == 'R')
			RSetN(i);
		else if (chesses[i].name == 'H')
			HSetN(i);
		else
			CSetN(i);
	}

	if (general.y - 1 >= 4 && d[general.x][general.y - 1] == '#')
		return false;
	else if (general.y + 1 <= 6 && d[general.x][general.y + 1] == '#')
		return false;
	else if (general.x - 1 >= 8 && d[general.x - 1][general.y] == '#')
		return false;
	else if (general.x + 1 <= 10 && d[general.x + 1][general.y] == '#')
		return false;
	else
		return true;
}

int main()
{
	while (cin >> general.x >> general.y && general.x != 0)
	{
		if (cin >> n && n >= 2 && n <= 7)
		{
			memset(d, '#', sizeof(d));
			for (int i = 0; i < n; i++)
			{
				cin >> chesses[i].name >> chesses[i].x >> chesses[i].y;
				d[chesses[i].x][chesses[i].y] = chesses[i].name;			//在棋盘上标记棋子
			}

			//
			if (isCheckmate())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}