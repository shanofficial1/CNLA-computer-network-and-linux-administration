#include <stdio.h>
#include <string.h>
int main()
{
	char str[100],rev[100];
	scanf("%s",str);

	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		rev[i]=str[len-i-1];
	}
	rev[len]='\0';
	if(strcmp(rev,str)==0)
	{
		printf("Pallidrome");
	}
	else
	{
		printf("Not pallidrome");
	}
}
