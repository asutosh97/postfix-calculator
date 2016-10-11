#include<stdio.h>
#include<ctype.h>
#define MATHLIB 1
#define NUMBER 0
#define END -2
extern int argc;
void traverse(void);
int wptr=1;
int lptr=0;
int getop(char s[],int argc,char *argv[])
{
	int i=-1;

	if(argv[wptr][lptr]=='\0')
	{	
		//printf("Next argument\n");
		wptr++;
		lptr=0;
	}

	if(wptr>argc-1)
		return END;


	if(argv[wptr][lptr]=='x'||argv[wptr][lptr]=='X')
		return argv[wptr][lptr++];

	if(isalpha(argv[wptr][lptr]))						//if is alphabet(mathematical function)
	{
		while(isalpha(argv[wptr][lptr]))
			s[++i]=argv[wptr][lptr++];
		//if(line[lp]!=EOF)
		//	lp--;
		s[++i]='\0';
		return MATHLIB;
	}	

	if(!isdigit(argv[wptr][lptr])&&argv[wptr][lptr]!='.'&&argv[wptr][lptr]!='-'&&argv[wptr][lptr]!='+')	
		return argv[wptr][lptr++];
	
	if(argv[wptr][lptr]=='+'||argv[wptr][lptr]=='-')
	{
		if(isdigit(argv[wptr][lptr+1])||argv[wptr][lptr+1]=='.')
		{
			s[++i]=argv[wptr][lptr++];
		}
		else
		{
			return argv[wptr][lptr++];
		}
	}	

	if(isdigit(argv[wptr][lptr]))
	{
		while(isdigit(argv[wptr][lptr]))
			s[++i]=argv[wptr][lptr++];
	}
	if(argv[wptr][lptr]=='.')
	{
		s[++i]=argv[wptr][lptr++];
		while(isdigit(argv[wptr][lptr]))
			s[++i]=argv[wptr][lptr++];
	}	
	s[++i]='\0';
	//if(line[lp]!=EOF)
		//lp--;
	return NUMBER;
}

int get_line(char s[],int lim)
{
	int i=0,c;
	for(i=0;(i<lim-1)&&(c=getchar())!=EOF&&(c!='\n');i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}
long long factorial(long long n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}