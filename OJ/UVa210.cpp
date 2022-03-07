#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1000

int n;		//模拟的程序数目
int n0;		//每个模拟程序的语句数目
int t1, t2, t3, t4, t5;  //5条命令的所需时间
int Q;		//每个程序的配额
char prog[MAXN][10];
int ip[MAXN], var[26];
bool locked;
deque<int> redayQ;
queue<int> blockQ;


void run(int pid)
{
	int q = Q;
	while (q > 0)
	{
		char* p = prog[ip[pid]];
		switch (p[2])
		{
		case '=':		//赋值
			var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
			q -= t1;
			break;
		case 'i':		//print
			cout << pid << ": " << var[p[6] - 'a'] << endl;
			q -= t2;
			break;
		case 'c':		//lock
			if (locked)
			{
				blockQ.push(pid);
				return;
			}
			locked = true;
			q -= t3;
			break;
		case 'l':		//unlock
			locked = false;
			if (!blockQ.empty())
			{
				int pid2 = blockQ.front();
				blockQ.pop();
				redayQ.push_back(pid2);
			}
			q -= t4;
			break;
		case 'd':		//end
			return;
		}
		ip[pid]++;
	}
	redayQ.push_back(pid);
}

int main()
{
	cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
	int line = 0;
	for (int i = 0; i < n; i++)
	{
		cin.getline(prog[line++], 10);
		ip[i] = line - 1;
		while (prog[line - 1][2] != 'd')
			cin.getline(prog[line++], 10);
		redayQ.push_back(i);
	}

	locked = false;
	while (!redayQ.empty())
	{
		int pid = redayQ.front();
		redayQ.pop_front();
		run(pid);
	}


	return 0;
}
/*
3 1 2 1 1 1 3
a = 5
print a
a = 8
print a
b = 3
end
c = 5
print b
lock
print c
c = 4
print c
unlock
end
b = 5
lock
print b
unlock
end
*/