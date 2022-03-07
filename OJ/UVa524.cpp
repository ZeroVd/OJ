#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int vis[17];
int kase = 0;

bool isPrime(int v)
{
	for (int i = 2; i * i <= v; i++)
		if (v % i == 0) 
			return false;
	return true;
}

void dfs(int n, int *val, int cur)
{
	if (cur == n && isPrime(val[0] + val[n - 1]))
	{
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				cout << " ";
			cout << val[i];
		}
		cout << endl;
		return;
	}
	else
		for (int i = 2; i <= n; i++)
			if (isPrime(val[cur-1] + i) && !vis[i])
			{
				vis[i] = 1;
				val[cur] = i;
				dfs(n, val, cur + 1);
				vis[i] = 0;
			}

}

int main()
{
	int n;
	int val[16];
	val[0] = 1;
	while (cin >> n && n > 0)
	{
		memset(vis, 0, sizeof(vis));
		if (kase > 0)
			cout << endl;
		cout << "Case " << ++kase << ":" << endl;
		dfs(n, val, 1);
	}
	

	return 0;
}