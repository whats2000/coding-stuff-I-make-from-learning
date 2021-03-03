#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int t=0;
	int output=0;
	printf("叫块俱计\n");
	scanf("%d",&n);
	if(n<=2)
	{
		if(n==2)
		t=n;
		else
		t=n-1;			
	}
	else
	{
		for(t=2;t<n;t++)
		{
			if(n%t==0)
			{
				break;
			}
		}
	}
	if(t==n)
	printf("%d借计\n",n);
	else if(t>0)
	printf("%d计\n",n);
	else
	printf("%dぃ琌借计 ぃ琌计\n",n);
	system("Pause");
	return 0;
}

