#include <stdio.h>

int main()
{
        int n;
        printf("Enter the limit: ");
        scanf("%d",&n);
	int pro=1;
	for(int i=1;i<=n;i++)
	{
		pro=pro*i;
	}
	printf("Product: %d",pro);
	return 0;
}

