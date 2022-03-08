#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1.0e-9

double func(double x)
{
	return x*x*x + 4*x*x - 10;
}

double derivFunc(double x)
{
	return (3*x*x+8*x);
}


void newtonRaphson(double x)
{
    int c=0;
	double h=func(x)/derivFunc(x);
	while (fabs(h)>=EPSILON)
	{
		c++;
		h=func(x)/derivFunc(x);
		x=x-h;
	}
	printf("The value of root: %.9lf\n", x);
	printf("No. of iteration: %d", c);

}


int main()
{
	double x0=1;
	newtonRaphson(x0);
	return 0;
}