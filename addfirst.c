#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
	struct student * addfirst(struct student *);
        struct student * destroy(struct student *);
	void display(struct student * );
int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addfirst..2:display..3:destroy\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addfirst(head);
		       break;
		case 2:display(head);
		       break;
		case 3:head=destroy(head);
		       break;
	}
}
}
struct student * addfirst(struct student *ptr)
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
			struct student *temp;
			newnode->link=ptr;
			ptr=newnode;
		}

	}
	return ptr;
}

void display(struct student *ptr)
{
	if(ptr==NULL)
		printf("list is empty\n");
	else
	{
while((ptr))
{
	printf("%d\n",ptr->data);
ptr=ptr->link;
}
}
}
struct student * destroy(struct student *ptr)
{
	struct student *temp=ptr;
while(ptr)
{
ptr=ptr->link;
free(temp);
temp=ptr;
}
return ptr;
}
