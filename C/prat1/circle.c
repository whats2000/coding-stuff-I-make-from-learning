#include <stdio.h>

int main(int argc, char* argv) {
    int radius = 0;  // number of circle radius

    // input radius
    scanf("%d", &radius);

    // draw circle
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++)
            if (i * i + j * j <= radius * radius)
                printf("*");
            else
                printf(" ");

        printf("\n");
    }
}