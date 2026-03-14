
// Count vowel and consants

#include <stdio.h>
#include <string.h>

int main()
{
	int c=0,v=0,l=0;
	char str[100];
	fgets(str,100,stdin);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
	if(
		(str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')
	)
	{
		if(str[i]=='a' || str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' || str[i]=='A' || str[i]=='E' ||str[i]=='I' ||str[i]=='O' || str[i]=='U')
		{
			v++;
		}
		else
		{
			c++;
		}
	}
}
	printf("consants : %d\n",c);
	printf("vowels : %d\n",v);
}
