#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
	struct student * addlast(struct student *);
       struct student * findloop(struct student *);
	void display(struct student * );
       struct student * rotate(struct student *ptr);

int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addlast..2:display..3:exit..4:findloop..5:rotate\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:head=addlast(head);
		       break;
		case 2:display(head);
		       break;
		case 4:head=findloop(head);
		       break;
		case 5:head=rotate(head);
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
struct student * findloop(struct student *ptr)
{
struct student *p=ptr,*q=ptr;
while(p && q && q->link)
{
p=p->link;
q=q->link->link;
if(p==q)
{
	printf("loop found\n");
	return p;
}
printf("no loop\n");
return NULL;}
}
void display(struct student *ptr)
{
while(ptr!=NULL)
{
	printf("%d\n",ptr->data);
ptr=ptr->link;
}
}

struct student * rotate(struct student *ptr)
{
int n;
printf("enter upto which node u want to rotate\n");
scanf("%d",&n);
struct student *temp,*newhead,*p=ptr;
while(n>1)
{
p=p->link;
n--;
}
newhead=p->link;
p->link=NULL;
temp=newhead;
while((temp->link)!=NULL)
{
temp=temp->link;
}
temp->link=ptr;
return newhead;
}
