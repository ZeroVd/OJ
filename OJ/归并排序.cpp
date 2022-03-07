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
		while (p < m || q < y)				//��߻��ұ�������δ����ʱ����ѭ��
		{
			if (q >= y || (p < m && A[p] <= A[q]))			//�ұ������ݻ�����׸�����С���ұ��׸�����ʱ����������������½��м�ռ�������
				T[i++] = A[p++];
			else
				T[i++] = A[q++];				//�����ұ����������½��м�ռ�������
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