#include<stdio.h>
#include<stdlib.h>
struct student
{
	int data;
	struct student *link;
};
int cnt=0;
struct student * addlast(struct student *);
struct student *delete(struct student *);
struct student *delfromlast(struct student *);
void display(struct student * );
int main()
{
	int c;
	struct student *head=NULL;
	while(1)
	{
		printf("enter choice\n1:addlast..2:display..3:delete..4:delfromlast\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:head=addlast(head);
			       break;
			case 2:display(head);
			       break;
			case 3:head=delete(head);
			       break;
			case 4:head=delfromlast(head);
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
		newnode->link=NULL;
		cnt++;
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
	int i,loc;
	struct student *temp;
	printf("enter which node to delete\n");
	scanf("%d",&loc);
	if(cnt==1)
	{
		temp=ptr;
		ptr=temp->link;
		temp->link=NULL;
		free(temp);
	}	
	else
	{
		i=1;
		temp=ptr;
		while(i<loc-1)
		{
			temp=temp->link;
			i++;
		}
		struct student *q;
		q=temp->link;
		temp->link=q->link;
		q->link=NULL;
		free(q);
	}
	return ptr;
}

struct student * delfromlast(struct student *ptr)
{
	int loc;
	struct student *temp;
	printf("enter which node to delete from last\n");
	scanf("%d",&loc);
                if(loc==1)
		{
			cnt=0;
                   free(ptr);
		   ptr=NULL;
		   printf("list is empty\n");
		   return ptr;
		}
	        else if(loc==2)
		{
		cnt--;
                temp=ptr;
		ptr=ptr->link;
                free(temp);
                temp=NULL;
                return ptr;
		}	
		else
		{	
		temp=ptr;
		while(cnt>loc+1)
		{
			temp=temp->link;
			cnt--;
		}
		struct student *q;
		q=temp->link;
		temp->link=q->link;
		free(q);
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
	printf("cnt=%d\n",cnt);
}
