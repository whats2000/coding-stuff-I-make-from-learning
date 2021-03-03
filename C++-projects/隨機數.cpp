#include <random>
#include <iostream>
using namespace std;

int main()
{
    std::random_device rd;
    cout << rd();
}