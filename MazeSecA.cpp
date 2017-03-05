
#include<stdio.h>

struct position
{
int row,col;
} offset[4];



int n,m;

int main()
{
int i,op,lastop,r,c;
struct position here,pre;

int path[35][2]; // to save path
int opsave[35]; // to save direction infomation
int Top=-1;
n=7;
m=4;

offset[0].row=0;  offset[0].col=1; //right
offset[1].row=1;  offset[1].col=0;  //down
offset[2].row=0;  offset[2].col=-1; //left
offset[3].row=-1;  offset[3].col=0; //up


//read maze[][] //read maze (matrix from user)

int maze[][8]=  {{1,1,1,1,1,1,1,1},
				{1,0,0,1,1,1,1,1},
				{1,1,0,0,0,0,1,1},
				{1,1,0,1,1,1,1,1},
				{1,1,0,1,1,1,1,1},
				{1,1,0,1,1,1,1,1},
				{1,1,0,0,0,1,1,1},
				{1,1,1,1,0,1,1,1},
				{1,1,1,1,1,1,1,1}};



here.row=1; //entry point
here.col=1;

maze[1][1]=1;

op=0;
lastop=3;

while(here.row!=n|| here.col!=m)
{

printf("\n%d %d %d\n",here.row,here.col,op);
 while(op<=lastop)
  {
   r=here.row+offset[op].row;
   c=here.col+offset[op].col;

	if(maze[r][c]==0)
	break;
	op=op+1;
	}
  if(op<=lastop)
	{
	Top=Top+1;
	path[Top][0]=here.row;
	path[Top][1]=here.col;
	here.row=r;
	here.col=c;
	maze[r][c]=1;
	opsave[Top]=op;
	op=0;
	//j=j+1;
	}
	else
	{
	pre.row=path[Top][0];
	pre.col=path[Top][1];
	op=opsave[Top]+1;
	Top=Top-1;
	here.row=pre.row;
	here.col=pre.col;
//	j=j-1;
	}
printf("\n%d %d %d\n",here.row,here.col,op);





	  }
	if(here.row==n && here.col==m)
	printf("\n successful maze traversal");
return 0;

}
