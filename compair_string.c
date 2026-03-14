#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int  flag=0;
	char str1[100],str2[100];
	printf("Enter the string 1 : ");
	scanf("%s",str1);
	printf("Enter the string 2 : ");
        scanf("%s",str2);
	if(strlen(str1)==strlen(str2))
	{
		for(int i=0;str1[i]!='\0';i++)
		{
			if(toupper(str1[i])!=toupper(str2[i]))
			{
				flag=1;
			}
		}
	}
	else
	{
		flag=1;
	}
	if(flag==0)
	{
		printf("Strings are equal\n");
	}
	else
	{
		 printf("Not equal string\n");
	}
}


