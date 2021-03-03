#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	while (true)
	{
	start:
		char ox[9];
		for (int t = 0; t < 9; t++)
			cin >> ox[t];

		if (ox[4] != '.' && ox[0] == ox[4] && ox[4] == ox[8])
		{
			cout << ox[0] << " wins";
			continue;
		}
		else if (ox[4] != '.' && ox[2] == ox[4] && ox[4] == ox[6])
		{
			cout << ox[0] << " wins";
			continue;
		}
		else
			for (int t = 0; t <= 2; t++)
			{
				if (ox[t] != '.' && ox[t] == ox[t + 3] && ox[t + 3] == ox[t + 6])
				{
					cout << ox[t] << " wins";
					goto start;
				}
				else if (ox[3 * t] != '.' && ox[3 * t] == ox[3 * t + 1] && ox[3 * t + 1] == ox[3 * t + 2])
				{
					cout << ox[3 * t] << " wins";
					goto start;
				}
			}
		for (int t = 0; t < 9; t++)
			if (ox[t] == '.')
			{
				cout << "not end";
				goto start;
			}
		cout << "Draw";
	}
}