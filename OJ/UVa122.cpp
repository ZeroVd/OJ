#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 20;


struct Node
{
	bool isValue = false;
	int v;
	Node* left, * right;
	Node() :isValue(false), left(NULL), right(NULL) {}
};

Node *root = NULL;


bool failed = false;
void addNode(int data, char *pos)
{
	Node* currentNode = root;
	int n = strlen(pos) - 1;
	for (int i = 0; i < n; i++)
	{
		if (pos[i] == 'L')
		{
			if (currentNode->left == NULL)
				currentNode->left = new Node();
			currentNode = currentNode->left;
		}
		else if (pos[i] == 'R')
		{
			if (currentNode->right == NULL)
				currentNode->right = new Node();
			currentNode = currentNode->right;
		}
	}
	if (currentNode->isValue) 
		failed = true;
	currentNode->v = data;
	currentNode->isValue = true;
}
void remove_tree(Node* u) {
	if (u == NULL) 
		return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}

char s[maxn];
bool read_input()
{
	failed = false;
	remove_tree(root);
	root = new Node();
	while(true)
	{
		if (scanf("%s", s) != 1)
			return false;
		if (!strcmp(s,"()"))
			break;
		int data = 0;
		sscanf(&s[1], "%d", &data);
		addNode(data, strchr(s, ',')+1);
	}
	return true;
}


vector<int> ans;
bool bfs()
{
	queue<Node *> q;
	q.push(root);
	ans.clear();
	while (!q.empty())
	{
		Node* t = q.front();
		if (!t->isValue)
			return false;
		ans.push_back(t->v);
		if (t->left != NULL)
			q.push(t->left);
		if (t->right != NULL)
			q.push(t->right);
		//delete t;
		q.pop();
	}
	return true;
}



int main()
{
	while (read_input())
	{
		int i = 0;
		if (!bfs() || failed == true)
			printf("not complete");
		else
		{
			int len = ans.size();
			for (int i = 0; i < len; i++)
			{
				if (i != 0)
					printf(" ");
				printf("%d", ans[i]);
			}
		}
			
		printf("\n");
	}
	
	return 0;
}
