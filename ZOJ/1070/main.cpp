/*1070 ZOJ*/
#include <stdio.h>
#include <math.h>


int main()
{
    double vs,vr,r,c,w;
    int n,i;
    while(scanf("%lf %lf %lf %d", &vs,&r,&c, &n)!=EOF && n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf",&w);
            vr=w*c*vs/sqrt(w*w+1);
            printf("%.3lf\n", vr);
        }
    }

	return 0;
}