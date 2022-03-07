#include <iostream>
#include <algorithm>
using namespace std;

struct Section {
	int l, r;
	bool operator<(Section& t) {
		return r < t.r;
	}
};
Section program[151];
int n;
int r1 = -1, r2 = -1;
int ans = 0;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> program[i].l >> program[i].r;
	}
	sort(program, program + n);

	for (int i = 0; i < n; i++)
	{
		if (r1 <= program[i].l)
		{
			ans++;
			r1 = program[i].r;
		}
		else if (r2 <= program[i].l)
		{
			ans++;
			r2 = program[i].r;
			swap(r1, r2);
		}
	}

	cout << ans << endl;

	return 0;
}