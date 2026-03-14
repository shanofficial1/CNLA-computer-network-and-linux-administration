#include <stdio.h>
#include <string.h>


int main()
{
	char str1[100],str2[100];
	int  len;
	printf("Enter the string 1: ");
	scanf("%s",str1);
	printf("Enter the string 2: ");
        scanf("%s",str2);
	len=strlen(str1);
	str1[len]=' ';
	for(int i=1;i<=strlen(str2);i++)
	{
		str1[len+i]=str2[i-1];
	}
	printf("string : %s \n",str1);
}
