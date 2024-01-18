#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};

struct node *head=NULL;

void insert()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node\n");
scanf("%d",&temp->data);
temp->link=NULL;
if(head==NULL)
	head=temp;

else
{	
	struct node *p;
        p=head;
 	while((p->link)!=NULL)
	{
         p=p->link;
	}
	p->link=temp;
}
}

void atbegin()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
	printf("list is empty\n");
else
{
temp->link=head;
head=temp;
}
}


void display()
{
struct node *temp;
temp=head;

if(temp==NULL)
	printf("list is empty\n");
else
{
while(temp!=NULL)
{	
	printf("%d-->",temp->data);
        temp=temp->link;
}
}
}





void findaloop()
{
struct node *p=head,*q=head;

while(p&&q&&q->link)
{
	p=p->link;
	q=p->link->link;
if(p==q)
{
	printf("loop found\n");
return p;
}
else 
printf("No loop found\n");


}







}
int main()
{

	int ch;
	while(1)
	{
         printf("1.Insert\n 2.insert at begin \n 3.Dsiplay\n 4.findaloop\n");
	 scanf("%d",&ch);
         switch(ch)
	 {
          case 1:insert();
		break;
       	 case 2:atbegin();
                break;
	 case 3:display();
                break;
       	case 4:findaloop();
  		break;
	}

	}
return 0;

}
