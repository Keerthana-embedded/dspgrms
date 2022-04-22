#include<stdio.h>
int top1=-1,top2=-1;
int q1[10];
int q2[10];
void enq(int);
int deq();
int main()
{
	int c,n;
	while(1)
	{
		printf("enter choice 1:enq..2:deq..3:print\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter element to be pushed\n");
			       scanf("%d",&n);
			       enq(n);
			       break;
			case 2:if((top1==-1)&&(top2==-1))
				       printf("queue is empty\n");
			       else
				       printf("data poped=%d\n",deq());
			       break;

		}
	}
}
void enq(int e)
{
	q1[++top1]=e;
}
int deq()
{
	if(top2==-1)
	{
		while((top1)!=-1)
		{
		q2[++top2]=q1[top1--];
		
	        }
	}
			return q2[top2--];


}
