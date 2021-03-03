#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cassert>
#define Pi 3.141592653
//#define Pi 245850922 / 78256779
#define DegToRad Pi / 180
using namespace std;

typedef vector<int> BigInt; //階乘用

double input[2] = {0.0, 0.0}; //輸入緩存
char type;					  //運算指令
long double ans;			  //答案緩存
bool flag[2] = {true, true};  //迴圈控制
bool first = true;			  //首次輸入
//bool IsNum = true;
string check;
string degrad = "deg"; //弧度角度轉換

//三角函數
double useSin(double deg)
{
	double sine;
	if (degrad == "deg")
		sine = sin(deg * DegToRad);
	else
		sine = sin(deg);
	return sine;
}
double useCos(double deg)
{
	double cosine;
	if (degrad == "deg")
		cosine = cos(deg * DegToRad);
	else
		cosine = cos(deg);
	return cosine;
}
double useTan(double deg)
{
	double Tangant;
	if (degrad == "deg")
		Tangant = tan(deg * DegToRad);
	else
		Tangant = tan(deg);
	return Tangant;
}

//輸入數字
double checkdouble(int ty)
{
	double intput[2];
	//string ignore;

	while (true)
	{
		cin >> input[ty];
		//		first = false;
		//ignore = to_string(input[ty]);
		//cout << "執行cin數字 input[" << ty << "] = " << input[ty] << endl;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "請重新輸入\n";
		}
	}
	return input[ty];
	cout << input[ty] << endl;
}

//輸入運算符號
void checkchar()
{
	//	IsNum = false;
	cin >> type;
	//	cout << "成功輸入符號" << type << endl;
	//cout << "執行cin指令\n";
}

//char組列轉換數字
double checkCharNum()
{
	int t = 1;
	char buf[1024] = {
		type,
	};

	for (t; t <= 1023; t++)
	{
		cin >> buf[t];
		if (!isdigit(buf[t]) && buf[t] != '.')
			break;
	}
	type = buf[t];
	//	cout << "轉換" << atof(buf) << endl;
	//	cout << "輸入符號為" << type << endl;
	return atof(buf);
}

//大數加法(未完成)
BigInt BigAddition(BigInt num1, BigInt num2)
{
	BigInt result;
	int i;
	int product;

	if (num1 < num2)
		swap(num1, num2);

	for (i = sizeof(num1); i > 0; i--)

	{
		bool carry = 0;

		product = num1[i] + num2[i] + carry;

		if (product > 10)

		{
			result.push_back('0' + product % 10);

			carry = 1;
		}

		else

		{
			result.push_back('0' + product);

			carry = 0;
		}
	}
	return result;
}

//大數階乘
BigInt factorial(int n)
{
	assert(n >= 0 && n <= 10000);
	BigInt result;
	result.push_back(1);
	for (int factor = 1; factor <= n; ++factor)
	{
		int carry = 0;

		for (auto &item : result)
		{
			int product = item * factor + carry;
			item = product % 10000;
			carry = product / 10000;
		}
		if (carry > 0)
			result.push_back(carry);
	}
	return result;
}

//輸出陣列
void coutBigInt(const BigInt &number)
{
	if (number.empty())
		cout << "0\n"; // compiles to puts()
	else
	{
		cout << number.back();
		for (auto it = number.rbegin() + 1; it != number.rend(); ++it)
		{
			cout.fill('0');
			cout.width(4);
			cout << *it;
		}
		cout << endl;
	}
}

//大數指數
BigInt BigIndex(int num, int t)
{
	assert(num >= 0 && t >= 0 && num <= 10000 && t <= 10000);
	BigInt result;
	result.push_back(num);

	for (int i = 0; i < t; i++)
	{
		int carry = 0;

		cout << 100 * i / t << "%\r";
		for (auto &item : result)
		{
			int product = item * num + carry;

			item = product % 10000;
			carry = product / 10000;
		}
		if (carry > 0)
			result.push_back(carry);
	}
	return result;
}

//小數位數
int decimal(double num)
{
	int i = 0, j = 0;
	string buf;

	buf = to_string(num * 10);
	//cout << "抄寫為" << setprecision(7) << buf << endl;
	reverse(buf.begin(), buf.end());
	//cout << "抄寫為" << setprecision(7) << buf << endl;
	for (i = 0; i < buf.length(); i++)
	{
		if (buf[i] == '0')
			buf[i] = 0;
		else if (buf[i] == '.')
		{
			break;
		}
		else
			/*cout <<*/ j++;
	}
	//cout << "抄寫為" << setprecision(7) << j << endl;
	//cout << "抄寫為" << setprecision(7) << buf << endl;
	return j;
}

//char及float兩數合併
double charplusdouble(char a, double b)
{
	string s = to_string(a - 48) + to_string(b);
	cout << "合成" << s << endl;
	//	IsNum = false;
	return stof(s);
}
//提示
void prompt()
{
	cout << "歡迎使用whats2000_練習用計算機程式\n如果有錯誤請回報\n指令：\n加法'+'\n減法'-'\n乘法'*'\n除法'/'\n階乘'!'\n餘數'%'\n指數'^'\n三角函數指令 <數字><命令> \nsin's'\ncos'c'\ntan't'\nreset answer'x'\n提示'?'\ndeg/rad = " << degrad << endl;
}

