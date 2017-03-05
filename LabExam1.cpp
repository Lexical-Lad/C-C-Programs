//MIN HEAP

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int tree[100],n=-1;

void insert(int item)
{
	int par;
	n++;
	int ptr=n;

	while(ptr>0)
	{
		par=(ptr-1)/2;

		if(item>tree[par])
		{
			tree[ptr]=item;
			return;
		}
		else
		{
			tree[ptr]=tree[par];
			ptr=par;
		}
	}
	tree[ptr]=item;
}

void display()
{
	int k;
	for(k=0;k<=n;k++)
		printf("%d \t",tree[k]);

}

int height(int root)
{
	if(tree[root]==-1)
	return 0;

	int lh,rh;

	lh=height(root*2+1);
	rh=height(root*2+2);

	if(lh>rh)
	return ++lh;
	else
	return ++rh;

}



int main()
{
	int i=0;
	int choice,item;
	for(;i<100;i++)
	tree[i]=-1;

	while(1)
	{
		printf("Enter your choice : \n 1. Insert element \n 2.Display the existing tree \n 3.Find the height \n 4.Exit \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("Enter the element to be inserted \n");
					scanf("%d",&item);
					insert(item);
					printf("Item inserted \n");
					break;

			case 2: display();
					break;

			case 3: printf("Height : %d ",height(0));
					break;

			case 4: exit(0);

			default: printf("Invalid choice. Pick again!!! \n");

		}

	}

}





