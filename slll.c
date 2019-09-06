#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};
typedef struct node sn;

void addbeg(sn **q,int val)
{
	sn *temp,*n;
	temp=*q;
	if(temp==NULL)
	{
		temp= (sn *)malloc(sizeof(sn));
		temp->val=val;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{
		n=(sn *)malloc(sizeof(sn));
		n->val=val;
		n->next=temp;	
		*q=n;	
	}
}


void addend(sn **q,int val)
{
	sn *temp,*n;
	temp=*q;
	if(temp==NULL)
	{
		temp= (sn *)malloc(sizeof(sn));
		temp->val=val;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{
		while(temp->next !=NULL)
			temp=temp->next;
		n=(sn *)malloc(sizeof(sn));
		n->val=val;
		n->next=NULL;
		temp->next=n;		
	}
}

void addpos(sn **q, int pos, int val)
{
	sn *temp,*n,*temp1=*q;
	temp=*q;
	if(temp==NULL)
	{
		temp= (sn *)malloc(sizeof(sn));
		temp->val=val;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{	int count=0;
		while(temp1!=NULL){
			count++;
			temp1=temp1->next;		
		}
		if(pos<=count){
		for(int i=1;i<=pos-1;i++)
			temp=temp->next;
		n=(sn*)malloc(sizeof(sn));
		n->val=val;
		n->next=temp->next;
		temp->next=n;	}
		else 	
			printf("Not valid:::\n");	
	}
}


void delbeg(sn **q)
{
	sn *temp;
	temp=*q;
	if(temp==NULL)
	{
		printf("\nNo elements ro delete\n");	
	}
	else
	{
		*q=temp->next;
		 free(temp);
		 temp=*q;		
	}
}


void delend(sn **q)
{
	sn *temp,*temp1;
	temp=*q;
	if(temp==NULL)
	{
		printf("\nNo elements ro delete\n");	
	}
	else
	{
		while(temp->next->next != NULL)
		temp=temp->next;
		temp1=temp->next;
		temp->next=NULL;
		free(temp1);
	}
	
}


void delpos(sn **q, int pos)
{
	sn *temp;
	temp=*q;
	if(temp==NULL)
		printf("\nNothing to delete\n");
	else
	{ 
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		temp=temp->next;
		free(temp);		
	}
}

void display(sn **q)
{
	sn *temp;
	temp=*q;
	if(temp==NULL)
	printf("\nNothing to display\n");
	else
	{ 	printf("\nElements in linked list:::\n");
		while (temp->next!=NULL)
		{
			printf("%d\t",temp->val);
			temp=temp->next;
		}
		printf("%d\t",temp->val);
		printf("\n");		
	}


}



void destroy(sn **q)
{
	sn *temp,*temp1;
	temp=*q;
	while(temp!=NULL)
	{
	temp1=temp;
	temp=temp->next;
	free(temp1);
	}
	*q=temp;
}

int count(sn **q)
{
	int count=0;
	sn *temp;
	temp=*q;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;

	}
	printf("\nNo.of elements in linkelist is %d\n",count);
	return count;
}

void reverse(sn **q)
{
	sn *temp,*temp1=NULL,*temp2=NULL;
	temp=*q;
	while(temp!=NULL)
	{
		temp2=temp->next;
		temp->next=temp1;
		temp1=temp;
		temp=temp2;
		
	}
*q=temp1;	

}

void search(sn **q,int val)
{
	int count=0;
	sn *temp;
	temp=*q;
	while(temp!=NULL)
	{
		count++;
		if(temp->val==val)
			printf("\n%d found at position %d\n",val,count);
		
		temp=temp->next;
		
	}	
	//printf("\n%d not found\n",val);
}



int main()
{
int ch,val,pos;
sn *start=NULL;
 
while(1)
{
	printf("\n\n1.insert at begin\n2.insert at end\n3.insert at position\n4.display\n5.del at begin\n6.del at end\n7.delete at position\n8.destroy linked list\n9.count of elements in list\n10.Reverse\n11.search an element\n12.exit\n\n");
	scanf("%d",&ch);
	switch (ch)
	{
        case 1:
		printf("enter the element\n");
		scanf("%d",&val);
		addbeg(&start,val);
		break;
        case 2:
		printf("enter the element\n");
		scanf("%d",&val);
		addend(&start,val);
		break; 
	case 3:count(&start);
		printf("enter element and position to insert\n");
		scanf("%d%d",&val,&pos);	
		addpos(&start,pos,val);
		break;
	case 4:	printf("\n");
		display(&start);
		break;
        case 5:
		delbeg(&start);
		break;
        case 6:
		delend(&start);
		break;
	case 7:
		printf("enter the position to delete\n");
		scanf("%d",&pos);	
		delpos(&start,pos);
        	break;
        case 8:
		destroy(&start);
		break;
	case 9:
		count(&start);
		break;
	case 10:
		reverse(&start);
		break;
	case 11:
		printf("Enter element to search:::");
		scanf("%d",&val);
		search(&start,val);
		break;
	case 12:
        	exit(0);
		break;
	default:
		printf("Enter from given options::::\n");
       		break;
        
    	}
}
return 0;
}





/*

pavani@TSHYD-033:~/Desktop$ gcc slll.c 
pavani@TSHYD-033:~/Desktop$ ./a.out 


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

1
enter the element
14


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

1
enter the element
345


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
345	14	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

2
enter the element
12551


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
345	14	12551	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

3

No.of elements in linkelist is 3
enter element and position to insert
2
2


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
345	14	2	12551	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

3

No.of elements in linkelist is 4
enter element and position to insert
33
3


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
345	14	2	33	12551	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

3

No.of elements in linkelist is 5
enter element and position to insert
45
5


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
345	14	2	33	12551	45	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

10


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
45	12551	33	2	14	345	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

9

No.of elements in linkelist is 6


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

5


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
12551	33	2	14	345	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

6


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

4


Elements in linked list:::
12551	33	2	14	


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit

11
Enter element to search:::2

2 found at position 3


1.insert at begin
2.insert at end
3.insert at position
4.display
5.del at begin
6.del at end
7.delete at position
8.destroy linked list
9.count of elements in list
10.Reverse
11.search an element
12.exit




*/
