#include <stdio.h>
#include <string.h>

int main()

{
 	char in[1000]="(",post[1000],stack[1000],temp[999],t;
	int k=0;
	int st=-1,p=-1;
	printf("Enter the infix expression : \n");

	gets(temp);

	strcat(in,temp);
	strcat(in,")");

	while(in[k]!='\0')
	{
		t=in[k++];

		if(t=='(')
			stack[++st]=t;

		else if(t=='-' || t=='+')
			{
				while(stack[st]!='(')
					post[++p]=stack[st--];

				stack[++st]=t;
			}
		else if(t=='^')
			{
				if(stack[st-1]!=t)
					stack[++st]=t;
				else
					post[++p]=t;
			}

		else if(t=='/' || t=='*' || t=='%')
			{
				while(stack[st]!='(' && stack[st]!='+' && stack[st]!='-')
						post[++p]=stack[st--];

				stack[++st]=t;

			}

		else if(t==')')
			{
				while(stack[st]!='(')
					post[++p]=stack[st--];

				st--;

			}

		else
			post[++p]=t;

	}


	post[++p]='\0';

	printf("The corresponding postfix expression is : \n");
	puts(post);

}





