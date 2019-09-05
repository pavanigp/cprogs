#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct queue
{
int data;
struct queue *link;
};

typedef struct queue sn;


void display(sn **f)
{
sn *temp;
temp=*f;
printf("Queue elements are::\n");
while(temp!=NULL){
	printf("%d\n",temp->data);
	temp=temp->link;
	}
printf("\n");
}

void add(sn **f,sn **r,int n)
{
sn *temp,*temp1;

temp=(sn*)malloc(sizeof(sn));
temp->data=n;
temp->link=NULL;
if(*f==NULL)
{
*f=temp;
*r=temp;
}
else
{
temp1=*r;
temp1->link=temp;
*r=temp;
}


}

void deq(sn **f)
{
sn *temp;
temp=*f;
printf("\n\n\n");
if(temp==NULL)
	printf("queue is empty\n");
else
{
*f=temp->link;
free(temp);
temp=*f;
}
}

void front(sn **f)
{
sn *temp;
temp=*f;
if(temp!=NULL)
{
printf("\nRear element is %d\n",temp->data);
}
}



void rear(sn **r)
{
sn *temp;
temp=*r;
if(temp!=NULL)
{
printf("\nRear element is %d\n",temp->data);
}
}


void Count(sn **q)
{
sn *temp;
temp=*q;
int count=0;
while(temp!=NULL)
{
count++;
temp=temp->link;
}
printf("Number of elements in queue is %d\n",count);
}

int main()
{
int ch,data;
sn *f=NULL;
sn *r=NULL;
while(1)
{
printf("\nSelect option:::\n");
printf("1.enq\n2.deq\n3.display\n4.rear\n5.front\n6.count\n7.exit\n\n");
scanf("%d",&ch);

	switch (ch)
	{
	case 1:
		printf("\nEnter data to push::\n");
		scanf("%d",&data);
		printf("\n\n");
		add(&f,&r,data);
		break;
	case 2:
		deq(&f);
		break; 
	case 3:
		display(&f);
		break;
	case 4:
		rear(&r);
		break;
	case 5:
		front(&f);
		break;
	case 6:
		Count(&f);
		break;
	case 7:
		exit(1);
		break;
	default:
		printf("enter digits in given options::::");
		break;
        
	}
}
return 0;
}


/*

pavani@TSHYD-033:~/Desktop/Mr.Teja/datast$ gcc queue.c 
pavani@TSHYD-033:~/Desktop/Mr.Teja/datast$ ./a.out 

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

1

Enter data to push::
123



Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

1

Enter data to push::
34



Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

3
Queue elements are::
123
34


Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

4

Rear element is 34

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

5

Rear element is 123

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

1

Enter data to push::
56



Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

1

Enter data to push::
5677



Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

6
Number of elements in queue is 4

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

4

Rear element is 5677

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

5

Rear element is 123

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

2




Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

3
Queue elements are::
34
56
5677


Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

4

Rear element is 5677

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

5

Rear element is 34

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

6
Number of elements in queue is 3

Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

3
Queue elements are::
34
56
5677


Select option:::
1.enq
2.deq
3.display
4.rear
5.front
6.count
7.exit

7
*/
