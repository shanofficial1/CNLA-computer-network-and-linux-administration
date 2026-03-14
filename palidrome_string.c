#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int flag=0;
	printf("Enter the string : ");
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i < len/2;i++)
	{
		if(str[i]!=str[len-1-i])
		{
			flag=1;
		}
	}

	if(flag==0)
	{
		printf("PALIDROME \n");
	}
	else
	{
		printf("NOT PALIDROME \n");
	}
}
