#include <stdio.h>

int main()
{
	int a=0,b=1,c,limit;
	printf("Enter the limit");
	scanf("%d",&limit);
	for(int i=1;i<=limit;i++)
	{
		printf("%d \t",a);
		c=a+b;
		a=b;
		b=c;
	}
	return 0;
}
