#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void mergeSort(int* A, int x, int y, int* T)
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		mergeSort(A, x, m, T);
		mergeSort(A, m, y, T);

		int p = x, q = m, i = x;
		while (p < m || q < y)				//左边或右边有数据未排序时进入循环
		{
			if (q >= y || (p < m && A[p] <= A[q]))			//右边无数据或左边首个数据小于右边首个数据时，将左边数据移入新建中间空间数组中
				T[i++] = A[p++];
			else
				T[i++] = A[q++];				//否则将右边数据移入新建中间空间数组中
		}

		for (int i = x; i < y; i++)
			A[i] = T[i];
	}
}

int main()
{
	int arr[10000], t[10000];
	int n;
	cin >> n;
	srand(int(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	
	cout << endl;

	mergeSort(arr, 0, n, t);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}