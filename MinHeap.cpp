#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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


void deletion()
{
	int item=tree[0];
	int last=tree[n];

	n--;

	int ptr=0,left=1,right=2;

	while(right<=n)
	{
		if(last<tree[left]&&last<tree[right])
		{
			tree[ptr]=last;
			return;
		}

		if(tree[left]<tree[right])
		{
			tree[ptr]=tree[left];
			ptr=left;
		}
		else
		{
			tree[ptr]=tree[right];
			ptr=rightl
		}

		left=2*ptr+1;
		right=2*ptr+2;
	}

	if(left==n && last>tree[left])
	{

		tree[ptr]=tree[left];
		tree[left]=last;
	}
	else
	tree[ptr]=last;
}


void display()
{
	int k;
	for(k=0;k<=n;k++)
		printf("%d \t",tree[k]);

	}


