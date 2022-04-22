#include<stdio.h>
#include<stdlib.h>
struct student1
{
	int data;
	struct student *link;
};
struct student1
{
	int data;
	struct student *link;
};
	struct student * addlast1(struct student *);
	struct student * addlast2(struct student *);
	void display1(struct student * );
	void display2(struct student * );
       struct student * sort(struct student *ptr);

int main()
{
	int c;
	struct student *head1=NULL;
	struct student *head2=NULL;
	while(1)
	{
		printf("enter choice\n1:addlast..2:display..3:sort\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addlast1(head);
		       break;

		case 2:head=addlast2(head);
		       break;
		case 2:display(head);
		       break;
		case 3:head=merge(head);
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

struct student * sort(struct student *ptr)
{
	struct student *t1=ptr,*t2=ptr->link;
	int temp;
	for(t1=ptr;t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if((t1->data)<(t2->data))
                        {
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
	}
	return ptr;
}

