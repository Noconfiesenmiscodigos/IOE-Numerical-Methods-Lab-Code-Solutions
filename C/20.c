/* Trapezoidal rule.*/
#include <stdio.h>
float y(float x)
{
    return 1/(1+x*x);
}
main()
{
    float x0,xn,h,s;
    int i,n;
    puts("Enter x0,xn,no. of subintervals");
    scanf ("%f %f %d",&x0,&xn,&n);
    h = (xn-x0)/n;
    s = y(x0)+y(xn);
    for (i=1; i<=n-1; i++)
        s += 2*y(x0+i*h);
    printf ("Value of integral is % 6.4f\n",
            (h/2)*s);
}

/*
Enter x0, xn, no. of subintervals
0 6 6
Value of integral is 1.4108
*/
