#define _CRT_SECURE_NO_DEPRECATE 

#include <cstdio>

#define MAXN 10010

int in_order[MAXN], post_order[MAXN], lch[MAXN], rch[MAXN];
int n;

bool readData(int *u)
{
	int data = 0;
	char ch;
	n = 0;
	while (scanf("%d%c", &data, &ch) == 2)
	{
		u[n++] = data;
		if (ch == '\n')
			break;
	}
	return n > 0;
}

int build(int l1, int r1, int l2, int r2)
{
	if (l1 > r1)
		return 0;

	int root = post_order[r2];
	int t = l1;
	while (root != in_order[t])
		t++;
	int cnt = t - l1;
	lch[root] = build(l1, t - 1, l2, l2 + cnt - 1);
	rch[root] = build(t + 1, r1, l2 + cnt, r2 - 1);
	return root;
}

int best, best_sum;
void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (sum < best_sum || (sum == best_sum && u < best))
		{
			best = u;
			best_sum = sum;
		}
	}
	if (lch[u])
		dfs(lch[u], sum);
	if (rch[u])
		dfs(rch[u], sum);
}

int main()
{
	while (readData(in_order))
	{
		readData(post_order);
		build(0, n-1, 0, n-1);
		best_sum = 100000000;
		dfs(post_order[n-1], 0);
		printf("%d\n", best);
	}

	return 0;
}