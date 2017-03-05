#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int j=-1;
	int C,R;
	const int x=9,y=8;  //size of the maze(no. of rows and columns, respectively)
	static int a[1000];//stores the moves in sequence
	int m[x][y]={{1,0,0,1,1,1,1,1},{1,1,0,0,0,0,0,1},{0,0,0,1,0,1,1,1},{1,1,0,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,0,0,0,1,1,1},{1,1,0,1,0,1,1,1},{1,1,0,1,0,0,1,1},{1,1,1,1,1,0,1,1}};//could be as big as the memory allows

int mazeRec(int r,int c,int i)

	{
		if(i!=0)
		a[++j]=i;

		if(c==C && r==R)
		return 1;

		if(r!=0 && i!=3)
		{
			if(m[r-1][c]!=1)
			{
				if(mazeRec(r-1,c,1)==1)
				return 1;
			}

		}


		if(c!=(y-1) && i!=4)

		{
			if(m[r][c+1]!=1)
			{
				if(mazeRec(r,c+1,2)==1)
				return 1;
			}

		}


		if(r!=(x-1) && i!=1)
		{
			if(m[r+1][c]!=1)
			{
				if(mazeRec(r+1,c,3)==1)
				return 1;
			}

		}

		if(c!=0 && i!=2)
		{
			if(m[r][c-1]!=1)
			{
				if(mazeRec(r,c-1,4)==1)
				return 1;
			}
		}

		a[j--]=0;
		return 0;

	}


	int main()
	{
		int r,c,k=0,l;
		printf("Enter the starting indices(row, then column)\n");//indices start from 0. Eg. 0,0 for the first cell

		scanf("%d",&r);
		scanf("%d",&c);

		printf("Enter the ending indices(row, then column)\n");

		scanf("%d",&R);
		scanf("%d",&C);

		l=mazeRec(r,c,0);

		if(l==0)
		{
			printf("There is no way out, Sucker!\n");
			exit(0);
		}


		while(a[k]!=0)
		{
			if(a[k]==1)
			printf("Top\n");

			if(a[k]==2)
			printf("Right\n");

			if(a[k]==3)
			printf("Down\n");

			if(a[k]==4)
			printf("Left\n");

			k++;
		}

	}




