#include <stdio.h>

int main(int argc, char* argv) {
    int num = 0;       // num = input arguments
    int a = 1, b = 1;  // a, b = template data

    // input number
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        if (i == 1)
            printf("F1 = 1\n");
        else if (i == 2)
            printf("F2 = 1\n");
        else {
            a += b;

            // swap a and b
            int t = a;
            a = b;
            b = t;

            printf("F%d = %d\n", i, b);
        }
    }
}