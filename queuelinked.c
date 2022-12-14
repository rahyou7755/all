#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL,*newNode,*temp;
void enqueue()
{
    newNode = (struct node *) malloc(sizeof(struct node));
    int element;
    printf("enter the element to be inserted\n");
    scanf("%d",&element);
    newNode->data = element;
    newNode->next = NULL;

    //if it is the first node
    if(front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        //add newnode in rear->next
        rear->next = newNode;

        //make the new node as the rear node
        rear = newNode;
    }
}
void dequeue()
{
    //used to free the first node after dequeue
    struct node *temp;

    if(front == NULL)
         printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {//take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;
	temp->next=NULL;
       //free the first node
       free(temp);
    }

}
void printList()
{
    struct node *temp = front;
    if(front == NULL)
    {
	    printf("queue is empty\n");
    }
    else
    {
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    }
}
int main()
{
	int a,c=1;
	//printf("\n1) enqueue the list\n2)dequeue the list\n3)print the list\n4)quit\n");
	while(c)
	{
		 printf("1) enqueue the list\n2)dequeue the list\n3)print the list\n4)quit\n");

		 printf("\nenter the option:\n");
        scanf("%d",&a);

		switch(a)
		{
			case 1:
				enqueue();
				break;
			case 2:dequeue();
			       break;
			case 3:
			       printList();
			       break;
			case 4:c=0;
			       break;
			default:
			       printf("wrong input\n");
		}
	}
}




/*
    enqueue();
    enqueue();
    enqueue();
    printf("Queue :");
    printList();
    dequeue();
    printf("After dequeue the new Queue :");
    printList();
    dequeue();
    printf("After dequeue the new Queue :");
    printList();

    return 0;
}*/



