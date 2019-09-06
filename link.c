#include<stdio.h>
#include<stdlib.h>
struct linklist{
	int data;
	struct linklist *next;
	};
void add(struct linklist **q,int val)
{
struct linklist *temp=*q,*r;
		
		
	if(temp==NULL)
	{	temp=malloc(sizeof(struct linklist*));
		temp->data=val;
		temp->next=NULL;
		*q=temp;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		r=malloc(sizeof(struct linklist*));
		r->data=val;
		r->next=NULL;
		temp->next=r;

	}	
}
void display(struct linklist **q)
{
	struct linklist *temp=*q;
	if(temp==NULL)
	printf("\nemplty list \n");
	else{
	while(temp != NULL)
	{
	printf("%d   ",temp->data);
	temp=temp->next;
	}}
}
void del(struct linklist **q)
{
	struct linklist *temp1,*temp=*q;
	if(temp==NULL)
	printf("no elements\n");
	else
	{
	while(temp->next->next != NULL)
	temp=temp->next;
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	}
}
void delval(struct linklist **q,int key)
{
	struct linklist *temp1,*temp=*q;
	while((temp->data==key)&&(temp->next!=NULL))
	temp=temp->next;
	if(temp->next==NULL)
	printf("\nKey is not found");
	else
	{
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
	}
}
void delpos(struct linklist **q,int pos)
{
	struct linklist *temp1,*temp=*q;
	int i;
	for(i=0;i<=pos-3;i++)
	temp=temp->next;
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
}
void destroy(struct linklist **q)
{
	struct linklist *temp1,*temp=*q;
	while(temp!=NULL)
	{
	temp1=temp;
	temp=temp->next;
	//printf("\n%d",temp1->data);
	free(temp1);
	}
	*q=temp;
}



void main()
{
int n,m;
struct node *p=NULL;
struct node **q=&p;
int choice;
while(1)
{
printf("enter any choice\n");
printf("1.add\t 2.add_at_beg\t3.add_at_end\t4.display\t 5:destroy\t6:ins_after_data\t 7:delete_at_beg\t8:delete_at_end\t9:delete_at_pos\t10.count\t11.exit\t\n");
scanf("%d",&choice);

switch(choice)
{

case 1:add(&p,n);
	break;
case 2:printf("enter number to add_at_beg\n");
	scanf("%d",&n);
	//add_at_beg(&p,n);
	break;
case 3:printf("enter number to add_at_end\n");
	scanf("%d",&n);
	//add_at_end(&p,n);
	break;
case 4:display(&p);
	break;
case 5:destroy(&p);
	break;
case 6:printf("enter number to add after data\n");
	scanf("%d%d",&n,&m);
	//ins_after_data(&p,n,m);
	break;
case 7://delete_at_beg(&p);
	break;
case 8://delete_at_end(&p);
	break;
case 9:printf("enter the position to delete\n");
	scanf("%d",&n);
	//delete_at_pos(&p,n);
	break;
case 10://count(&p);
	break;
case 11:exit(1);
}
}
}




