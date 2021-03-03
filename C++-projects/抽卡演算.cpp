#include <iostream>
#include <functional>
#include <random>
#include <string>
#include <iomanip>
 
using namespace std;

int numrare;
double rarechance[10];
double currentchance;
double lastchance = 1;
char type;
int counttime[10];
int sum;
int times;

int checkCharNum()
{
	int t = 1;
	char buf[1024] = {
		type,
	};

	for (t; t <= 1023; t++)
	{
		cin >> buf[t];
		if (!isdigit(buf[t]) && buf[t] != '\n')
			break;
	}
	type = buf[t];
	//cout << "轉換" << atof(buf) << endl;
	//cout << "輸入符號為" << type << endl;
	return atoi(buf);
}

double randnum(int smin, int smax)
{
	random_device rd;			 // 種子產生器
	mt19937 gen = mt19937(rd()); //使用mt19937引擎
	uniform_real_distribution<> dis(smin, smax);
	auto randfun = bind(dis, gen);
	return randfun();
}

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

double checknum(double smin, double smax)
{
	double num;
	while (true)
	{
		num = check_double();
		if (num < smin || num >= smax)
			cout << "無效機率範圍，請重新輸入 v" << endl;
		else
			break;
	}
	return num;
}

string rarestring(int num)
{
	switch (num)
	{
	case 0:
		return " E X ";
	case 1:
		return "SSS R";
	case 2:
		return " SSR ";
	case 3:
		return " S R ";
	case 4:
		return "  A  ";
	case 5:
		return "  B  ";
	case 6:
		return "  C  ";
	case 7:
		return "  D  ";
	case 8:
		return "  E  ";
	case 9:
		return "  F  ";
	default:
		return "unkown";
	}
}

int main(int argc, char *argv[])
{
	cout << "請輸入稀有度分級數 : ";
	numrare = checknum(1, 1024);
	string rarestr[1024];

	cout << "是否採用預設稀有度分級 Y/N : ";
	cin >> type;
	if (type == 'Y' || type == 'y')
	{
		for (int i = 0; i < numrare; i++)
		{
			rarestr[i] = rarestring(i);
			//cout << rarestr[i] << endl;
		}
	}
	for (int i = 0; i < numrare - 1;)
	{
		if (type != 'Y' && type != 'y')
		{
			cout << "設置抽卡種類 : ";
			cin >> rarestr[i];
		}
		cout << "設置抽卡 " << rarestr[i] << " 的機率 : ";
		while (true)
		{
			rarechance[i] = checknum(0, 1);
			if (lastchance < rarechance[i])
			{
				cout << "機率總合不可能大於1，請重新輸入" << endl;
			}
			else
			{
				lastchance -= rarechance[i];
				if (i > 0)
					rarechance[i] += rarechance[i - 1];
				i++;
				break;
			}
		}
	}
	if (type != 'Y' && type != 'y')
	{
		cout << "設置抽卡種類 : ";
		cin >> rarestr[numrare - 1];
	}
	cout << "設置抽卡 " << rarestr[numrare - 1] << " 的機率 : " << lastchance << endl;
	cout << "按\" x  \"結束，其餘按數字後按其他鍵會自動執行輸入次數抽卡演算" << endl;
	while (cin >> type)
	{
		if (type == 'x')
			break;
		else if (isdigit(type))
			times = checkCharNum();
		else
			times = 1;
		cout << "是否顯示每次抽卡 Y/N : (一萬次以上建議關閉)";
		cin >> type;
		for (int h = 0; h < times; h++)
		{
			cout << setprecision(sizeof(h) - 2) << (double)100 * h / times << "%\r";
			for (int j = 0; j < 10; j++)
			{
				currentchance = randnum(0, 1);
				//cout << "當前抽卡編號為" << currentchance << endl;
				for (int i = 0; i < numrare - 1; i++)
				{
					if (currentchance < rarechance[i])
					{
						if (type == 'y' || type == 'Y')
							cout << "[" << rarestr[i] << "] ";
						counttime[i]++;
						goto end;
					}
				}
				if (type == 'y' || type == 'Y')
					cout << "[" << rarestr[numrare - 1] << "] ";
				counttime[numrare - 1]++;
			end:
				if (j == 4 && (type == 'y' || type == 'Y'))
					cout << endl;
			}
			sum += 10;
			if (type == 'y' || type == 'Y')
				cout << endl;
			if (h == times - 1)
			{
				for (int i = 0; i < numrare; i++)
				{
					cout << "累積抽中[" << rarestr[i] << "] : " << counttime[i] << "次，佔 " << setprecision(10) << (double)counttime[i] / sum << endl;
				};
			}
			if (type == 'y' || type == 'Y')
				cout << endl;
		}
	}
	return 0;
}
