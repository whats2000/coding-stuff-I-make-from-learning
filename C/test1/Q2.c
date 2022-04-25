#include <stdio.h>

short is_prime_num(int n);

// evaluate if the number is prime number
short is_prime_num(int n) {
    if (n == 1)
        return 0;
    for (size_t i = 2; i < n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(int argc, char* argv[]) {
    int num = 0;

    printf("> n: ");

    // do until receive EOF
    while (scanf("%d", &num) != EOF) {
        size_t i = 0;
        // do from reverse order
        for (i = num - 1; i > 0; i--) {
            if (is_prime_num(i) && is_prime_num(num - i))
                break;
        }

        // output
        printf(
            "The max gap of the pairs of primes given "
            "n = %d is %zu - %zu = %d\n\n> n: ",
            num, i, num - i, (int)(i) - (num - (int)(i)));
    }

    return 0;
}
