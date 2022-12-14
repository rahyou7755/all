#include<stdio.h>
#include<stdlib.h>
struct adi
{
	int info;
	struct adi *link;
};
//struct adi *start=NULL;

struct adi *create(struct adi *start);
void display(struct adi *start);
struct adi *addatbeg(struct adi *start,int data);
struct adi *addatend(struct adi *start,int data);
struct adi *addafter(struct adi *start,int data,int item);
struct adi *addbefore(struct adi *start,int data,int item);
struct adi *addatposition(struct adi *start,int data,int position);
struct adi *delete(struct adi *start,int data);
struct adi *reverse(struct adi *start);
int c=1;
int main()
{
	struct adi *start=NULL;
	int a,data,item,position;
	while(c)
	{
		printf("1)create linked list\n 2)display list\n 3)add at beginning\n 4)add at end\n 5)add after a node\n 6)add before a node\n 7)add at position\n8)delete\n9)reverse\n10)quit");
		printf("\nenter the option\n");
		scanf("%d",&a);
		
		switch(a)
		{
			case 1:
				start=create(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("enter the element to be inserted\n");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			case 4: printf("enter the element to be inserted\n");
                                scanf("%d",&data);
                               start =addatend(start,data);
                                break;
			case 5: printf("enter the element to be inserted\n");
                                scanf("%d",&data);
                                printf("enter the element after which you want to insert:");
				scanf("%d",&item);
				start=addafter(start,data,item);
				break;
			case 6:printf("enter the element to be inserted\n");
                                scanf("%d",&data);
                                printf("enter the element before  which you want to insert:");
                                scanf("%d",&item);
                                start=addbefore(start,data,item);
                                break;
			case 7:printf("enter the element to be inserted\n");
                                scanf("%d",&data);
                                printf("enter position  which you want to insert:");
                                scanf("%d",&position);
                                start=addatposition(start,data,position);
				break;
			case 8:printf("enter the element to be deleted\n");
                                scanf("%d",&data);
			        start=delete(start,data);
                                break;
			case 9:
				start=reverse(start);
				break;
			case 10:
				printf("thankyou\n");
				c=0;
				break;
			default:
				printf("wrong option selected");
		}
	}
}
void display(struct adi *start)
{
	struct adi *p;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	p=start;
	printf("list is........\n");
	while(p != NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}
struct adi *addatbeg(struct adi *start,int data)
{
	struct adi *temp;
	temp=(struct adi *)malloc(sizeof(struct adi));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct adi *addatend(struct adi *start,int data)
{
        struct adi *temp,*p;
        temp=(struct adi *)malloc(sizeof(struct adi));
        temp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=temp;
        temp->link=NULL;
        //start=temp;
        return start;
}
struct adi *addafter(struct adi *start,int data,int item)
{
	struct adi *temp,*p;
 p=start;
 while(p!=NULL)
 {
	 if(p->info == item)
	 {
		  temp=(struct adi *)malloc(sizeof(struct adi));
        temp->info=data;
	 temp->link=p->link;
	 p->link=temp;
	   return start;
	 }
	   p=p->link;
 }
 printf("%d not found\n ",item);
 return start;
}
struct adi *addbefore(struct adi *start,int data,int item)
{
	struct adi *temp,*p;

        if(start==NULL)
        {
                printf("list is empty\n");
                return start;
	}
	//if data to be inserted  before first node
	if(item==start->info)
	{
		   temp=(struct adi *)malloc(sizeof(struct adi));
        temp->info=data;
         temp->link=p->link;
         p->link=temp;
           return start;
	}
	p=p->link;

printf("%d not present in the list\n",item);
return start;
}
struct adi *addatposition(struct adi *start,int data,int position)
{
	struct adi *temp,*p;
	int i;
	p=start;
	for(i=1;i<position-1 && p!=NULL;i++)
		p=p->link;
	if(p==NULL)
		printf("there are less %d elements\n",position);
	else
	{
		     temp=(struct adi *)malloc(sizeof(struct adi));
        temp->info=data;
	if(position==1)
	{
		temp->link=start;
		start=temp;
	}
	else
	{
		temp->link=p->link;
		p->link=temp;
	}
	}
}
struct adi *create(struct adi *start)
{
	int i,n,data;
	printf("enter the number of nodes:");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("enter the element to be inserted:");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(i=2;i<=n;i++)
	{
		printf("enter the element to be inserted:");
		scanf("%d",&data);
		start=addatend(start,data);
		 //printf(" element is %d\n",start->info);

	}
	
	return start;
}
struct adi *delete(struct adi *start,int data)
{
	struct adi *temp,*p;
	  if(start==NULL)
        {
                printf("list is empty\n");
                return start;
        }
	  if(start->info==data)//deletion of first node
	  {
		  temp=start;
		  start=start->link;
		  free(temp);
		  return start;
	  }
	  p=start;
	  while(p->link!=NULL)
	  {
		  if(p->link->info == data)
		  {
			  temp=p->link;
			  p->link=temp->link;
			  free(temp);
			  return start;
		  }
		  p=p->link;
	  }
	  printf("element %d not found\n",data);
	  return start;
}
struct adi *reverse(struct adi *start)
{
	struct adi *prev,*ptr,*next;
	prev=NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}






































