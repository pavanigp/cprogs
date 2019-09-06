#include<stdio.h>
#include<string.h>
char rem[100];
int count=0;
char *radix_convert(int no, int radix )
{
int remainder,d;
while(no>0)
{
	remainder=no%radix;
	d=remainder+'0';
        if(d>'9')
        {
	d=d+7;
	}
	rem[count++]=d;
	no=no/radix;
	}
return rem;
}

int main()
{
	char *remainders;
	int decimal,base,i;
	printf("Entre a decimal number\n");
	scanf("%d",&decimal);
	printf("Enter a base to convert::\n");
	scanf("%d",&base);
	remainders=radix_convert(decimal,base);
	printf("After converting decimal %d to base %d\n",decimal,base);
	for(i=strlen(remainders)-1;i>=0;i--)
	printf("%c",remainders[i]);
	printf("\n");
	return 0;
}
