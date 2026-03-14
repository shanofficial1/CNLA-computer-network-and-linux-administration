#include <stdio.h>

int main(){

	int num,sum=0,temp;
	printf("enter the number :");
	scanf("%d",&num);
	while(num>0){
		temp=num%10;
		sum+=temp;
		num/=10;
	}
	printf("sum of digit %d is %d",num,sum);
	return 0;
}

