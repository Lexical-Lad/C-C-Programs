 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
 #include <string.h>

const int  max=1000;

char a[max]; int top=-1;


void push(char data);
char pop();

void push(char data)
{
	a[++top]= data;
}
char pop()
{
	return a[top--];
}


int main()
{
	char s[1000];
	int i,k=0;
	printf("Enter a string \n");

	gets(s);

	k=strlen(s);
	i=0;


	while(i<k)
	{
		push(s[i]);
		i++;
	}


	for(i=0;i<k;i++)
	{
		if(s[i]!=pop())
		{
			printf("Not palindrome\n");
			exit(0);
		}

	}

	printf("Palindrome\n");

}






