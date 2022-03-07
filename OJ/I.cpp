#include <bits/stdc++.h>
using namespace std;


int main()
{
	char str[200005];
	cin >> str;
	int ans = 0;
	for (int i = 0; i < strlen(str) - 6; i++) {
		if (str[i] == 'y' && str[i + 1] == 'l' && str[i + 2] == 'n' &&
			str[i + 3] == 'y' && str[i + 4] == 'w' && str[i + 5] == 'y' && str[i + 6] == 's')
			ans++;
	}
	cout << ans;
	return 0;
}