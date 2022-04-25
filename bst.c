#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int d;
	struct bst *r;
	struct bst *l;
};
void inorder(struct bst *root)
{
	if(root)
	{	
		inorder(root->l);
	printf("%d",root->d);
	inorder(root->r);
	}
}
int main()
{
	int n;
	struct bst *root=NULL,*p,*q;
	printf("enter array elements size\n");
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=(struct bst *)malloc(sizeof(struct bst));

	p->d=a[0];
	p->r=NULL;
	p->l=NULL;
	root=p;
	for(i=1;i<n;i++)
	{
		p=(struct bst *)malloc(sizeof(struct bst));
                p->d=a[i];
		p->l=NULL;
		p->r=NULL;
		q=root;
		while(1)
		{
			if((p->d)<=(q->d))
			{
				if((q->l)==NULL)
				{
					q->l=p;
					break;
				}
				else
					q=q->l;
			}
			else
			{
				if((q->r)==NULL)
				{
					q->r=p;
					break;
				}
				else
					q=q->r;
			}
		}
	}
	inorder(root);
}
