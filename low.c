#include<stdio.h>

int main()
{

char st;
printf("Enter a character:::");
scanf("%c",&st);
if( st> 96 && st<123)
	printf("\n%c is lowercase letter\n",st);
else
	printf("\n%c is not a lowercase letter\n",st);
return 0;
}



/*
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ gcc low.c 
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ gcc -Wall -Werror low.c 
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ ./a.out 
Enter a character:::a

a is lowercase letter
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ ./a.out 
Enter a character:::A

A is not a lowercase letter
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ ./a.out 
Enter a character:::z

z is lowercase letter
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ gcc -Wall -Werror low.c 
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ ./a.out 
Enter a character:::Z

Z is not a lowercase letter
pavani@TSHYD-033:~/Desktop/Mr.Teja/file$ 


*/
