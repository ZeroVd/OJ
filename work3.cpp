#include <iostream>
using namespace std;
#define LL long long

double res;
LL f[50];


int main()
{
	f[1]  = 1;
	for(int i=2; i<40; i++)
		f[i] = f[i-1]*i;
	
	for(int i=1; i<40; i++) 
		res += 1.0/f[i];
	
	cout << res;
	return 0;
}
