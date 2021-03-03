#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int a;
	int b;
	printf("¿é¤J¾ã¼Æ\n");
	scanf("%d",&b);
		for(i=1;i<=b;i++)
	{
			for(a=1;a<=i-1;a++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	for(i=1;i<=b;i++)
	{
			for(a=1;a<=b-i+1;a++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	system("Pause");
}
