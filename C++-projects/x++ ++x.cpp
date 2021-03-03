#include <iostream>
using namespace std;
int main()
{
	int x = 5;
	int y = 5;
	cout << x++ * ++x << endl;
	cout << ++y * y++ << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y;
}