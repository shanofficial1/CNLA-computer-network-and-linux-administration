#include <stdio.h>

int main()
{
	int num,count=0;
	printf("Enter the number");
	scanf("%d",&num);
	while(num>0)
	{
		count++;
		num/=10;
	}
	printf("number of digit : %d \n",count);
}
