#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	double angle;
	int type;
	int id;

	bool operator<(const Node& t) {
		return angle < t.angle;
	}
};

Node p[1000];
int ans[1000];


void sovel(int l, int r)
{
	if (l >= r)
		return;

	//Ѱ�����½ǵ�Ԫ��
	int pos = l;
	for (int i = l + 1; i <= r; i++)
		if (p[i].y < p[pos].y || (p[i].y == p[pos].y && p[i].x < p[pos].x))
			pos = i;

	//�������½�Ԫ�����������Ԫ��λ��
	Node t;
	t = p[l];
	p[l] = p[pos];
	p[pos] = t;
	
	//����Ƕ�
	for (int i = l + 1; i <= r; i++)
	{
		p[i].angle = atan2(p[i].y - p[l].y, p[i].x - p[l].x);
	}
	sort(p + l + 1, p + r);

	int cnt = p[l].type;
	for (int i = l + 1; i <= r; i++)
	{
		cnt += p[i].type;
		if (cnt == 0)
		{
			ans[p[l].id] = p[i].id;
			ans[p[i].id] = p[l].id;
			sovel(l + 1, i - 1);
			sovel(i + 1, r);
			break;
		}
	}
		
	return;
}


int main()
{
	memset(ans, 0, sizeof(ans));
	int x, y, t, l = 0;
	cin >> l;
	for (int len = 0; len < l; len++)// ¼������ 
	{
		scanf("%d%d%d", &t, &x, &y);
		p[len].x = x;
		p[len].y = y;
		p[len].id = len;//��ӦID
		if (t == 1)
			p[len].type = 1;//��ʾ����
		else
			p[len].type = -1;
	}

	sovel(0, l-1);
	for (int i = 0; i < l; i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}