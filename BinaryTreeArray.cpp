#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 100
static char t[max];
int level, s;

void create(int parent);
void print();
void printArray();
void preorder(int root);
void inorder(int root);
void postorder(int root);
void insert();
void deletion(int in);
int search(char val);


int main()
{
	int choice;
	printf("Creation Time!!! \n");
	char val;
	do
	{
		printf("\nEnter the number of levels \n");
		scanf("%d",&level);
		s=pow(2,(level+1))-1;
	}while(s>max);

	printf("\nEnter the value for the root node \n");
	fflush(stdin);
	scanf(" %c",&t[0]);
	create(0);

	printf("Tree Created, Mothafucka!!! \n");

	while(1)
	{
		printf("Pick an option, rasta! \n 1.Good ol' print \n 2.Print array, as is \n 3. Preorder print \n 4.Inorder print \n 5.Postorder print \n 6.Insert an element \n 7.Delete an element \n 8.Search for an element \n 9.Exit \n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:	print();
				break;
		case 2:	printArray();
				break;
		case 3: preorder(0);
				break;
		case 4:	inorder(0);
				break;
		case 5:	postorder(0);
				break;
		case 6:	insert();
				break;
		case 7:	printf("Enter the element to be deleted \n");
				fflush(stdin);
				scanf(" %c",&val);
				if(search(val)==-1)
				printf("Element not found");
				else
				deletion(search(val));
				break;
		case 8:	printf("Enter the value to be searched \n");
				fflush(stdin);
				scanf(" %c",&val);
				printf("The element is found at the index %d \n",search(val));
				break;
		case 9: exit(0);
		default: printf("Wrong choice, biatch! Pick again!!!");
	}
}

}

void create(int parent)
{
	if(parent<s)  //NOT less than or equal to!!!
	{
		if(t[parent]!='#')
		{
			  printf("\n Enter the left child for %c : \n",t[parent]);
			  fflush(stdin);
			  scanf(" %c",&t[2*parent +1]);

			  create(2*parent +1);

			  printf(" \nEnter the right child for %c : \n",t[parent]);
			  fflush(stdin);
			  scanf(" %c",&t[2*parent +2]);

			  create(2*parent +2);

		  }

		  else
		  {
			  t[2*parent+1]='#';
			  create(2*parent +1);

			  t[2*parent +2]='#';
			  create(2*parent +2);
		  }

	  }

  }

  void print()
  {
	  int i=0;

	  printf("(\t Node \t,\t Index \t ) \n");

	  for(;i<s;i++)
	  	if(t[i]!='#')
		  printf("(\t %c \t,\t %d \t ) \n",t[i],i);

	}

	void printArray()
	{
		int i=0;

		printf("Index \t Value \n");

		for(;i<s;i++)
			printf("%d \t %c \n",i,t[i]);

	}


void preorder(int root)
{
	if(t[root]=='#')
	return;

	printf("%c",t[root]);
	printf("\t");
	preorder(2*root+1);
	preorder(2*root+2);

}

void inorder(int root)
{
	if(t[root]=='#')
		return;


	inorder(2*root+1);
	printf("%c",t[root]);
	printf("\t");
	inorder(2*root+2);
}

void postorder(int root)
{
	if(t[root]=='#')
	return;

	postorder(2*root+1);
	postorder(2*root+2);
	printf("%c \t",t[root]);

}

void insert()
{
	int i=0;
	for(;i<s;i++)
	{
		if(t[i]=='#')
		break;
	}
	if(i==s)
	{
		printf("No more elements can be inserted! Max no. of nodes for the specified no. of levels reached! \n");
		return;
	}

	printf("Enter the value to be inserted \n");
	fflush(stdin);
	scanf(" %c",&t[i]);

	printf("\n Value inserted");

}

int search(char val)
{
	int i=0;

	for(;i<s;i++)
	{
		if(t[i]==val)
		break;
	}
	if(i==s)
	return -1;

	return i;
}

void deletion(int in)
{
	int i=s-1;
	if(t[2*in+1]=='#' && t[2*in+2]=='#')
	{
		t[in]='#';
		printf("Deleted!");
		return;
	}
	for(;i>in;i--)
	{
		if(t[i]!='#')
		break;
	}

	t[in]=t[i];
	t[i]='#';

	printf("Deleted!");
}







