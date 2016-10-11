#include<stdio.h>
#define STACK_MAX 1000
double stack[STACK_MAX];
int top=0;
void push(double x)
{
	//if(top>=STACK_MAX)
	//	printf("Error:Stack Overflow!!!\n");
	//else
		stack[top++]=x;
}
double pop(void)
{
	if(top)
		return stack[--top];
	else
		printf("Error:Stack Underflow!!!\n");
}
double printtop(void)
{
	if(top)
		return stack[top-1];
	else
		printf("Empty Stack!!!\n");
}
void duplicate(void)
{
	if(top)
	{
		double temp=pop();
		push(temp);
		push(temp);
	}
	else
		printf("Empty stack!!!\n");
}
void swap(void)
{
	if(top>1)
	{
		double temp1=pop();
		double temp2=pop();
		push(temp1);
		push(temp2);
	}
	else
		printf("Error:Insufficient Elements!!!\n");
}
void traverse()
{
	int i=top-1;
	printf("Stack is:");
	for(;i>=0;i--)
	{
		printf("%lf ",stack[i]);
	}
	printf("\n");
}