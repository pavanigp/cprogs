#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

//struct node **base;
void insert_at_begin(struct node **,int);
void insert_at_end(struct node **,int);
void display(struct node **);
void delete_from_begin(struct node **);
void delete_from_end(struct node **);
void insert_at_position(struct node **, int , int);
void delete_at_position(struct node **, int);
void distroy(struct node **);
 int main()
{
    int ch,data,pos;
struct node *start=NULL;
  //  base=&start;
  jump:  printf("1.insertion at begin 2.insertion at end 3.display 4.delete from begin 5.delete from end 6.insert_at_position 7.delete_at_position 8.distroy 9.exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_begin(&start,data);
        goto jump;
        case 2:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_end(&start,data);
        goto jump; 
	case 3:
	display(&start);
	goto jump;
        case 4:
        delete_from_begin(&start);
        goto jump;
        case 5:
        delete_from_end(&start);
        goto jump;
	case 6:
	printf("enter the data and position\n");
        scanf("%d %d",&data,&pos);	
        insert_at_position(&start,pos,data);
        goto jump;
	case 7:
	printf("enter the position\n");
        scanf("%d",&pos);	
        delete_at_position(&start,pos);
        goto jump;
	case 8:
        distroy(&start);
	goto jump;
        case 9:
        exit(0);
       default:printf("enter the number between 1-9\n");
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
		temp->prev=NULL;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp;
		n->prev=NULL;
		temp->prev=n;
		temp=n;
		*base=temp;		
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
		temp->prev=NULL;
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
		n->prev=temp;		
	}
}
void delete_from_begin(struct node **base)
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
		 temp->prev=NULL;		
	}
}
void delete_from_end(struct node **base)
{
	struct node *temp,*temp1;
	temp=*base;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{		
	while(temp->next !=NULL)
			{
				temp1=temp;
				temp=temp->next;
			}
		 free(temp);
		 temp1->next=NULL;
		 temp=*base;
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
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);		
	}

}
void insert_at_position(struct node **base, int pos, int data)
{
	struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->prev=NULL;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		for(int i=1;i<pos-1;i++)
			temp=temp->next;
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->prev=temp;
		n->next=temp->next;
		temp->next=n;		
	}
}
void delete_at_position(struct node **base, int pos)
{
	struct node *temp,*temp1;
	temp=*base;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp->next->next;
		temp->next->prev=temp;
		free(temp1);		
	}

}

