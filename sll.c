#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node **base;
void insert_at_begin(struct node **,int);
void insert_at_end(struct node **,int);
/*void traverse();
void delete_from_begin();
void delete_from_end();
int count = 0;*/
 int main()
{
    int ch,data;
struct node *start=NULL;
    base=&start;
  jump:  printf("1.insertion at begin 2.insertion at end 3.traverse 4.delete from begin 5.delete from end 6.exit");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        printf("enter the data");
        scanf("%d",&data);
        insert_at_begin(&start,data);
        goto jump;

        case 2:
        printf("enter the data");
        scanf("%d",&data);
        insert_at_end(&start,data);
        goto jump;
 /*       case 3:
        traverse();
        goto jump;
        case 4:
        delete_from_begin();
        goto jump;
        case 5:
        delete_from_end();
        goto jump;
        case 6:
        exit(0);
*/        default:printf("enter the number between 1-6");
        goto jump;
        
    }

    return 0;
}
void insert_at_begin(struct node **base,int data)
{
	struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp;		
	}
}
void insert_at_end(struct node **base,int data)
{
	struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		while(temp->next !=NULL)
			temp=temp->next;
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=NULL;
		temp->next=n;		
	}
}
void deletion_begin(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		*base=temp->next;
		 free(temp);
		 temp=*base;		
	}
}
void deletion_end(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		while(temp->next !=NULL)
			temp=temp->next;
		 free(temp);		
	}
}
void display(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		while (temp->next!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);		
	}

}
void copy(struct node *q,struct node *s)
{
	if(q!=NULL)
	{
		*s=(struct node *)malloc(sizeof(struct node))
		*s->data=q->data;
		*s->next=NULL;
		copy(q->link,&((*s)->next));
	}
}
int compare(struct node *list1,struct node *list2)
{
	static int flag;
	if((list1==NULL)&&(list2==NULL))
	{
		flag =1;		
	}
	else
	{
		if((list1==NULL)||(list2==NULL))
		flag=0;
		if(list1->data != list2->data)
		flag=0;
		else
			compare(list1->next,list2->next);
	}
	return flag;
}*/


