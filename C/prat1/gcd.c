#include <stdio.h>

int main(int argc, char* argv) {
    int a = 0, b = 0;  // a, b = input number

    // input number
    scanf("%d %d", &a, &b);

    // make a is always greater than b
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }

    // process functinative
    while (b != 0) {
        int t = b;

        b = a % b;

        a = t;
    }

    // output number
    printf("%d", a);
}