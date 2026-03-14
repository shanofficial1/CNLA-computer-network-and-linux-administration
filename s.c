#include <stdio.h>


int main()
{
	char str1[50];
	int count=0;
	printf("Enter the string");
	fgets(str1,50,stdin);
	int i=0;
	while(str1[i] != '\0')
	{
		if(str1[i] != ' ' && str1[i] != '\n')
		{
			count++;
		}
		i++;
	}
	printf("count of characters is %d",count);
}
