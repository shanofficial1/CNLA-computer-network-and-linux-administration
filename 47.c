#include <stdio.h>

int main()
{
        int n,temp;
        printf("Enter the limit: ");
        scanf("%d",&n);
	int a=0,b=1;
        for(int i=1;i<=n;i++)
	{
		printf("%d\t",a);
		temp=a+b;
		a=b;
		b=temp;
	}
	printf("\n--------------\n");
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		printf("%d\t",sum);
		sum=sum+3;
	}
}




