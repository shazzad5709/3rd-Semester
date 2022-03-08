#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1.0e-9

double function(double x)
{
    return (x*x*x+4*x*x-10);
}

void falsePosition(double a, double b)
{
    double c=a;
    int it=0;
    while(fabs(function(c))>=EPSILON)
    {
        c=(a*function(b)-b*function(a))/(function(b)-function(a));
        it++;
        if (function(c)*function(a) < 0)
			b=c;
		else
			a=c;

	}
	printf("The value of root: %.9lf ", c);
	printf("\nNo. of iteration: %d", it);
    return;
}


int main()
{
	double a=1, b=2;
	falsePosition(a, b);
	return 0;
}