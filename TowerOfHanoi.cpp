 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>


 void hanoi(int n,char start,char aux,char end)
 {
	 if(n==1)
	 {
		 printf("%c -> %c \n",start,end);
		 return;
	 }

	 hanoi(n-1,start,end,aux);

	 printf("%c -> %c \n",start,end);

	 hanoi(n-1,aux,start,end);

 }

 int main()

 {
	 int n;

	 printf("Enter the number of rings");
	 scanf("%d",&n);

	 hanoi(n,'A','B','C');

 }

