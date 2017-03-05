#include <stdio.h>
#include <stddef.h>

int x=5,y=7;
	int m[5][7]={{1,1,1,1,1,1,1},{0,0,0,0,1,1,1},{1,1,0,0,1,1,1},{1,1,0,0,0,1,1},{1,1,1,1,0,1,1}};

void f(int r,int c)
	{

		m[r][c]=2;

		if((r-1)>=0)
		{
			if(m[r-1][c]==0)
			{
				f(r-1,c);

			}

		}

		if((c+1)<=(y-1))
		{
			if(m[r][c+1]==0)
			{
				f(r,c+1);

			}
		}

		if((r+1)<=(x-1))
		{
			if(m[r+1][c]==0)
			{
				f(r+1,c);

			}
		}

		if((c-1)>=0)
		{
			if(m[r][c-1]==0)
			{
				f(r,c-1);

			}

		}

		return ;

	}

int main()
{

			f(1,0);

			for(int i=0;i<5;i++)
			{
				for(int j=0;j<7;j++)
				printf("%d",m[i][j]);

			printf("\n");

			}

}
