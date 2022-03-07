#include <iostream>
#include <ctime>
using namespace std;

void sort_q(int* A, int x, int y)
{
	if (x >= y)
		return;
	int i = x, j = y, base = A[x];
	while (i < j)
	{
		while (A[j] >= base && i < j)
			j--;
		while (A[i] <= base && i < j)
			+
			i++;
		if(i < j)
		{
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	A[x] = A[j];
	A[j] = base;

	sort_q(A, x, i - 1);
	sort_q(A, i + 1, y);
}

int bSearch(int* A, int x, int y, int v)
{
	while (x < y)
	{
		int m = x + (y - x) / 2;
		if (A[m] >= v)
			y = m;
		else
			x = m + 1;
	}
	return x;
}

int main()
{
	int arr[10000];
	int n;
	cin >> n;
	srand(int(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;

	sort_q(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;


	//¶þ·Ö²éÕÒ
	int v, pos;
	while (cin >> v)
	{
		pos = bSearch(arr, 0, n, v);
		if (pos == -1)
			cout << "None" << endl;
		else
			cout << pos << endl;
	}
		

	return 0;
}