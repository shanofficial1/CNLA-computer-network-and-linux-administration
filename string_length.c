#include <stdio.h>

int main()
{
	char str[100];
	int length=0;
	printf("Enter the string : ");
	scanf("%s",str);
	int i=0;
	while(str[i] != '\0')
	{
		length++;
		i++;
	}
	printf("length of string is %d \n",length);
}
