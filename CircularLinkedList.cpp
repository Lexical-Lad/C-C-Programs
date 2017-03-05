#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
	{
		int data;

		struct node *next;

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
				start->next=start;
			}


		else
			{
				end->next=new_node;
				end=new_node;
				end->next=start;
			}

		printf("Do you want to add another node?(y/n)\n");
		scanf(" %c",&c);



		while(c=='y')
		{
			new_node= (struct node*)malloc(sizeof(struct node));

			printf("Enter the data(number) for the  new node\n");

			scanf("%d",&n);

			new_node->data=n;
			new_node->next=start;
			end->next=new_node;

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
						start=new_node;
						end->next=start;
						printf("Node Inserted \n");
						break;


			case 'b' :	end->next=new_node;
						end=new_node;
						end->next=start;
						printf("Node Inserted \n");
						break;

			case 'c' : 	printf("Enter the number before which you want to enter the new node\n");
						scanf("%d",&a);


						if(start->data==a)
						{
							new_node->next=start;
							start=new_node;
							end->next=start;
							printf("Node Inserted \n");
							return;
						}

						while(ptr->next!=start)
							{
								if(ptr->next->data==a)
								{
									new_node->next=ptr->next;
									ptr->next=new_node;
									printf("Node Inserted \n");
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
							end->next=new_node;
							end=new_node;
							end->next=start;
							printf("Node Inserted \n");
							return;
						}


						do
						{
							if(ptr->data==a)
							{
								new_node->next=ptr->next;
								ptr->next=new_node;
								printf("Node Inserted \n");
								return;
							}

							ptr=ptr->next;
						}while(ptr!=end);

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
					free(temp);
					end->next=start;
					printf("Node Deleted\n");
					break;

		case 'b' : 	temp=start;
					while(temp->next!=end)
					temp=temp->next;

					temp->next=end->next;
					free(end);
					end=temp;
					printf("Node Deleted\n");
					break;

		case 'c' : 	if(start->next==start)
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
						while(b->next!=end)
						b=b->next;

						b->next=end->next;
						free(end);
						end=b;
						printf("Node Deleted \n");
						return;
					}


					if(temp->data==n)
					{
						start=start->next;
						end->next=start;
						free(b);
						printf("Node Deleted\n");
						return;
					}

					do
					{
						if(temp->next->data==n)
						{
							b->next=temp->next;
							free(temp);
							printf("Node Deleted\n");
							return;
						}

						temp=temp->next;
						b=b->next;

					}while(temp->next!=start);

					printf("The number entered is not present in the existing linked list \n");

					break;

		case 'd' : 	if(start->next==start)
					{
						printf("The list contains only one node. These is no 'before' or 'after', per say. Please Try Again \n");
						return;
					}

					printf("Enter the number, the node after which is to be deleted :\n");
					scanf("%d",&n);


					if(end->data==n)
					{
						end->next=start->next;
						free(start);
						start=end->next;
						printf("Node Deleted\n");
						return;

					}

					temp=start;

					while(temp->next!=start)
					{
						if(temp->data==n)
						{
							b=temp->next;
							temp->next=b->next;
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


					if(start->next==start)
					{
						start=end=NULL;
						return;
					}


					if(start->data==n)
					{
						temp=start;
						start=start->next;
						end->next=start;
						free(temp);
						printf("Node Deleted \n");
						return;
					}

					temp=start->next;
					b=start;

					while(temp!=start)
					{
						if(temp->data==n)
						{
							b->next=temp->next;
							free(temp);
							printf("Node Deleted \n");
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

		printf("The Current List :\n");
		printf("%d \n",start->data);

		temp=start->next;

		while(temp!=start)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}

}
