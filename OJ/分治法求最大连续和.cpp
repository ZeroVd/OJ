#include <iostream>
using namespace std;

const int maxn = 100;
int n;

int maxsum(int *arr, int x, int y)
{
	int v, L, R, maxs;
	if (y - x == 1)
		return arr[x];
	//�ֿ���������
	int m = x + (y - x) / 2;
	maxs = max(maxsum(arr, x, m), maxsum(arr, m, y));
	//�����ϲ���

	v = 0;
	L = arr[m - 1];
	for (int i = m - 1; i >= x; i--)
		L = max(L, v += arr[i]);
	v = 0;
	R = arr[m];
	for (int i = m; i < y; i++)
		R = max(R, v += arr[i]);
		


	return max(maxs, L + R);
}

int main()
{
	int arr[maxn];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int m = maxsum(arr, 0, n);
	cout << m << endl;

	return 0;
}