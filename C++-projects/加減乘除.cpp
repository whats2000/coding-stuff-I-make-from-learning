#include<stdio.h>
#include<stdlib.h>
int main()
{
	char type;
	float a;
	float b;
	while(type!='E' && type!='e')
	{
		printf("輸入想要的運算模式\nE鍵結束\n");
		scanf("%c",&type);
		if(type=='E' || type=='e')
		{
			return 0;
		}
		printf("輸入變數a\n");
		scanf("%f",&a);
		printf("輸入變數b\n");
		scanf("%f",&b);
		switch(type)
		{
			case '+':
				printf(" a+b =%f",a+b);
				system("Pause");
				break;
			case '-':
				printf(" a-b =%f",a-b);
				system("Pause");
				break;
			case '*':
				printf(" a*b =%f",a*b);
				system("Pause");
				break;
			case '/':
				printf(" a/b =%f",a/b);
				system("Pause");
				break;	
		}
	}	
}
