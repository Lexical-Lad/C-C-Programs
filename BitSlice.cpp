#include <stdio.h>


int main()
{
	int a1,a2,b1,b2,c1,c2,carry;
	int num1,num2;
	printf("Enter 2 numbers : \n");

	scanf("%d",&num1);
	scanf("%d",&num2);

	a1=num1;
	a1=a1&255;

	a2=num1;
	a2=a2>>8;

	b1=num2;
	b1=b1&255;

	b2=num2;
	b2=b2>>8;

	c1=a1+b1;
	c1=c1&255;

	if(c1<a1 || c1<b1)
	carry=1;
	else
	carry=0;

	c2=carry+a2+b2;

	printf("%d \n",c1);
	printf("%d",c2);

}

