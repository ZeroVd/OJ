/*

首先，将所有编码保存到一个二维数组code[len][i]中，其中len表示该编码长度，i表示该编码的编号；
然后，读取编码，先读取三位确定编码长度len，再逐个读取编码，每len个编码组成的二进制数转化为十进制数，
	即为该编码在coed中对应的编号，之后输出对应编码，当读到len个1时，此长度编码读取结束，在读取3位，
	重新确定编码长度，重读上述模式，直至编码读取结束；


2020/7/25 16:58			by Zero

*/


#include <iostream>
using namespace std;



int code[8][1 << 8];


int readchar()
{
	while (true)
	{
		int ch = getchar();
		if (ch != '\n' || ch != '\r')
			return ch;
	}
}

int readint(int c)
{
	int v = 0;
	while (c--)
	{
		v = v * 2 + readchar() - '0';
	}
	return v;

}

int readcodes()
{
	memset(code, 0, sizeof(code));		//清空数组
	
	code[1][0] = readchar();
	for (int len = 2; len < 8; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			int ch = getchar();
			if (ch == EOF)
				return 0;
			if (ch == '\n' || ch == '\r')
				return 1;
			code[len][i] = ch;
		}
	}
	return 1;
}

int main()
{
	while (readcodes())
	{
		while (true)
		{
			int len = readint(3);
			if (len == 0)
				break;

			while (true)
			{
				int v = readint(len);
				if (v == (1 << len) - 1)
					break;
				putchar(code[len][v]);

			}
			cout << endl;
		}
	}



	system("pause");
	return 0;
}