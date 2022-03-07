#include <stack>
#include <iostream>
using namespace std;

#define MAXN 1000

stack<int> s;
int n;
int target[MAXN];


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> target[i];
	}
	
	int ok = 1, a = 1, b = 1;
	while (b <= n)
	{
		if (a == target[b])
		{
			a++;
			b++;
		}
		else if (!s.empty() && s.top() == target[b])
		{
			s.pop();
			b++;
		}
		else if (a < target[b])
		{
			s.push(a);
			a++;
		}
		else
		{
			ok = 0;
			break;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;


	return 0;
}