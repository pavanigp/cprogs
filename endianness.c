

#include <stdio.h>
 
int main(void)
{
 unsigned int value = 0x11223344;
 char *r = (char *) &value;
 int i;
 
 for(i=0; i<4; i++) {
 printf("Address of 0x%x = %p \n", r[i], &r[i]);
 }

if(*r==0x44)
printf("Little endian");

else 
printf("Big endian");
 return 0;
}
