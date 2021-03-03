#include <iostream>
#include <math.h>
using namespace std;
#define DegToRad 3.141592653/180
float useSin(float deg)
{
	while(deg>=360)
	{
		deg -=360;
	}
	double sine=sin(deg*DegToRad);
	return sine;
}
int main()
{
	float degree;
	while(degree >= 0)
	{
	cin >> degree;
	double y = useSin(degree);
	cout << "sin(" << degree << "°)=" << y << endl;
	}
}