#include <stdio.h>

int main()
{
	int num,rev=0,copy,temp;
	printf("Enter the number");
	scanf("%d",&num);
	copy=num;
	while(num>0)
	{
		temp=num%10;
		rev=rev*10+temp;
		num/=10;
	}
	if(rev==copy)
	{
		printf("%d is palidrome \n",copy);
	}
	else
	{
		printf("%d is not palidrome \n",copy);
	}
}
