#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <vector>
using namespace std;



int main()
{
	int k = 0;
	int y;
	int x;
	vector<int> vx, vy;
	while (scanf("%d", &k) == 1&& k)
	{
		int n = 0;
		vx.clear();
		vy.clear();
		for (y = k + 1; y <= 2*k; y++)
		{
			if (k * y % (y - k) == 0)
			{
				vx.push_back(k * y / (y - k));
				vy.push_back(y);
				n++;
			}
		}
		printf("%d\n", n);
		for(int i = 0; i < n; i++)
			printf("1/%d = 1/%d + 1/%d\n", k, vx[i], vy[i]);
	}

	return 0;
}