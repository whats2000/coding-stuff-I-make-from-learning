#include <iostream>
#include <cmath>
using namespace std;

double p = 0;
int t = 1;
double want = 0;

double check_double()
{
	double input;

	while (true)
	{
		cin >> input;
		
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "請重新輸入\n";
		}
	}
	return input;
	cout << input << endl;
}

double check_int()
{
	int input;

	while (true)
	{
		cin >> input;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "請重新輸入\n";
		}
	}
	return input;
	cout << input << endl;
}

double checknum()
{
	double num;
	while (true)
	{
		num = check_double();
		if (num < 0 || num >= 1)
			cout << "無效機率範圍，請重新輸入 v" << endl;
		else
			break;
	}
	return num;
}

long double chance(int x, double y)
{
	return 1 - pow(1 - y, x);
}

void caculate()
{
	double currentchance;
	do
	{
		currentchance = chance(t++, p);
	} while (currentchance < want);
	cout << "期望次數為 : " << t - 1 << endl;
	cout << "此機率為" << currentchance << endl;
}

int main(int argc, char *argv[])
{
	cout << "角色機率 : ";
	p = checknum();
	cout << "期望抽中角色最低機率(例如5成中我就滿意就打0.5) : ";
	want = checknum();
	caculate();
	cout << "自定義抽次數演算中獎機率，輸入抽卡次數 : ";
	t = check_int();
	cout << "抽 " << t << " 次中機率為 : " << chance(t, p);
	return 0;
}