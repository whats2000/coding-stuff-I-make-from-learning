/* if */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int P;
	printf("請輸入金額\n");
	scanf("%d",&P);
	if(P>2000)
		{P=P*7/10;
		printf("超過2000 打7折\n");
		}
	printf("需付%d\n",P);
}

