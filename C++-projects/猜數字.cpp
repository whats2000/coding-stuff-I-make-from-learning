#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n;
	srand(time(NULL));
	n=rand()%101;
	printf("%d\n",n);
	int guess=0;
	int max=100;
	int min=0;
	while(guess!=n)
	{
		printf("請輸入您的猜測從%d~%d\n",min,max);
		scanf("%d",&guess);
		if(guess<max && guess>n)
			max=guess;
		else if(guess>min && guess<n)
			min=guess;
		else if(guess>max||guess<min)
			printf("error\n");	
		else if(guess==n)
		{
			printf("Bingo");
			break;
		}
		
			
	}	
	
	return 0;
}

