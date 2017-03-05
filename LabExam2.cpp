#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char data;
	struct node *next,*prev;
};

struct node *start,*end,*ptr;
int count=0;

void insert(char val)
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;

	if(start==NULL)
	{
		start=end=ptr;
		ptr->next=NULL;
		ptr->prev=NULL;
	}
	else
	{
		ptr->next=NULL;
		ptr->prev=end;
		end->next=ptr;
		end=ptr;
	}

}


void sort()
{
	char a[1000];
	ptr=start;
	int i=0,j;
	char temp;

	while(ptr!=NULL)
	{
		a[i]=ptr->data;
		i++;
		ptr=ptr->next;
	}

	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(((int)a[i])<((int)a[j]))
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

	start=NULL;

	for(i=0;i<count;i++)
	insert(a[i]);
}


void display()
{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%c",ptr->data);
			ptr=ptr->next;
		}

		printf("\n");
}

int main()
{

	printf("Enter a string \n");

	char s[1000];

	gets(s);

	int i=0;

	while(s[i]!='\0')
	{
		insert(s[i]);count++;
		i++;
	}

	sort();
	display();


}


