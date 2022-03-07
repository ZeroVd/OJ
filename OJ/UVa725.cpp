#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n = 0;
	char buf[99];
	int kase = 0;
	while (scanf("%d", &n) && n != 0)
	{
		long v1, v2;
		int cnt = 0;
		bool ok = true;
		if (kase++) printf("\n");
		for (v2 = 1234;; v2++)
		{
			v1 = v2 * n;
			sprintf(buf, "%05d%05d", v1, v2);
			if (strlen(buf) > 10)
				break;
			sort(buf, buf + 10);
			ok = true;
			for (int i = 0; i < 10; i++)
			{
				if (i != buf[i] - '0')
					ok = false;
			}
			if (ok)
			{
				printf("%05d / %05d = %d\n", v1, v2, n);
				cnt++;
			}
		}

		if (cnt == 0)
			printf("There are no solutions for %d.\n", n);
	}

	return 0;
}