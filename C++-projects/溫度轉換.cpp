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
		if(type==1)
		{
			printf("請輸入一個攝氏溫度\n");
			scanf("%f",&C);
			F = 5/9*C+32;
			printf("%.2f轉成華氏為%.2f",C,F);
			system("Pause");
		}
		else if(type==2)
		{
			printf("請輸入一個華氏溫度\n");
			scanf("%f",&F);
			C = (F-32)*9/5;
			printf("%.2f轉成攝氏為%.2f",F,C);
			system("Pause");
		}
		else if(type==3)
		{
			return 0;
		}
	}
} 
