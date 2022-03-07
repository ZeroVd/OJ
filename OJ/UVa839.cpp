#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <iostream>
using namespace std;


bool solve(int &w)
{
	int w1 = 0, d1 = 0, w2 = 0, d2 = 0;
	bool b1 = true, b2 = true;
	scanf("%d %d %d %d", &w1, &d1, &w2, &d2);
	if (!w1)
		b1 = solve(w1);
	if (!w2)
		b2 = solve(w2);
	w = w1 + w2;
	return b1 && b2 && (w1 * d1 == w2 * d2);
}


int main()
{
	int T, W;
	scanf("%d", &T);
	while (T--)
	{
		if (solve(W))
			printf("YES\n");
		else
			printf("NO\n");

		if (T)
			printf("\n");
	}

	return 0;
}