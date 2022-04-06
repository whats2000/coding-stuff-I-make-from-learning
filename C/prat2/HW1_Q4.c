#include <stdio.h>
#define SIZE 100

void isPalindrome(const char str[]);

void isPalindrome(const char str[]) {
    size_t len = 0;     // length of string
    short is_same = 1;  // flag check the reverse str is same as original
    char res_str[SIZE];

    // calculate the length of the string
    for (size_t i = 0; str[i] != '\0'; i++)
        len++;

    for (size_t i = 0; i < len; i++) {
        res_str[i] = str[len - i - 1];
    }

    printf("Reversed '%s' is '%s'.\n", str, res_str);

    for (size_t i = 0; i < len; i++)
        if (res_str[i] != str[i]) {
            is_same = 0;
            break;
        }

    if (is_same)
        printf("'%s' is a palindrome.\n", str);
    else
        printf("'%s' is not a palindrome.\n", str);
}

int main(int argc, char* argv) {
    char str[SIZE];

    printf("Please enter a string: ");
    scanf("%s", str);

    isPalindrome(str);
}