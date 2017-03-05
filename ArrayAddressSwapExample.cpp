#include <stdio.h>

int main()
{

	int arr1[]={1,2};
	int arr2[]={3,4};

	int *q1=arr1;
	int *q2=arr2;

	int *temp=q1;
	q1=q2;
	q2=q1;



	printf("%d\t%d\n",q1[0],q1[1]);

	printf("%d \n",*q1);

	printf("%d \n",q1);

}
