#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int n;
int snowflakes[1000010];

int max_num, _start, _end;



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> snowflakes[i];
		max_num = _start = _end = 0;
		set<int> s;
		while (_end < n)
		{
			while (_end < n && !s.count(snowflakes[_end]))
				s.insert(snowflakes[_end++]);
			max_num = max(max_num, _end - _start);
			s.erase(snowflakes[_start++]);
		}
		cout << max_num << endl;
	}
	return 0;
}