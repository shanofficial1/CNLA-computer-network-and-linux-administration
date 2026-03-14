#include <stdio.h>
#include <string.h>

int main()
{
	char str[100],rev[100];
	int i;
	printf("Enter the string : ");
	scanf("%s",str);
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
	
		rev[i]=str[len-1-i];
	}
	rev[len]='\0';
	printf("string reverse is %s\n",rev);
}
