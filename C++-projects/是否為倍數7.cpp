//判斷是否為倍數七 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	printf("請輸入一個整數\n");
	scanf("%d",&a);
	if(a%7==0)
	{
		printf("是7的倍數");
	}
	else
	{
		printf("不是7的倍數");
	}
	system("Pause");
} 
