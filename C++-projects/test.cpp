#include <stdio.h>

int main(void)
{

 int height, min;

 printf("Please input the height of the pyramid:");
 scanf("%d", &height);

 printf("Please input the min star:");
 scanf("%d", &min);

 for (int i = 1; i <= height; i++)
 {

		while (height - i)
		{
			printf(" ");
		}

		while (i <= min + 2 * (i - 1))
		{
			printf("*");
		}

		printf("\n");
 }

 return 0;
}