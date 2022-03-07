#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int arr[30];
int n;

void reversal(int y)
{
	int m = y / 2;
	for (int i = 0; i <= m; i++)
		swap(arr[i], arr[y - i]);
	cout << (n - y) << " ";
}


int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << s << endl;
		stringstream ss(s);
		n = 0;
		while (ss >> arr[n])
			n++;
		
		for (int i = 0; i < n; i++)
		{
			int m = max_element(arr, (arr + n - i)) - arr;
			if (m == n - i - 1)
				continue;
			if (m != 0)
				reversal(m);
			reversal(n - i - 1);
		}
		cout << "0" << endl;
	}


	return 0;
}