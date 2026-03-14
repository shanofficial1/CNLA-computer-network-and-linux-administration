#include <stdio.h>

int main()
{
	int n;
	printf("Enter the limit: ");
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("Sum of numbers is : %d",sum/n);
	float rsum=0.0;
	float r;
	for(int i=1;i<=n;i++)
	{
		r=1.0/i;
		rsum=rsum+r;
	}
	printf("Recipocal sum; %f",rsum/n);
	return 0;
}
