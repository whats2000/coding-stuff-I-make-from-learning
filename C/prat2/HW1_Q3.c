#include <stdio.h>
#define SIZE 100

int wordCount(const char str[]);

int wordCount(const char str[]) {
    int count = 0;      // count of spaces
    short is_word = 0;  // flag check is the last character is word

    // check the string
    for (size_t i = 0; str[i] != '\0'; i++) {
        // ignore ' ', '\n', number, and the last character is alphabet
        if (str[i] == ' ' || str[i] == '\n' ||
            (str[i] >= '0' && str[i] <= '9')) {
            is_word = 0;
        }
        // if the last character is not alphabet then the new word is begins
        // with str[i], only count when the first characterin word is appear
        else if (!is_word) {
            is_word = 1;
            count++;
        }
    }

    return count;
}

int main(int argc, char* argv) {
    char str[SIZE] = " ";

    printf("Input a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Total %d words.\n", wordCount(str));
}
