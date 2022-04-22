#include<stdio.h>
#define M 5
int s1[M],s2[M];
int top1=-1,top2=-1;
void push(int);
void sort();
int pop();
int main()
{
	int n,c;
	while(1)
	{
		printf("enter choice 1:push 2:sorted stack 3:pop\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter element\n");
			       scanf("%d",&c);
			       push(c);
			       break;
			case 2:printf("sorted data is\n");
			       sort();
			       break;
			case 3:printf("%d..",pop());
			       break;

		}
	}
}
void push(int e)
{
	s1[++top1]=e;
}
void sort()
{
	int temp;
	while((top2)!=M-1)
	{
		temp=s1[top1--];
		if((top2)==-1)
			s2[++top2]=temp;
		else
		{
			while((temp<s2[top2])&&((top2)!=-1))
			{
				s1[++top1]=s2[top2--];
			}
			s2[++top2]=temp;
		}
	}
}
int pop()
{
return s2[top2--];
}
