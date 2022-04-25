#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
	struct student * addlast(struct student *);
	void display(struct student * );
       struct student * reverse(struct student *ptr);

int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addlast..2:display..3:reverse\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addlast(head);
		       break;
		case 2:display(head);
		       break;
		case 3:head=reverse(head);
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
void display(struct student *ptr)
{
while(ptr!=NULL)
{
	printf("%d\n",ptr->data);
ptr=ptr->link;
}
}

struct student * reverse(struct student *ptr)
{
struct student *p,*q;
if(ptr==NULL)
	return p;
p=ptr;
q=ptr->link;
if(q==NULL)
	return p;
q=reverse(q);
p->link->link=p;
p->link=NULL;
return q;
}
