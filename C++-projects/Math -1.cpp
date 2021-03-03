/* 溫度轉換運算 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b;
	printf("請輸入被除數整數a\n");
	scanf("%d",&a);
	printf("請輸入除數整數b\n");
	scanf("%d",&b);
	printf("%d除以%d商為%d餘數%d",a,b,a/b,a%b);
	system("Pause");
	return 0;
}

