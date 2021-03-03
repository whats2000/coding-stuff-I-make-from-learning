/* if分數範圍 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b;
	printf("請輸入分數\n");
	scanf("%d",&a);
	if(a<=100 && a>=0)
	{
		if(a>=60)
		{
			printf("及格\n");
			if(a==100)
			{
				printf("滿分\n");
			}
		}
		else if(a>=40)
		{
			printf("可以補考\n");	
		}
		else if(a<40)
		{				
			printf("死當\n");
		}		
		system("Pause");
		return 0;
    }
    else
    {
    	printf("作弊\n"); 
    	system("Pause");
	}
}

