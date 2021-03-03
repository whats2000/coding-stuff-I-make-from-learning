//自選溫度轉換
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int type;
	float C;
	float F;
	while(1)
	{//"功能"無法輸入 
		printf("請輸入選項\n1.攝氏轉華氏 2.華氏轉攝氏 3.關閉執行\n");
		scanf("%d",&type);
		switch(type)
		{ 
			case 1:	printf("請輸入一個攝氏溫度\n");
					scanf("%f",&C);
					F = 9.0/5*C+32;
					printf("%.2f轉成華氏為%.2f",C,F);
					system("Pause");
					break;
			case 2:	printf("請輸入一個華氏溫度\n");
					scanf("%f",&F);
					C = (F-32)*5/9;
					printf("%.2f轉成攝氏為%.2f",F,C);
					system("Pause");
					break;
			case 3: return 0;
					break;
			default:printf("What's are you saying");									
		}
	}	
} 
