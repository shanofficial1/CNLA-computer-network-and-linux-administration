#include <stdio.h>

int main()
{
	int length=0;
	char str[100];
	scanf("%s",str);
	while(str[length]!='\0')
	{
		length++;
	}
	printf("Length : %d\n",length);
}
