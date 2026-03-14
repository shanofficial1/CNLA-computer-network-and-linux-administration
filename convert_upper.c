#include <stdio.h>
#include <ctype.h>
int main()
{
	char str[100]="shan";
	int i=0;
	while(str[i]!='\0')
	{
		str[i]=toupper(str[i]);
		i++;
	}
	printf("%s",str);
}
