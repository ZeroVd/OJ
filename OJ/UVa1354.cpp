#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int maxd = 6;

struct Node
{
	int w;
	Node* left;
	Node* right;
	Node() :w(0), left(NULL), right(NULL) {}
};

int n, w[maxd];
double r;

void dfs()
{

}


int main()
{
	int  T = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %d", &r, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);

	}


	return 0;
}