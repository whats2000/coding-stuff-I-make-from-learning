/* if */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b;
	printf("請輸入數字\n");
	scanf("%d",&a);
	if(a%2==0)
	{
			printf("偶數");
	}else{
			printf("奇數");
	}
	system("Pause");
	return 0;
}

