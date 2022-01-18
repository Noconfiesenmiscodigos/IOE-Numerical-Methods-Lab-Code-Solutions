/* Newton Raphson Method */
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x*log10(x)-1.2;
}
float df(float x)
{
    return log10(x) + 0.43429;
}
main()
{
    int itr,maxitr;
    float h,x0,x1,aerr;
    printf("Enter x0,allowed error,"
           "maximum iterations\n");
    scanf("%f %f %d",&x0,&aerr,&maxitr);
    for (itr=1; itr<=maxitr; itr++)
    {
        h = f(x0)/df(x0);
        x1 = x0-h;
        printf("Iteration no. %3d,"
               "x = %9.6f\n",itr,x1);
        if (fabs(h) < aerr)
        {
            printf("After %3d iterations,"
                   "root = %8.6f\n", itr,x1);
            return 0;
        }
        x0 = x1;
    }
    printf("Iterations not sufficient,"
           "solution does not converge\n");
    return 1;
}

/*
Enter x0, allowed error, maximum iterations
2.000001 10
Iteration No. 1 X = 2.813170
Iteration No. 2 X = 2.741109
Iteration No. 3 X = 2.740646
Iteration No. 4 X = 2.740646
After 4 iterations, root = 2.740646
*/
