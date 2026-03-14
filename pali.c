
	#include <stdio.h>
#include <string.h>

int main(){

	char *text;
	printf("ENter the number");
	scanf("%s",text);
	if(strcmp(reverse(text),text)==0){
	printf("%s is plaidrome",text);
}
else{
printf("Not palidrome");
}
return 0;
}
