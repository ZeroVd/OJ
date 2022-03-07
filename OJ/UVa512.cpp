/*
UVa 512
一：先计算出模拟结果，再查询结果
	1，读入表格的行数，列数，模拟操作次数，然后初始化一个二维数组作为表格，根据坐标位置
		赋值；
	2.逐个读入模拟操作命令，对表格进行操作；
	3.根据表格中的值确定该表格的原坐标，在一个新数组中用原坐标保存该单元格，为该格根据
		模拟后的新位置赋值；
	4.读取查询次数，查询数据，输出结果；

二：先保存模拟命令，查询时对所查询的内容执行模拟命令，得出结果
	1.读入表格的行数，列数，模拟操作次数；
	2.

	2021/7/30    by Zero
*/

#include <iostream>
using namespace std;

//二
#define MAXD 16

int r, c, n;
struct {
	char cmd[MAXD];
	int a, r1, c1, c2, r2;
	int x[MAXD];
}cmd[MAXD];


bool simulate(int* r0, int* c0)
{
	int dr = 0, dc = 0;
	for (int i = 0; i < n; i++)
	{
		//交换时
		if (cmd[i].cmd[0] == 'E')
		{
			if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0)
			{
				*r0 = cmd[i].r2;
				*c0 = cmd[i].c2;
			}
			else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0)
			{
				*r0 = cmd[i].r1;
				*c0 = cmd[i].c1;
			}
		}
		//删除时
		else if (cmd[i].cmd[0] == 'D')
		{
			if(cmd[i].cmd[1] == 'R')
				for (int k = 0; k < cmd[i].a; k++)
				{
					if (cmd[i].x[k] < *r0)
						dr--;
					else if (cmd[i].x[k] == *r0)
						return false;
				}
			else if (cmd[i].cmd[1] == 'C')
				for (int k = 0; k < cmd[i].a; k++)
				{
					if (cmd[i].x[k] < *c0)
						dc--;
					else if (cmd[i].x[k] == *c0)
						return false;
				}
		}
		//添加时
		if (cmd[i].cmd[0] == 'I')
		{
			if (cmd[i].cmd[1] == 'R')
				for (int k = 0; k < cmd[i].a; k++)
				{
					if (cmd[i].x[k] <= *r0)
						dr++;
				}
			else if (cmd[i].cmd[1] == 'C')
				for (int k = 0; k < cmd[i].a; k++)
				{
					if (cmd[i].x[k] <= *c0)
						dc++;
				}
		}

	}
	*r0 += dr;
	*c0 += dc;

	return true;
}


int main()
{
	int r0, c0;
	cin >> r >> c >> n;
	//保存命令
	for (int i = 0; i < n; i++)
	{
		cin >> cmd[i].cmd;
		if (cmd[i].cmd[0] == 'E')
			cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
		else
		{
			cin >> cmd[i].a;
			for (int k = 0; k < cmd[i].a; k++)
			{
				cin >> cmd[i].x[k];
			}
		}

	}

	//查询部分
	int q;
	cin >> q;
	while (q--)
	{
		cin >> r0 >> c0;
		cout << "Cell data in (" << r0 << "," << c0 << ") ";
		//模拟操作
		if(simulate(&r0, &c0))
			cout << "moved to (" << r0 << ", " << c0 << ") " << endl;
		else
			cout << "GONE" << endl;	
	}


	return 0;
}






#if 0
//一
#define maxd 100
#define BIG 10000
#define CMDMAX 10

int r, c, n, d[maxd][maxd], d2[maxd][maxd], ans[maxd][maxd], cols[maxd];
void copy(char type, int p, int q)
{
	if (type == 'R')
	{
		for (int i = 1; i <= r; i++)
			d[p][i] = d2[q][i];
	}
	else
	{
		for (int i = 1; i <= c; i++)
			d[i][p] = d2[i][q];
	}

}

void del(char type)
{
	memcpy(d2, d, sizeof(d));

	int cnt = type == 'R' ? r : c, cnt2 = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (!cols[i])
			copy(type, ++cnt2, i);
	}

	if (type == 'R')
		r = cnt2;
	else
		c = cnt2;
}

void ins(char type)
{
	memcpy(d2, d, sizeof(d));

	int cnt = type == 'R' ? r : c, cnt2 = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (cols[i])
			copy(type, ++cnt2, 0);
		copy(type, ++cnt2, i);
	}

	if (type == 'R')
		r = cnt2;
	else
		c = cnt2;
}

int main()
{
	int r1, c1, r2, c2, q, kase = 0;
	char cmd[CMDMAX];		//保存命令代码
	memset(d, 0, sizeof(d));	//讲数组d全部保存为0

	//对数组d进行初始化
	while (cin >> r >> c >> n && r)		//一次输入表格的行，列，操作次数
	{
		int r0 = r, c0 = c;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				d[i][j] = i * BIG + j;
		
		while (n--)
		{
			cin >> cmd;
			//如果是交换命令
			if (cmd[0] == 'E')
			{
				cin >> r1 >> c1 >> r2 >> c2;		//依次输入交换前后的行列
				int t = d[r1][c1];
				d[r1][c1] = d[r2][c2];
				d[r2][c2] = t;
			}
			//如果是删除或添加命令
			else
			{
				int a, x;
				cin >> a;
				memset(cols, 0, sizeof(cols));		//讲标记数组全部赋值为0
				for (int i = 0; i < a; i++)
				{
					cin >> x;
					cols[x] = 1;		//将需要修改的位置赋值为1进行标记
				}
				//如果是删除操作
				if (cmd[0] == 'D')
					del(cmd[1]);
				//如果是添加操作
				else
					ins(cmd[1]);

			}

		}

		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
			}
		if (kase > 0)
			cout << endl;

		cout << "Spreadsheet #" << ++kase << endl;

		cin >> q;
		while (q--)
		{
			cin >> r1 >> c1;
			cout << "Cell data in (" << r1 << "," << c1 << ") ";
			if (ans[r1][c1] == 0)
				cout << "NONE" << endl;
			else
				cout << "moved to (" << ans[r1][c1]/BIG << ", " << ans[r1][c1]%BIG << ") " << endl;
		}
			
	}



	return 0;
}

#endif