#include <stdio.h>
#include <string.h>


int main()
{
	char str[100];
	int len,words;
	printf("Enter the sentence : ");
	fgets(str,100,stdin);
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]== ' ')
		{
			words++;
		}
	}
	printf("Number of words : %d \n",words+1);
}
