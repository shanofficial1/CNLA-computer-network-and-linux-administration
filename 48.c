#include <stdio.h>

int main()
{
        int n;
        printf("Enter the limit: ");
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
	{
		int flag=1;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("%d\t",i);
		}
	}
}





