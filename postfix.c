#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE 10000
#define NUMBER 0
#define MATHLIB 1
#define END -2
int get_line(char[],int);
int getop(char[],int,char **);
void push(double);
double pop(void);
void swap(void);
void clear(void);
void duplicate(void);
long long factorial(long long n);
char line[MAX_LINE];
int lp=0;
int main(int argc,char *argv[])
{
	char str[100];
	//get_line(line,MAX_LINE);
	//printf("Input String is:%s",line);
	int type;
	double p2;
	while((type=getop(str,argc,argv))!=EOF)
	{
		switch(type)
		{
			case NUMBER:
						//printf("String:%s\n",str);
						push(atof(str));
						break;
			case MATHLIB:
						if(strcmp("cos",str)==0)
							push(cos(pop()));
						else if(strcmp("sin",str)==0)
							push(sin(pop()));
						else if(strcmp("pow",str)==0)
						{
							double p2=pop();
							push(pow(pop(),p2));
						}
						else
							printf("Error:Invalid Operation!!!\n");
						break;
			case '+':
						push(pop()+pop());
						break;
			case 'x':
						push(pop()*pop());
						break;
			case '-':
						p2=pop();
						push(pop()-p2);
						break;
			case '/':
						p2=pop();
						if(p2)
						{
							push(pop()/p2);
						}
						else
							printf("Zero divide error!!!\n");
						break;
			case '%':
						p2=pop();
						if(p2)
						{
							push((long long)pop()%(long long)p2);
						}
						else
							printf("Zero divide error!!!\n");
						break;
			case '^':
						p2=pop();
						push(pow(pop(),p2));
						break;
			case '!':
						push(factorial(pop()));
						break;
			case END:
						printf("Evaluated expression:%.8g\n",pop());
						exit(0);
			default:
					printf("Error:Invalid Operation!!!\n");
					break;
		}
	}
	return 0;
}