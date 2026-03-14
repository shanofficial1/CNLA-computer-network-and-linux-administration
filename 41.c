#include <stdio.h>

int main()
{
	int n;
	printf("Enter the limit: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("%d : %c\n",i,'A'+i);
	}
}
