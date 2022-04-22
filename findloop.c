#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node * data(struct node *);
struct node * findloop(struct node *);
void print(struct node *);
int main()
{
	struct node *head=NULL;
	int c;
	while(1)
	{
		printf("enter choice\n1:add..2:print..3:findloop\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:head=data(head);
			       break;
			case 2:print(head);
			       break;
			case 3:head=findloop(head);
			         break;
		}
	}
}
struct node * data(struct node *ptr)
{
	struct node *new,*temp;
	new=malloc(sizeof(struct node));
	if(new==NULL)
		printf("node not created\n");
	else
	{
		printf("enter data\n");
		scanf("%d",&new->data);
		if(ptr==NULL)
		{
			ptr=new;
			new->link=ptr;
		}
		else
		{
			struct node * temp;
			temp=ptr;
			while((temp->link)!=ptr)
				temp=temp->link;
			temp->link=new;
			new->link=ptr;

		}
	}
	return ptr;
}
struct node * findloop(struct node *ptr)
{
struct node *p=ptr,*q=ptr;
int cnt=0;
while(p&&q&&q->link)
{

	p=p->link;
        q=q->link->link;
	cnt++;
       if(p==q)
       {
	       printf("loop found\n");
        return ptr;
       }
}
}
	void print(struct node *ptr)
	{
		struct node *temp=ptr;
		do
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}while(temp!=ptr);
	}
