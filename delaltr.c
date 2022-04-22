#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
	struct student * addlast(struct student *);
	struct student *delete(struct student *);
	void display(struct student * );
int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addlast..2:display..3:delete\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addlast(head);
		       break;
		case 2:display(head);
		       break;
		case 3:head=delete(head);
		       break;
	}
}
}
struct student * addlast(struct student *ptr)
{
	struct student *newnode=NULL;
	newnode=malloc(sizeof(struct student));
	if(newnode==NULL)
		printf("node not created");
	else
	{
		printf("enter element\n");
  		scanf("%d",&newnode->data);
		if(ptr==NULL)
		{
			ptr=newnode;
		}
		else
		{
			struct student *temp=NULL;
			temp=ptr;
			while((temp->link)!=NULL)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}

	}
	return ptr;
}
struct student * delete(struct student *ptr)
{
	struct student *temp,*q;
	temp=ptr;
	q=ptr;
	while((temp)!=NULL)
	{
        q=temp->link->link;
	temp->link=q;
	temp=temp->link;
          free(q);
	}
}
void display(struct student *ptr)
{
while(ptr!=NULL)
{
	printf("%d\n",ptr->data);
ptr=ptr->link;
}
}
