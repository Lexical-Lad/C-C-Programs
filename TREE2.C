#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int top=0,size=100;
typedef struct node
{
char data;
struct node *lchild,*rchild;
}node;
node *t,*root=NULL,*stack[100];
void push(node *el)
{
stack[0]=NULL;
if(top>=size-1)
printf("overflow");
else
{
top++;
stack[top]=el;
}
}
node * pop()
{
node *s;
if(top==0)
printf("underflow");
else
{
s=stack[top];
top--;
return s;
}
}
void btcreate(node *parent)
{
int i,l;
if(parent!=NULL)
{
printf("enter the left node 1/0");
scanf(" %d",&i);
if(i==1)
{
t=(node *)malloc(sizeof(node));
scanf(" %c",&t->data);
parent->lchild=t;
btcreate(t);
}
else
{
parent->lchild=NULL;
}
printf("enter the right child 1/0");
scanf(" %d",&i);
if(i==1)
{
t=(node *)malloc(sizeof(node));

scanf(" %c",&t->data);
parent->rchild=t;
btcreate(t);
}
else
{
parent->rchild=NULL;
}
}
}
void preorder(node *parent)
{
while(parent!=NULL)
{
printf(" %c",parent->data);
if(parent->rchild!=NULL)
push(parent->rchild);
if(parent->lchild!=NULL)
parent=parent->lchild;
else
parent=pop();
}
}
/*void inorder(node *parent)
{
while(parent!=NULL)
{
if(parent->rchild!=NULL)
push(parent->rchild);
else if(parent->lchild!=NULL)
{
push(parent);
parent=parent->lchild;
}
else
{
printf(" %c",parent);
parent=pop();
}
if(parent!=NULL)
{
printf(" %c",parent);
parent=pop();
}
}
} */
int main()
{
printf("enter the root");
root=(node *)malloc(sizeof(node));

scanf(" %c",&root->data);
btcreate(root);
preorder(root);
}
