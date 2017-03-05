#include <stdio.h>

int main()
{
	int i=0,j;


	for(j=0;j<10;j++)
	{
		switch(i)
		{
			case 0: i=0;continue;

			case 1: i++; break;
		}
		i+=2;

	}

	printf("%d",i);
}
