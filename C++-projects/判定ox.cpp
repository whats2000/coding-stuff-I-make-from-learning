#include <iostream>
using namespace std;
int main() {
    int ai, bi; bool ans;
    cin >> ai >> bi >> ans;
    bool a = ai != 0;
    bool b = bi != 0;
    bool impossible = true;
    if ((a && b) == ans) cout << "AND\n", impossible = false;
    if ((a || b) == ans) cout << "OR\n", impossible = false;
    if ((a ^ b) == ans) cout << "XOR\n", impossible = false;
    if (impossible) cout << "IMPOSSIBLE";

    return 0;
}

