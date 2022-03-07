#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int kase = 0;
	int n = 0;
	
	int v[20];
	
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		long ans = 0;
		for (int i = 0; i < n; i++)
		{
			long s = 1;
			for (int j = i; j < n; j++)
			{
				s *= v[j];
				if (s > ans)
					ans = s;
			}
		}

		cout << "Case #" << ++kase << ": The maximum product is " << ans << ".\n\n";
	}

	return 0;
}