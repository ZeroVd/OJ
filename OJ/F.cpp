#include <bits/stdc++.h>
using namespace std;

const int N=100005;
string str;
int n,res;
char q[N];
int cnt[3];

int main()
{
	cin >> n >> str;
	int k=0;
	int hh=0;
	for(int i=0; i<n; i++){
		q[hh++] = str[i];
		if(hh>=3 && q[hh-1]=='c' && q[hh-2]=='f' && q[hh-3]=='z') res++, hh-=3;
	}
	cout << res;
	return 0;
}