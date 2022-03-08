#include<stdio.h>
#include<math.h>
#define EPSILON 1e-9

double func(double x)
{
	return (x*x*x+4*x*x-10);
}

void bisection(double a, double b)
{
	double c=a;
	int itr=0;

	while(fabs(func(c))>=EPSILON)
	{
	    itr++;
		c=(a+b)/2;
		if (func(c)*func(a) < 0)
			b=c;
		else
			a=c;
	}
	printf("The value of root: %.9lf\n", c);
	printf("No. of iteration: %d", itr);
    return;
}

int main()
{
	double a=1, b=2;
	bisection(a, b);
	return 0;
}