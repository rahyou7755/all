#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
struct node *push();
void pop();
void display();
struct node *top=NULL;
int main()
{
int choice,c;
while(c)
{
printf("1)push\n2)pop\n3)display\n4)exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
       top=push();
       break;
case 2:pop();
       break;
case 3:display();
       break;
case 4:c=0;
       break;
default:printf("wrong input");
}
}
}
struct node *push()
{
 struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
printf("stack overflow");
else
{
int data;
printf("enter the data");
scanf("%d",&data);
temp->info=data;
temp->link=top;
top=temp;
return top;
}
}
void pop()
{
struct node *temp;
temp=top;
printf("%d element deleted:",temp->info);
top=top->link;
}

void display()
{
struct node *temp=top;
while(temp!=NULL)
{
printf("%d",temp->info);
temp=temp->link;
}
}
