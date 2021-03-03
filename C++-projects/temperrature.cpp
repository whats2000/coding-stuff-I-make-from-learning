/* 放锣传笲衡 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	float C,F;
	printf("块地ん放\n");
	scanf("%f",&F);
	C = (F-32)*5/9;
	printf("%f锣传尼ん%f\n",F,C);
	system("Pause");
	printf("块尼ん放\n");
	scanf("%f",&C);
	F = C*9/5+32;
	printf("%f锣传地ん%f\n",C,F);
	system("Pause");
	return 0;
}

