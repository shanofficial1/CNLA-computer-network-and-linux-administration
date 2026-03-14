#include <stdio.h>

int main()
{
	int num,count=0;
	printf("Enter the number");
	scanf("%d",&num);
	if(num!=1)
	{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			printf("%d is  not a prime",num);
			count++;
			break;
		}
	}
	if(count==0)
	{
		printf("%d is prime number",num);
	}
	}
	else
	{
		printf("1 is not prime ");
	}

	return 0;
}
