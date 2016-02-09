#include<stdio.h>

#define SIZE 5


int queue[SIZE], rear=-1, front=-1, item;


void insert()
{
	if((front==0 && rear==SIZE-1) || (front==rear+1))
		printf("\nQueue is full.");
	else
	{
		printf("\nEnter ITEM: ");
		scanf("%d", &item);

		if(rear == -1)
		{
			rear = 0;
			front = 0;
		}
		else if(rear == SIZE-1)
			rear = 0;
		else
			rear++;

		queue[rear] = item;
		printf("\nItem inserted: %d\n", item);
	}
}

void del()
{
	if(front == -1)
		printf("\nQueue is empty.\n");
	else
	{
		item = queue[front];

		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if(front == SIZE-1)
			front = 0;
		else
			front++;

		printf("\nITEM deld: %d", item);
	}
}

void display()
{
	int i;

	if((front == -1) || (front==rear+1))
		printf("\nQueue is empty.\n");
	else
	{
		printf("\n");

		for(i=front; i<=rear; i++)
			printf("\t%d",queue[i]);
	}
} 

int main()
{
	int ch;
	do
	{
		printf("\n1.\tInsert\n2.\tdel\n3.\tDisplay\n4.\tExit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;

			default:
			printf("\nInvalid choice. Pleasr try again...\n");
		}
	} while(1);
	return 0;
}
