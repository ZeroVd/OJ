#include <iostream>
using namespace std;
#include <stack>
#include <cstdio>
#include <string>
#include <cctype>

struct Matrix
{
	int a, b;
	Matrix(int a = 0, int b = 0)
		:a(a), b(b){}
}m[26];

stack<Matrix> s;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		cin >> m[name[0] - 'A'].a >> m[name[0] - 'A'].b;
	}

	string expr;
	while (cin >> expr)
	{
		int ans = 0;
		bool error = false;
		for (int i = 0; i < expr.length(); i++)
		{
			if (isalpha(expr[i]))
				s.push(m[expr[i] - 'A']);
			else if (expr[i] == ')')
			{
				Matrix m2 = s.top();
				s.pop();
				Matrix m1 = s.top();
				s.pop();
				if (m1.b != m2.a)
				{
					error = true;
					break;
				}
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b));
			}
		}
		if (error)
			cout << "error" << endl;
		else
			cout << ans << endl;

	}


	return 0;
}