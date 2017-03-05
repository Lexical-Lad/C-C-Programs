#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct node
	{
		int data;

		struct node *next;
		struct node *prev;

	};

	 node *start=NULL;
	 node *end=NULL;

	void create();
	void display();
	void deletion();
	void insert();

int main()

{
	int choice;

	while(1)
		{
			printf("Enter your choice: \n 1.Create a new linked list( or append several nodes) \n 2.Display the existing linked list \n 3.Insert an element \n 4.Delete an element \n 5.Exit \n");

			scanf("%d",&choice);

			switch(choice)
			{
				case 1: create();
						break;

				case 2: display();
						break;

				case 3: insert();
						break;

				case 4: deletion();
						break;

				case 5: exit(0);

				default : printf("Unknown choice. Pick again\n");

			}

		}

}

void create()

	{

		char c;
		int n;

		struct node *new_node;

		new_node= (struct node*)malloc(sizeof(struct node));

		printf("Enter the data(number) for the  new node\n");

		scanf("%d",&n);
		new_node->data=n;

		if(start==NULL)
			{
				start=end=new_node;
				start->next=NULL;
				start->prev=NULL;
			}


		else
			{
				end->next=new_node;
				new_node->prev=end;
				end=new_node;
				end->next=NULL;
			}

		printf("Do you want to add another node?(y/n)\n");
		scanf(" %c",&c);



		while(c=='y')
		{
			new_node= (struct node*)malloc(sizeof(struct node));

			printf("Enter the data(number) for the  new node\n");

			scanf("%d",&n);

			new_node->data=n;
			new_node->next=NULL;
			end->next=new_node;
			new_node->prev=end;
			end=end->next;

			printf("Do you want to add another node?(y/n)\n");
			scanf(" %c",&c);


		}
	}


void insert()

	{
		if(start==NULL)
		{
			printf("The list is empty. Use the 'create a new list' option to get started\n");
			return;
		}

		struct node *new_node=(struct node*)malloc(sizeof(struct node));
		struct node *ptr=start;
		char c;int a;
		printf("Enter the data(number) for the new node\n");
		scanf("%d",&new_node->data);

		printf("Where do you want to insert the new node? \n a.Beginning \n b.End \n c.Before a certain node \n d.After a certain node \n Enter your choice : \n");

		scanf(" %c",&c);

		switch(c)

		{
			case 'a' :	new_node->next=start;
						new_node->prev=NULL;
						start->prev=new_node;
						start=new_node;
						printf("Node Inserted");
						break;


			case 'b' :	end->next=new_node;
						new_node->prev=end;
						end=new_node;
						end->next=NULL;
						printf("Node Inserted");
						break;

			case 'c' : 	printf("Enter the number before which you want to enter the new node\n");
						scanf("%d",&a);


						if(start->data==a)
						{
							new_node->next=start;
							new_node->prev=NULL;
							start->prev=new_node;
							start=new_node;
							printf("Node Inserted");
							return;
						}

						while(ptr->next!=NULL)
							{
								if(ptr->next->data==a)
								{
									new_node->next=ptr->next;
									new_node->prev=ptr;
									ptr->next->prev=new_node;
									ptr->next=new_node;
									printf("Node Inserted");
									return;
								}

								ptr=ptr->next;

							}

						printf("The entered number does not exist in the stored list. Please try again.\n");
						break;

			case 'd' : 	printf("Enter the number after which you want to enter the new node\n");
						scanf("%d",&a);

						if(end->data==a)
						{
							new_node->next=end->next;
							new_node->prev=end;
							end->next=new_node;
							end=new_node;
							printf("Node Inserted");
							return;
						}

						do
						{
							if(ptr->data==a)
							{
								new_node->next=ptr->next;
								new_node->prev=ptr;
								ptr->next->prev=new_node;
								ptr->next=new_node;
								printf("Node Inserted");
								return;
							}

							ptr=ptr->next;
						}while(ptr!=NULL);

						printf("The entered number does not exist in the stored list. Please try again.\n");

						break;
			default : printf("Wrong input. Please try again\n");

			}

	}


void deletion()
{

	if(start==NULL)
		{
			printf("The list is empty. Use the 'create a new list' option to get started\n");
			return;
		}
	char c;
	int n;
	struct node *temp,*b;
	printf("Which node do you want to Delete? \n a.First node \n b.Last Node \n c.Before a certain node \n d. After a certain node \n e.A node containing a certain value \n");
	scanf(" %c",&c);

	switch(c)
	{
		case 'a' : 	temp=start;
					start=start->next;
					start->prev=NULL;
					free(temp);
					printf("Node Deleted\n");
					break;

		case 'b' : 	temp=end;
					end=end->prev;
					end->next=NULL;
					free(temp);
					printf("Node Deleted\n");
					break;

		case 'c' : 	if(start->next==NULL)
					{
						printf("The list contains only one node. These is no 'before' or 'after', per say. Please Try Again\n");
						return;
					}

					printf("Enter the number, the node before which is to be deleted :\n)");
					scanf("%d",&n);

					temp=start->next;
					b=start;



					if(b->data==n)
					{
						printf("The number entered resides in the first node. There is no node before the first node. Please try again.\n");
						return;
					}


					if(temp->data==n)
					{
						start=start->next;
						start->prev=NULL;
						free(b);
						printf("Node Deleted\n");
						return;
					}

					do
					{
						if(temp->next->data==n)
						{
							b->next=temp->next;
							temp->next->prev=b;
							free(temp);
							printf("Node Deleted\n");
							return;
						}

						temp=temp->next;
						b=b->next;

					}while(temp->next!=NULL);

					printf("The number entered is not present in the existing linked list \n");

					break;

		case 'd' : 	if(start->next==NULL)
					{
						printf("The list contains only one node. These is no 'before' or 'after', per say. Please Try Again \n");
						return;
					}

					printf("Enter the number, the node after which is to be deleted :\n");
					scanf("%d",&n);


					if(end->data==n)
					{
						printf("The number entered resides in the last node. There is no node after the same. Please try again \n");
						return;
					}

					temp=start;

					if(end->prev->data==n)
					{
						b=end;
						end->prev->next=NULL;
						end=b->prev;
						free(b);
						printf("Node Deleted");
						return;
					}



					while(temp->next!=end)
					{
						if(temp->data==n)
						{
							b=temp->next;
							temp->next=b->next;
							b->next->prev=temp;
							free(b);
							printf("Node Deleted\n");
							return;
						}
						temp=temp->next;

					}

					printf("The number entered is not present in the existing list. Please try again \n");

					break;

		case 'e' :  printf("Enter the number, the node containing which is to be deleted :\n)");
					scanf("%d",&n);


					if(start->data==n)
					{
						temp=start;
						start=start->next;
						start->prev=NULL;
						free(temp);
						printf("Node Deleted \n");
						return;
					}

					temp=start->next;
					b=start;

					while(temp!=NULL)
					{
						if(temp->data==n)
						{
							b->next=temp->next;
							temp->next->prev=b;
							free(temp);
							printf("Node Deleted");
							return;
						}

						temp=temp->next;
						b=b->next;

					}

					printf("The number entered is not present in the existing list. Please try again \n");

					break;

		default :	printf("Invalid Option. Please try again");

	}

}

void display()

{
		struct node *temp;

		if(start==NULL)
		{
			printf("The list is empty. Use the 'create a new list' option to get started\n");
			return;
		}

		temp=start;

		printf("The Current List :\n");

		while(temp!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}

}

