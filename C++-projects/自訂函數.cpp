#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int pow1(int x,int y);
int pow1(int x,int y)
{
	int i;
	int z=1;
	for(i=0;i<y;i++)
	z=z*x;
	return z;
}
int fac(int x);
int fac(int x)
{
	int i;
	int z=1;
	for (i=2;i<=x;i++)
	z=z*i;
	return z;
}
int main()
{	
	int x;
	int y;
	int z;
	printf("¿é¤Jx\n");
	scanf("%d",&x);
	printf("¿é¤Jy\n");
	scanf("%d",&y);	
	z=pow1(x,y);
	printf("x^y=%d\n",z);
	
	printf("¿é¤Jx\n");
	scanf("%d",&x);
	z=fac(x);
	printf("x!=%d\n",z);
	
	system("Pause");
	return 0;
}


