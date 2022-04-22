#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
	struct student * addfirst(struct student *);
	void rprint(struct student * );
	void display(struct student *);
int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addfirst..2:display..3:rprint\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addfirst(head);
		       break;
		case 2:display(head);
		       break;
		case 3:rprint(head);
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

void rprint(struct student *ptr)
{
if((ptr->link)!=NULL)
rprint(ptr->link);
	printf("%d\n",ptr->data);
}
void display(struct student *ptr)
{
while(ptr)
{
	printf("%d\n",ptr->data);
ptr=ptr->link;
}

}
