#include <stdio.h>

int main()
{
	int vowel=0;
	char str[100];
	printf("Enter the string :");
	scanf("%s",str);
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' )
		{
			vowel++;
		}
		i++;
	}
	printf("Number of vowel is %d\n",vowel);
}
