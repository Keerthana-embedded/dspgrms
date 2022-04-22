#include<stdio.h>
#include<stdlib.h>
struct data
{
	char c;
	struct data *link;
};
struct data * addlast(struct data * ptr);
int findchar(struct data * ptr);
void display(struct data *ptr);
int main()
{
	struct data *head=NULL;
	int c;
	while(1)
	{
		printf("enter choice 1:addlast 2:findchar 3:display\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:head=addlast(head);
			       break;
			case 2:findchar(head);
			       break;
			case 3:display(head);
			       break;
		}
	}
}
struct data * addlast(struct data *ptr)
{
	struct data *temp=ptr,*new=NULL;
	new=malloc(sizeof(struct data));
	if(new==NULL)
		printf("node not created\n");
	else
	{
		printf("enter charector\n");
		__fpurge(stdin);
		scanf("%c",&new->c);
		if(ptr==NULL)
			ptr=new;
		else
		{
			struct data *temp=ptr;
			while((temp->link)!=NULL)
			{
				temp=temp->link;
			}
			temp->link=new;
			return ptr;
		}
	}
}
int findchar(struct data * ptr)
{
char ch;
struct data *temp=ptr;
printf("enter charector to find\n");
__fpurge(stdin);
scanf("%c",&ch);
while(ptr!=NULL)
{
	if((ptr->c)==ch)
	{		
		printf("found\n");
		return 0;
	}
	ptr=ptr->link;
}
	printf("not found\n");
	return 0;

}
void display(struct data *ptr)
{
while(ptr!=NULL)
{
	printf("%c\n",ptr->c);
ptr=ptr->link;
}
}
