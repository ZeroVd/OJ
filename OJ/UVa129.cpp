#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <iostream>
using namespace std;

int n, L, cnt;
int s[100];

int dfs(int cur)
{
	//输出部分
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; i++)
		{
			if (i % 64 == 0 && i > 0)
				printf("\n");
			else if (i % 4 == 0 && i > 0)
				printf(" ");
			printf("%c", 'A' + s[i]);
		}
		printf("\n%d\n", cur);
		return 0;	
	}
	//计算部分
	for (int i = 0; i < L; i++)
	{
		s[cur] = i;
		int ok = 1;
		
		for (int j = 1; j * 2 <= cur + 1; j++)
		{
			int equal = 1;
			for (int k = 0; k < j; k++)
			{
				if (s[cur - k] != s[cur - k - j])
				{
					equal = 0;
					break;
				}
			}
			if (equal)
			{
				ok = 0;
				break;
			}
		}
		if(ok)
		{
			if (!dfs(cur + 1))
				return 0;
		}
	}
	return 1;
}


int main()
{
	while (scanf("%d %d", &n, &L) == 2 && n && L)
	{
		cnt = 0;
		dfs(0);
	}

	return 0;
}