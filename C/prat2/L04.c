#include <stdio.h>
#define SIZE 100

void uppercase(char const str[], size_t len);
void lowercase(char const str[], size_t len);
void reverse(char const str[], size_t len);

// To print a string in uppercase
void uppercase(char const str[], size_t len) {
    printf("The string after uppercased is: ");

    char c = '0';

    for (size_t i = 0; i < len; i++) {
        // Compare the characters if it is already uppercase
        if (str[i] >= 'a' && str[i] <= 'z')
            c = str[i] - ('a' - 'A');
        else
            c = str[i];

        // Stop program when the character is end of string
        if (str[i] == '\0')
            break;

        // Output the modify character
        printf("%c", c);
    }
}

// To print a string in lowercase
void lowercase(char const str[], size_t len) {
    printf("The string before lowercased is: ");

    char c = '0';

    for (size_t i = 0; i < len; i++) {
        // Compare the characters if it is already lowercase
        if (str[i] >= 'A' && str[i] <= 'Z')
            c = str[i] + ('a' - 'A');
        else
            c = str[i];

        // Stop program when the character is end of string
        if (str[i] == '\0')
            break;

        // Output the modify character
        printf("%c", c);
    }
}

// To print a reverse string
void reverse(char const str[], size_t len) {
    printf("When we make your input string reversed: ");

    // Get the length of the input string
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\0') {
            len = i;
            break;
        }
    }

    // print the string in reverse order
    for (size_t i = 0; i < len; i++) {
        if (str[len - i - 1] != '\n')
            printf("%c", str[len - i - 1]);
    }
}

int main(int argc, char* argv) {
    char str[SIZE];

    // input string
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    // output functions
    printf("Your input is: %s\n", str);

    uppercase(str, SIZE);

    lowercase(str, SIZE);

    reverse(str, SIZE);
}