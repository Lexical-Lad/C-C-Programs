#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[1000];

	gets(c);
	char a[]="~";
	strcat(c,"~");
	puts(c);
	strcat(a,c);
	puts(a);

}
