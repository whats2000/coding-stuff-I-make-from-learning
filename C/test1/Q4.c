#include <stdio.h>
#define SIZE 100

void reverse(char str[]);

void reverse(char str[]) {
    // calculate length of the string
    size_t len;
    for (len = 0; str[len] != '\n' && str[len] != '\0'; len++)
        ;

    printf("%c", str[len - 1]);

    // change the last character to '\0'
    str[len - 1] = '\0';

    if (len > 1)
        reverse(str);
}

int main(int argc, char* argv[]) {
    char str[SIZE] = "";

    printf("> ");

    // same as scanf != EOF but using fgets
    while (fgets(str, sizeof(str), stdin) != NULL) {
        reverse(str);

        printf("\n\n> ");
    }

    return 0;
}
