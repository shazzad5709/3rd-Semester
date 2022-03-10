#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 300

double x[N+1], f[N+1], dc[N+1], dm[N+1];

double F(double x)
{
	return (x*x*x+4*x*x-10);
}

double diff(double x)
{
	return (3*x*x+8*x);
}

double forward(double x1, double x2)
{
	return ((F(x2)-F(x1))/(x2-x1));
}

double backward(double x1, double x0)
{
	return ((F(x1)-F(x0))/(x1-x0));
}

double central(double x2, double x0)
{
	return ((F(x2)-F(x0))/(x2-x0));
}

int main()
{
	
	double l=0, r=10;
	int n=N;

	
	double h=(r-l)/(double)n;

	x[0]=0;
	f[0]=F(x[0]);
	dc[0]=diff(x[0]);
	
	for(int i=1; i<N; i++)
	{
		x[i]=x[i-1]+h;
		f[i]=F(x[i]);
		dc[i]=diff(x[i]);
	}

	x[N]=10;
	f[N]=F(x[N]);
	dc[N]=diff(x[N]);

	
	dm[0]=forward(x[0], x[1]);

	for(int i=1; i<N; i++)
	{
		dm[i]=central(x[i+1], x[i-1]);
	}

	dm[N]=backward(x[N], x[N-1]);

	double max=fabs(dm[0]-dc[0]);
	
	for(int i=1; i<N+1; i++)
	{
		if(max<fabs(dm[i]-dc[i]))
			max=fabs(dm[i]-dc[i]);
	}
	// for(int i=0; i<3; i++)
	// 	printf("F=%lf D=%lf\n", dm[i], dc[i]);
	printf("Maximum: %lf\n", max);
}
