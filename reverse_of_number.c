#include <stdio.h>

int main()
{
	int num,temp,reverse=0;
	printf("Enter the number :");
	scanf("%d",&num);
	while(num>0)
	{
		temp=num%10;
		reverse=reverse *10+temp;
		num/=10;
	}
	printf("reverse is :%d",reverse);
	return 0;
}
