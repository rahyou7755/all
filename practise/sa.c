#include<stdio.h>
#define SIZE 10
int stack[SIZE],top=-1;
void push(int a);
void display();
void pop();
int main()
{
	int choice,c=1,a;
	while(c)
	{
		printf("\n1)push\n2)pop\n3)display\n4)exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:printf("enter the element to push:\n");
			       scanf("%d",&a);
			       push(a);
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:c=0;
			       break;
			default:printf("enter the correct input");
		}
	}
}
void push(int a)
{
       if(top==SIZE-1)
       {
       printf("stack over");
       }
       else
       {
	top++;
	stack[top]=a;
	printf("element push successfully");
       }
}
void pop()
{
        if(top==-1)
        {
        printf("empty stack:");
        }
       else
       {
	printf("%d is pop successfully\n",stack[top]);
	top--;
       }
}
void display()
{
       
	int i;
        if(top==-1)
        {
        printf("empty list");
        }
        else
        {
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
}


