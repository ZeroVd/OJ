/*

���ȣ������б��뱣�浽һ����ά����code[len][i]�У�����len��ʾ�ñ��볤�ȣ�i��ʾ�ñ���ı�ţ�
Ȼ�󣬶�ȡ���룬�ȶ�ȡ��λȷ�����볤��len���������ȡ���룬ÿlen��������ɵĶ�������ת��Ϊʮ��������
	��Ϊ�ñ�����coed�ж�Ӧ�ı�ţ�֮�������Ӧ���룬������len��1ʱ���˳��ȱ����ȡ�������ڶ�ȡ3λ��
	����ȷ�����볤�ȣ��ض�����ģʽ��ֱ�������ȡ������


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
	memset(code, 0, sizeof(code));		//�������
	
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