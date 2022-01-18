/* Bisection Method */
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (x*x*x - 4*x - 9);
}
void bisect(float *x,float a,float b,int *itr)
{
    *x = (a + b)/2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n",*itr,*x);
}
main()
{
    int itr = 0, maxitr;
    float x, a, b, aerr, x1;
    printf("Enter the values of a,b,"
           "allowed error, maximum iterations\n");
    scanf("%f %f %f %d",&a,&b,&aerr,&maxitr);
    bisect(&x,a,b,&itr);
    do
    {
        if (f(a)*f(x) < 0)
            b = x;
        else
            a = x;
        bisect (&x1,a,b,&itr);
        if (fabs(x1-x) < aerr)
        {
            printf("After %d iterations, root "
                   "= %6.4f\n",itr,x1);
            return 0;
        }
        x = x1;
    }
    while (itr < maxitr);
    printf("Solution does not converge,"
           "iterations not sufficient");
    return 1;
}

/*
Enter the values of a, b, allowed error, maximum iterations
3 2.0001 20
Iteration No. 1 X = 2.50000
Iteration No. 2 X = 2.75000
Iteration No. 3 X = 2.62500
Iteration No. 4 X = 2.68750
Iteration No. 5 X = 2.71875
Iteration No. 6 X = 2.70313
Iteration No. 7 X = 2.71094
Iteration No. 8 X = 2.70703
Iteration No. 9 X = 2.70508
Iteration No. 10 X = 2.70605
Iteration No. 11 X = 2.70654
Iteration No. 12 X = 2.70630
Iteration No. 13 X = 2.70642
Iteration No. 14 X = 2.70648
After 14 iterations, root = 2.7065
*/
