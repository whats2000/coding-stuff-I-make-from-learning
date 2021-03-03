/* scanf輸入運算 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b;
	printf("輸入變數整數a\n");
	scanf("%d",&a);
	printf("輸入變數整數b\n");
	scanf("%d",&b);	
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
	printf("%d/%d=%.3f\n",a,b,(float)a/b);
	system("Pause");
	return 0;
}

