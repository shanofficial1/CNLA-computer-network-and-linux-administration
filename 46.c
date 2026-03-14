#include <stdio.h>

int main()
{
        int n,temp,cn;
        printf("Enter the limit: ");
        scanf("%d",&n);
	cn=n;
	int sum=0;
	while(n>0)
	{
		temp=n%10;
		sum=sum+temp;
		n=n/10;
	}
	printf("\n%d\n",sum);

	int rev=0;
	while(cn>0)
	{
		temp=cn%10;
		rev=rev*10+temp;
		cn=cn/10;
	}
	printf("%d",rev);
}
