#include <stdio.h>

int main()
{
	int alpha=0,digit=0,special=0;
	char str[100];
	printf("Enter the string : ");
	fgets(str,sizeof(str),stdin);
	int i=0;
	while( str[i]!='\0')
	{
		if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
		{
			alpha++;
		}
		else if(str[i]>='0' && str[i]<='9')
		{
			digit++;
		}
		else if(str[i]!=' ' && str[i]!='\n')
		{
			special++;
		}
	i++;
	}
	printf(" Alphabets :%d\n",alpha);
	printf("Digits :%d\n",digit);
	printf("Special :%d\n",special);
}

