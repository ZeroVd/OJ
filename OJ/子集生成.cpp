#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <iostream>
using namespace std;


void print_subset1(int n, int* A, int cur)
{
	for (int i = 0; i < cur; i++)
		cout << A[i]+1 << " ";
	cout << endl;

	int s = cur ? A[cur - 1] + 1 : 0;
	for (int i = s; i < n; i++)
	{
		A[cur] = i;
		print_subset1(n, A, cur + 1);
	}
}

void print_subset2(int n, int *B, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (B[i])
				cout << i + 1 << " ";
		}
		cout << endl;
		return;
	}

	B[cur] = 1;
	print_subset2(n, B, cur + 1);
	B[cur] = 0;
	print_subset2(n, B, cur + 1);
}

void print_subset3(int n, int s)
{
	for (int i = 0; i < n; i++)
		if (s & (1 << i))
			cout << i + 1 << " ";
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	int A[10000];

	print_subset1(n, A, 0);
	cout << endl;
	print_subset2(n, A, 0);
	cout << endl;
	for (int i = 0; i < (1 << n); i++)
		print_subset3(n, i);

	return 0;
}