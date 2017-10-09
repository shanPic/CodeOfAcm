#include<stdio.h>
#include<math.h>
double f(double x)
{
	return (8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6);
}
int main()
{
	int ncase,i,j,k;
	double m,n;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%lf",&m);
		if(f(0)>m||f(100)<m)
		{
			printf("No solution!\n");
			continue;
		}
		double l,r;
		l=0.0;
		r=100.0;
		double mid=50.0;
		while(fabs(f(mid)-m)>1e-5)
		{
		     if((f(mid)>m))
			 {
			 	r=mid;
 				mid=(l+r)/2;	
 			 }	
 			 else if(f(mid)<m)
 			 {
 			 	l=mid;
 			 	mid=(l+r)/2; 			 	
 			 }
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}