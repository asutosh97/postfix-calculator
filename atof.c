#include<ctype.h>
double atof(char s[])
{
	int i=0,sign;
	double value;
	while(isspace(s[i]))
		i++;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='-'||s[i]=='+')
		i++;
	for(value=0.0;isdigit(s[i]);i++)
		value=value*10+(s[i]-'0');
	if(s[i]=='.')
		i++;
	double power;
	for(power=1.0;isdigit(s[i]);i++)
	{
		value=value*10+(s[i]-'0');
		power=power*10;
	}
	if(s[i]=='e'||s[i]=='E')
		i++;
	double factor;
	factor=(s[i]=='-')?0.1:10;
	if(s[i]=='-'||s[i]=='+')
		i++;
	double base=1;
	double temp;
	for(temp=0.0;isdigit(s[i]);i++)
		temp=temp*10+(s[i]-'0');
	
	while(temp--)
		base=base*factor;

	return value/power*base; 
}