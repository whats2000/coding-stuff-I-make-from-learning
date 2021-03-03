/* ifだ计单锣传 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b;
	printf("叫块だ计\n");
	scanf("%d",&a);
	if(a<=100 && a>=0)
	{
		if(a>=80)
		{
			printf("单材A\n");
			b=4;
		}
		else if(a>=70)
		{
			printf("单材B\n");
			b=3;	
		}
		else if(a>=60)
		{				
			printf("单材C\n");
			b=2;
		}		
		else if(a>=50)
		{				
			printf("单材D\n");
			b=1;
		}
		else
		{
			printf("单材E\n");
			b=0;
		}		
		system("Pause");
		return 0;
    }
    else
    {
    	printf("稱び 簎\n"); 
    	system("Pause");
	}
}

