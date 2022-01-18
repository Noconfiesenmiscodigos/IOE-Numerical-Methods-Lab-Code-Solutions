/* Muller's Method */
#include <stdio.h>
#include <math.h>
#define I 2
float y(float x)
{
    return cos(x)-x*exp(x);
}
main()
{
    int i,itr,maxitr;
    float x[4],li,di,mu,s,l,aerr;
    printf("Enter the initial "
           "approximations\n");
    for (i = I-2; i<3; i++)
        scanf("%f",&x[i]);
    printf("Enter allowed error,"
           "maximum iterations\n");
    scanf("%f %d",&aerr,&maxitr);
    for(itr = 1; itr <= maxitr; itr++)
    {
        li = (x[I]-x[I-1])/(x[I-1]-x[I-2]);
        di = (x[I]-x[I-2])/(x[I-1]-x[I-2]);
        mu = y(x[I-2])*li*li
             - y(x[I-1])*di*di
             + y(x[I])*(di+li);
        s = sqrt((mu*mu - 4*y(x[I])*di*li*(y(x[I-2])*li-y(x[I-1])
                                           *di + y(x[I]))));
        if (mu < 0)
            l = (2*y(x[I])*di)/(-mu+s);
        else
            l = (2*y(x[I])*di)/(-mu-s);
        x[I+1] = x[I]+l*(x[I] - x[I-1]);
        printf("Iteration no. % 3d,"
               "x = %7.5f\n",itr,x[I+1]);
        if (fabs(x[I+1]-x[I]) < aerr)
        {
            printf("After %3d iterations,"
                   "the solution is %6.4f\n",
                   itr,x[I+1]);
            return 0;
        }
        for (i=I-2; i<3; i++)
            x[i] = x[i+1];
    }
    printf("Iterations not sufficient,"
           "solution does not converge\n");
    return 1;
}

/*
Enter the initial approximations
–1 0 1
Enter allowed error, maximum iterations
.0001 10
Iteration No. 1 X = 0.44152
Iteration No. 2 X = 0.51255
Iteration No. 3 X = 0.51769
Iteration No. 4 X = 0.51776
After 4 iterations, the solution is 0.5178
*/
