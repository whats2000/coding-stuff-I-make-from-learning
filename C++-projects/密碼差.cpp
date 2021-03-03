#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string input;
    char x[1000];
    long int sum[2];
    cin >> input;
    strcpy(x, input.c_str());
    for (int i = 0; i < input.length(); i++)
    {
        if (i % 2)
        {
            x[i + 2] += x[i];
        }
        else
        {
            x[i + 2] += x[i];
        }
    }
    cout << abs(x[input.length() - 1] - x[input.length() - 2]);
    return 0;
}