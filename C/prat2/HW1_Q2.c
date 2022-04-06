#include <stdio.h>

int countPairs(int a[], int length);

int main(void) {
    // test data 1
    int a[7] = {1, 2, 4, 5, 3, 9, 3};
    int length1 = sizeof(a) / sizeof(a[0]);       // array length
    int result1 = countPairs(a, length1);         // call frontback function
    printf("Test 1 have %d pair(s)\n", result1);  // output result
    // test data 2
    int b[7] = {3, 6, 2, 1, 4, 5, 2};
    int length2 = sizeof(b) / sizeof(b[0]);
    int result2 = countPairs(b, length2);
    printf("Test 2 have %d pair(s)\n", result2);
    // test data 3
    int c[6] = {3, 5, 1, 4, 1, 10};
    int length3 = sizeof(c) / sizeof(c[0]);
    int result3 = countPairs(c, length3);
    printf("Test 3 have %d pair(s)\n", result3);
    // test data 4
    int d[6] = {1, 1, 1, 1, 1, 1};
    int length4 = sizeof(d) / sizeof(d[0]);
    int result4 = countPairs(d, length4);
    printf("Test 4 have %d pair(s) \n", result4);
    return (0);
}
int countPairs(int a[], int length) {
    // your function body
    int pre_sum[length], suf_sum[length];  // template array to stroe result
    int count = 0;                         // count the amount of pairs

    // prefix sum of a
    for (size_t i = 0; i < length; i++) {
        pre_sum[i] = a[i];

        if (i > 0)
            pre_sum[i] += pre_sum[i - 1];
    }

    // suffix sum of a
    for (size_t i = 0; i < length; i++) {
        suf_sum[i] = a[length - i - 1];

        if (i > 0)
            suf_sum[i] += suf_sum[i - 1];
    }

    // compare prefix sum of a and suffix sum of a
    for (size_t i = 0; i < length; i++)
        for (size_t j = 0; j < length; j++)
            if (pre_sum[i] == suf_sum[j])
                count++;

    return count;
}