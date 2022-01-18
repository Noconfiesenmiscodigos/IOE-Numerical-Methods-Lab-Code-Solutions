/* Power method for finding largest eigenvalue */
#include <stdio.h>
#include <math.h>
int N;
typedef float array[N];
void findmax(float *max,array x)
{
    int i;
    *max = fabs(x[0]);
    for (i=1; i<N; i++)
        if (fabs(x[i]) > *max)
            *max = fabs(x[i]);
}
main()
{
    float a[N][N],x[N],r[N],maxe,
          err,errv,aerr,e,s,t;
    int i,j,k,itr,maxitr;
    printf("Enter the matrix rowwise\n");
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            scanf("%f",&a[i][j]);
    printf("Enter the initial approximation"
           "to the eigen vector\n");
    for (i=0; i<N; i++)
        scanf("%f",&x[i]);
    printf("Enter the allowed error,"
           "maximum iterations\n");
    scanf("%f %d",&aerr,&maxitr);
    printf("Itr no. Eigenvalue"
           "EigenVector\n");
    /* now finding the largest eigenvalue in
    the initial approx. to eigen vector */
    findmax(&e,x);
    /* now starting the iterations */
    for (itr=1; itr<=maxitr; itr++)
    {
        /* loop to multiply the matrices
        a and x */
        for (i=0; i<N; i++)
        {
            s = 0;
            for (k=0; k<N; k++)
                s += a[i][k]*x[k];
            r[i]=s;
        }
        findmax(&t,r);
        for (i=0; i < N; i++) r[i] /= t;
        maxe = 0;
        for (i=0; i<N; i++)
        {
            err = fabs(x[i]-r[i]);
            if (err > maxe) maxe = err;
            x[i] = r[i];
        }
        errv = fabs(t-e);
        e = t;
        printf("%4d %12.4f",itr,e);
        for (i=0; i<N; i++)
            printf("%9.3f",x[i]);
        printf("\n");
        if ((errv <= aerr) && (maxe <= aerr))
        {
            printf("Converges in %d"
                   "iterations\n",itr);
            printf("Largest eigen value"
                   "= %6.2f\n",e);
            printf("Eigenvector:-\n");
            for (i=0; i<N; i++)
                printf("x[%3d] = %6.2f\n",
                       i+1,x[i]);
            printf("\n");
            return 0;
        }
    }
    printf("Solution does not converge,"
           "iterations not sufficient\n");
    return 1;
}

/*
Enter the matrix rowwise
2 -1 0
-1 2 -1
0 -1 2
Enter the initial approximation to the eigenvector
1 0 0
Enter the allowed error, maximum iterations
.01 10
Itr No. Eigen Value Eigen Vector
1 2.0000 1.000 - 0.500 0.000
2 2.5000 1.000 - 0.800 0.200
3 2.8000 1.000 -1.000 0.429
4 3.4286 0.875 -1.000 0.542
5 3.4167 0.805 -1.000 0.610
6 3.4146 0.764 -1.000 0.650
7 3.4143 0.741 -1.000 0.674
8 3.4142 0.727 -1.000 0.688
9 3.4142 0.719 -1.000 0.696
Converges in 9 iterations
Largest eigenvalue = 3.41
Eigenvector:-
X[1] = 0.72
X[2] = -1.00
X[3] = 0.70
*/
