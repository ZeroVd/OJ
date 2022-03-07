#include <iostream>
using namespace std;

char s1[6], s2[6], s[6];

bool isSame()
{
	int i = -1, f1 = 1, f2 = 1;
	while (i < 6 && s2[++i] != s1[0]);	//寻找到s2中与s1的首字母相同的字母的下标
	if (i >= 6)
		return false;
	s[0] = s1[0];
	s[5] = s1[5];
	int p = i;
	i = (++i) % 6;
	for (int j = 1; j < 5; j++, i++)
	{
		if (i == (5 - p))
		{
			j--;
			continue;
		}	
		s[j] = s2[i % 6];					//将调整好数据顺序的字符串保存到s
	}
		

	
	i = 0;
	while (i < 5 && s[++i] != s1[1]);	//寻找需要对比的4个字符的首下标
	if (i >= 5)
		return false;
	int m = i;
	for (int t = 1; t < 5; t++, m++)
	{
		if (m == 5)
			m = 1;
		if (s1[t] != s[m])
			f1 = 0;
	}
	if (f1 == 1)
		return true;

	m = i;
	for (int t = 1; t < 5; t++, m--)
	{
		if (m == 0)
			m = 4;
		if (s1[t] != s[m])
			f2 = 0;
	}
	if (f2 == 1)
		return true;

	return false;
	


}

int main()
{
	while (cin >> s1 >> s2 && s1[0] != '#')
	{
		isSame() ? cout << "Yes" << endl : cout << "No" << endl;
	}


	return 0;
}
