#include <iostream>
#include <algorithm>
using namespace std;


struct Section {
	int l, r;
	bool operator<(Section& t)
	{
		return r < t.r;
	}
		
};
int n;
Section s[100];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].l >> s[i].r;
	}
	sort(s, s + n);

	


	return 0;
}