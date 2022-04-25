#include <stdio.h>

void print_sum(const int num);

// To find  sums of a set (or multiple sets) of consecutive numbers
void print_sum(const int num) {
    // To calculate the amount of the set
    int count = 0;

    // Average of the set will always step by 0.5
    for (float i = 1; i < (num + 1) / 2; i += 0.5) {
        // (number) / (average of the set) will always be a integer
        if ((10 * num) % (int)(10 * i) == 0) {
            // if we found there are even amounts of the set
            if ((int)(num / i) % 2 == 0) {
                // To use the median to found the first and the last elements of
                // the set
                int adjust = (int)(num / i) / 2;

                // The minimum number of the set have to be greater than 0
                if ((int)(i + 0.5) - adjust > 0) {
                    printf("%d to %d\n", (int)(i + 0.5) - adjust,
                           (int)(i + 0.5) + adjust - 1);

                    count++;
                }
            } else {
                // To use the median to found the first and the last elements of
                // the set
                int adjust = ((int)(num / i) - 1) / 2;

                // The minimum number of the set have to be greater than 0
                if ((int)i - adjust > 0) {
                    printf("%d to %d\n", (int)i - adjust, (int)i + adjust);

                    count++;
                }
            }
        }
    }

    printf("There are total %d set(s)", count);
}

int main(int argc, char* argv[]) {
    int num = 0;  // number we are going to evaluate

    // intput
    printf("Please enter a number: ");

    // do until receive EOF
    while (scanf("%d", &num) != EOF) {
        // output
        print_sum(num);

        printf("\n\nPlease enter a number: ");
    }

    return 0;
}