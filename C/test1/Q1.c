#include <stdio.h>
#define SIZE 100

int main(int argc, char* argv[]) {
    char buf[SIZE];

    printf("> ");
    // do until receive EOF
    while (scanf("%s", buf) != EOF) {
        int biggest_count = 0,
            temp_count = 0;  // biggest_count store longest char count,
                             // temp_count store current char count
        char biggest_char = buf[0],
             temp_char = buf[0];  // biggest_char store longest char, temp_char
                                  // store current char

        // do until end of sting
        for (size_t i = 0; buf[i] != '\0'; i++) {
            // if the char is same to temp_char
            if (buf[i] == temp_char) {
                temp_count++;

                // compare if current count is greater than the biggest one
                if (temp_count > biggest_count) {
                    biggest_char = temp_char;
                    biggest_count = temp_count;
                }
            } else {
                // reset template
                temp_char = buf[i];
                temp_count = 1;
            }
        }

        // output
        printf("The longest indentical character: %c, the length is %d\n\n> ",
               biggest_char, biggest_count);
    }

    return 0;
}