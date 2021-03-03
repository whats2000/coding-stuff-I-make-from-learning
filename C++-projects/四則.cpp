#include <iostream>
#include <cstdlib>

using namespace std;

double Eval2(istream &iss)
{
	double Eval0(istream & iss);
	double res = 0;
	if (iss.peek() == '(' && iss.get())
	{
		res = Eval0(iss);
		iss.peek() == ')' && iss.get();
	}
	else
	{
		iss >> res;
	}
	cout << "Eval2 res = " << res << endl;
	return res;
}

double Eval1(istream &iss)
{
	double res = Eval2(iss);
	cout << "Eval1 res1 = " << res << endl;
	while (iss.peek() == '*' || iss.peek() == '/')
		(iss.get() == '*') ? (res *= Eval2(iss)) : (res /= Eval2(iss));
	cout << "Eval1 res2 = " << res << endl;
	return res;
}

double Eval0(istream &iss)
{
	double res = Eval1(iss);
	cout << "Eval0 res1 = " << res << endl;
	while (iss.peek() == '+' || iss.peek() == '-')
		res += (iss.get() == '+') ? Eval1(iss) : -Eval1(iss);
		cout << "Eval0 res2 = " << res << endl;
	return res;
}

int main()
{
	while(true)
	cout << Eval0(cin) << endl;
	system("pause");
}