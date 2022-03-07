#include <iostream>
using namespace std;



int main()
{
	int D, I;
	while (cin >> D >> I)
	{
		int k = 1;
		for (int i = 0; i < D - 1; i++)
		{
			if (I % 2)
			{
				k *= 2;
				I = (I + 1) / 2;
			}
			else
			{
				k = k * 2 + 1;
				I /= 2;
			}
		}
		cout << k << endl;

	}

	return 0;
}


/*
one
const int maxd = 20;
int s[1 << maxd];


int main()
{
	int D, I;
	while (cin >> D >> I)
	{
		memset(s, 0, sizeof(s));
		int k, n = (1 << D) - 1;
		for (int i = 0; i < I; i++)
		{
			k = 1;
			while (true)
			{
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n)
					break;
			}
			
		}
		cout << k / 2 << endl;
	}


	return 0;
}
*/