//主程序
int main()
{
	BigInt result;
	prompt();
start:
	//	if (first == true)
	//		goto first_type;
	while (flag[0] == true)
	{
		flag[1] = true;
		//ans = 0;
		//ans = checkdouble(0);
		//if (IsNum == true)
		//			ans = charplusdouble(type,input[0]);

		//		cout << "測試為" << ans << endl;
		//	first_type:
		while (flag[1] == true && flag[0] == true)
		{
			input[0] = ans;
			checkchar();
			//		cout << "測試為" << type << endl
			if (isdigit(type))
			{
				input[0] = checkCharNum();
				first = false;
				//cout << "test ans " << ans << endl;
				/*type -= 48;
				ans = ans * 10 + type * pow(10, -decimal(ans / 10));
				cout << "⇒" << ans << endl;*/
				goto typechar;
			}
			else
			{
			typechar:
				if (type == 'p')
					input[0] = Pi;
				switch (type)
				{
				case '+':
					ans = input[0] + checkdouble(1);
					cout << input[0] << "+" << input[1] << "=" << ans << endl;
					break;
				case '-':
					ans = input[0] - checkdouble(1);
					cout << input[0] << "-" << input[1] << "=" << ans << endl;
					break;
				case '/':
					ans = input[0] / checkdouble(1);
					if (input[1] != 0)
						cout << input[0] << "/" << input[1] << "=" << ans << endl;
					else
						cout << "Unintentional";
					break;
				case '*':
					ans = input[0] * checkdouble(1);
					cout << input[0] << "*" << input[1] << "=" << ans << endl;
					break;
				case '!':
					if (input[0] >= 0 && input[0] <= 10000)
					{
						result = factorial((int)input[0]);
						cout << input[0] << "!"
							 << "=";
						coutBigInt(result);
					}
					else
					{
						goto charerror;
					}
					break;
				case '%':
					int inputint[2];
					inputint[0] = input[0] + 0.5;
					inputint[1] = checkdouble(1) + 0.5;
					ans = inputint[0] % inputint[1];
					cout << input[0] << "%" << input[1] << "=" << ans << endl;
					break;
				case '^':
					input[1] = checkdouble(1);
					if (0 <= input[0] && input[1] <= 10000)
					{
						ans = pow(input[0], input[1]);
						if (input[0] == 0 && input[1] == 0)
							cout << "Unintentional";
						else if (ans > 0 && !isinf(ans))
							cout << input[0] << "^" << input[1] << "=" << ans << endl;
						else if (input[0] == 0)
							cout << input[0] << "^" << input[1] << "=" << ans << endl;
						else
						{
							result = BigIndex(input[0], input[1]);
							coutBigInt(result);
						}
					}
					else
					{
						cout << "overflow\nreset number";
						ans = 0;
					}
					break;

				case 'p':
					if (first == true)
						ans = Pi;
					else
						ans *= Pi;
					cout << ans << endl;
					break;

				case 's':
					if (first == true)
						ans = checkdouble(0);
					ans = useSin(input[0]);
					cout << "sin(" << input[0];
					if (degrad == "deg")
						cout << "°";
					cout << ")=" << ans << endl;
					break;
				case 'c':
					if (first == true)
						ans = checkdouble(0);
					ans = useCos(input[0]);
					cout << "cos(" << input[0];
					if (degrad == "deg")
						cout << "°";
					cout << ")=" << ans << endl;
					break;
				case 't':
					if (first == true)
						ans = checkdouble(0);
					ans = useTan(input[0]);
					cout << "tan(" << input[0];
					if (degrad == "deg")
						cout << "°";
					cout << ")=" << ans << endl;
					break;
				case 'd':
					checkchar();
					switch (type)
					{
					case 'e':
						//cout << "偵測輸入符號" << type << endl;
						checkchar();
						switch (type)
						{
						case 'g':
							//cout << "偵測輸入符號" << type << endl;
							degrad = "deg";
							cout << "swich to deg" << endl;
							break;
						default:
							goto charerror;
						}
						break;
					default:
						goto charerror;
					}
					break;
				case 'r':
					//cout << "偵測輸入符號" << type << endl;
					checkchar();
					switch (type)
					{
					case 'a':
						//cout << "偵測輸入符號" << type << endl;
						checkchar();
						switch (type)
						{
						case 'd':
							//cout << "偵測輸入符號" << type << endl;
							degrad = "rad";
							cout << "swich to rad" << endl;
							break;
						default:
							goto charerror;
						}
						break;
					}
					break;
				case 'e':
					//cout << "偵測輸入符號" << type << endl;
					checkchar();
					if (isdigit(type))
					{
						input[1] = checkCharNum();
					}
					else
						switch (type)
						{
						case 's':
							//cout << "偵測輸入符號" << type << endl;
							checkchar();
							switch (type)
							{
							case 'c':
								//cout << "偵測輸入符號" << type << endl;
								system("pause");
								return 0;
							default:
								goto charerror;
							}
							break;
						default:
							goto charerror;
						}
					break;
				case 'x':
					cout << "reset answer" << endl;
					first = true;
					goto start;
				case '?':
					prompt();
					break;
				default:
				charerror:
					cout << "未知指令 請重新輸入\n";
					checkchar();
					goto typechar;
				}
			}
		}
	}
}