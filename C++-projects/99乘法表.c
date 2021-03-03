#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int l;
	l=1;
	for(l=1;l<=9;l++)
	{ 
		for(n=1;n<=9;n++)
		{
			printf("%dx%d=%d\t",l,n,l*n);
		}
		printf("\n");
	}	
	return 0;
}

