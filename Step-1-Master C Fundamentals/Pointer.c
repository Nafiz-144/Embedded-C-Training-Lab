#include<stdio.h>
int main(){
int a=5;
int *p;
p=&a;
printf("Value of a is %d\n",a);
printf("Address of a is %p\n",(void *)&a);

printf("Address of a using pointer p is %p\n",p);
}