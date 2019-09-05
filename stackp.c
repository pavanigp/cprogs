#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct stack
{
int data;
struct stack *link;
};

typedef struct stack sn;


void display(sn **q)
{
sn *temp;
temp=*q;
printf("Stack elements are::\n");
while(temp!=NULL){
	printf("%d\n",temp->data);
	temp=temp->link;}
printf("\n");
}

void push(sn **q,int n)
{
sn *temp;
temp=*q;
temp=(sn*)malloc(sizeof(sn));
temp->data=n;
temp->link=*q;
*q=temp;
}

void pop(sn **q)
{
sn *temp;
temp=*q;
printf("\n\n\n");
if(temp==NULL)
	printf("Stack is empty\n");
else
{
*q=temp->link;
free(temp);
temp=*q;
}
}

void StPeek(sn **q)
{
sn *temp;
temp=*q;
if(temp!=NULL)
{
printf("\ntop element is %d\n",temp->data);
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
printf("Number of elements in stack is %d\n",count);
}

int main()
{
int ch,data;
sn *p=NULL;
while(1)
{
printf("\nSelect option:::\n");
printf("1.push\n2.pop\n3.display\n4.peek\n5.count\n6.exit\n\n");
scanf("%d",&ch);

	switch (ch)
	{
	case 1:
		printf("\nEnter data to push::\n");
		scanf("%d",&data);
		printf("\n\n");
		push(&p,data);
		break;
	case 2:
		pop(&p);
		break; 
	case 3:
		display(&p);
		break;
	case 4:
		StPeek(&p);
		break;
	case 5:
		Count(&p);
		break;
	case 6:
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

pavani@TSHYD-033:~/Desktop$ gcc stackp.c 
pavani@TSHYD-033:~/Desktop$ ./a.out 

Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

1

Enter data to push::
12



Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

2




Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

3
Stack elements are::


Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

1

Enter data to push::
13



Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

3
Stack elements are::
13


Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

1

Enter data to push::
134



Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

1

Enter data to push::
154



Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

3
Stack elements are::
154
134
13


Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

5
Number of elements in stack is 3

Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

4

top element is 154

Select option:::
1.push
2.pop
3.display
4.peek
5.count
6.exit

6
*/
