#include <stdio.h>

int main(int argc, char* argv) {
    int num = 0;       // num = input arguments
    int a = 1, b = 1;  // a, b = template data
    int i = 0;

    // input number
    scanf("%d", &num);

    // 將地一次及第二次獨立計算此外，其餘計算皆為將兩者合存於a後a, b交換
    for (i = 1; i <= num; i++) {
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