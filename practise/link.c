#include<stdio.h>
#include<stdlib.h>
struct node *addatbeg(struct node *start);
struct node *addatend(struct node *start);
void display(struct node *start);

struct node 
{
int info;
struct node *link;
};
struct node *start=NULL;
int main()
{
int n,i;
printf("enter the node:");
scanf("%d",&n);
start=addatbeg(start);
for(i=2;i<=n;i++)
{
start=addatend(start);
}
display(start);
}
struct node *addatbeg(struct node *start)
{
struct node *temp;
int data;
printf("enter the data:");
 scanf("%d",&data);
  

temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;
return start;
}
struct node *addatend(struct node *start)
{
int data;
struct node *p,*temp;
p=start;
while(p->link!=NULL)
{
p=p->link;
}
printf("enter the data:");
scanf("%d",&data);
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
temp->link=NULL;
p->link=temp;
return start;
}
void display(struct node *start)
{
struct node *p=start;
while(p!=NULL)
{
printf("%d ",p->info);
p=p->link;
}
}
