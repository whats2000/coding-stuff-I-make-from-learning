#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int score=0;
	int sum=0;
	int p=0;
	int t=0;
	int max=0;
	int min=0;
	printf("請輸入人數\n");
	scanf("%d",&p);
	for(t=1;t<=p;t++)
	{
		printf("請輸入第%d的成績:",t);
		scanf("%d",&score);
		if(score>=0 && score<=100)
		{
			sum = sum +score;
			if(min>score||t==1)
			{
				min=score;
			}
			else if(max<score||t==1)
			{
				max=score;
			}
		}
		else
		{
		printf("error\n");
		t=t-1;
		}
	}
	printf("============================================\n");
	printf("最高分為%d\n",max);
	printf("最低分為%d\n",min);
	printf("總成績為%d\n",sum);
	printf("平均為%.2f\n",(float)sum/p);
	printf("全距為%d\n",max-min);
	system("Pause");
	return 0;
}

