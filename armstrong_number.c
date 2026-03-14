#include <stdio.h>

int main()
{
	int sum=0,num,temp,copy;
	printf("Enter the number");
	scanf("%d",&num);
	copy=num;
	while(num>0)
	{
		temp=num%10;
		sum=sum + (temp*temp*temp);
		num/=10;
	}
	printf("sum = %d\n",sum);
	if(sum==copy)
	{
		printf("armstrong number\n");
	}
	else
	{
		printf("not armstrong number\n");
	}
}
