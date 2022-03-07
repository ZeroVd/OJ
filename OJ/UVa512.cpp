/*
UVa 512
һ���ȼ����ģ�������ٲ�ѯ���
	1���������������������ģ�����������Ȼ���ʼ��һ����ά������Ϊ��񣬸�������λ��
		��ֵ��
	2.�������ģ���������Ա����в�����
	3.���ݱ���е�ֵȷ���ñ���ԭ���꣬��һ������������ԭ���걣��õ�Ԫ��Ϊ�ø����
		ģ������λ�ø�ֵ��
	4.��ȡ��ѯ��������ѯ���ݣ���������

�����ȱ���ģ�������ѯʱ������ѯ������ִ��ģ������ó����
	1.�������������������ģ�����������
	2.

	2021/7/30    by Zero
*/

#include <iostream>
using namespace std;

//��
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
		//����ʱ
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
		//ɾ��ʱ
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
		//���ʱ
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
	//��������
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

	//��ѯ����
	int q;
	cin >> q;
	while (q--)
	{
		cin >> r0 >> c0;
		cout << "Cell data in (" << r0 << "," << c0 << ") ";
		//ģ�����
		if(simulate(&r0, &c0))
			cout << "moved to (" << r0 << ", " << c0 << ") " << endl;
		else
			cout << "GONE" << endl;	
	}


	return 0;
}






#if 0
//һ
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
	char cmd[CMDMAX];		//�����������
	memset(d, 0, sizeof(d));	//������dȫ������Ϊ0

	//������d���г�ʼ��
	while (cin >> r >> c >> n && r)		//һ����������У��У���������
	{
		int r0 = r, c0 = c;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				d[i][j] = i * BIG + j;
		
		while (n--)
		{
			cin >> cmd;
			//����ǽ�������
			if (cmd[0] == 'E')
			{
				cin >> r1 >> c1 >> r2 >> c2;		//�������뽻��ǰ�������
				int t = d[r1][c1];
				d[r1][c1] = d[r2][c2];
				d[r2][c2] = t;
			}
			//�����ɾ�����������
			else
			{
				int a, x;
				cin >> a;
				memset(cols, 0, sizeof(cols));		//���������ȫ����ֵΪ0
				for (int i = 0; i < a; i++)
				{
					cin >> x;
					cols[x] = 1;		//����Ҫ�޸ĵ�λ�ø�ֵΪ1���б��
				}
				//�����ɾ������
				if (cmd[0] == 'D')
					del(cmd[1]);
				//�������Ӳ���
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