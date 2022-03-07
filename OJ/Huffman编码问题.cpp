#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	char c;
	int num;
	Node* left, * right;
};

bool compre(Node* p, Node* q)
{
	return p->num < q->num;
}

Node* buildHuffmanTree(vector<Node*> &v)
{
	while (v.size() > 1)
	{
		sort(v.begin(), v.end(), compre);

		Node* first = v[0];
		Node* second = v[1];
		Node* temp = new Node;
		temp->left = first;
		temp->right = second;
		temp->num = first->num + second->num;

		vector<Node*>::iterator iter;
		iter = v.erase(v.begin(), v.begin() + 2);
		v.push_back(temp);
	}
	return v[0];
}

void printHuffmanTree(Node* t, int i, int *c)
{
	if (t->left == NULL && t->right == NULL)
	{
		cout << t->c << " : " << t->num << "  ---->";
		for (int j = 0; j < i; j++)
			cout << c[j];
		cout << endl;
		return;
	}
		

	if (t->left != NULL)
	{
		c[i] = 0;
		printHuffmanTree(t->left, i + 1, c);
	}
		
	if (t->right != NULL)
	{
		c[i] = 1;
		printHuffmanTree(t->right, i + 1, c);
	}
		
}


int main()
{
	int n;
	cin >> n;
	vector<Node*> v;
	for (int i = 0; i < n; i++)
	{
		Node* data = new Node;
		cin >> data->c >> data->num;
		data->left = NULL;
		data->right = NULL;
		v.push_back(data);
	}

	Node* root = buildHuffmanTree(v);
	
	int c[100];
	printHuffmanTree(root, 0, c);

	return 0;
}