/* Gauss elimination method */
#include <stdio.h>
#define N 4
main()
{
    float a[N][N+1],x[N],t,s;
    int i,j,k;
    printf("Enter the elements of the"
           "augmented matrix rowwise\n");
    for (i=0; i<N; i++)
        for (j=0; j<N+1; j++)
            scanf("%f",&a[i][j]);
    for (j=0; j<N-1; j++)
        for (i=j+1; i<N; i++)
        {
            t = a[i][j]/a[j][j];
            for (k=0; k<N+1; k++)
                a[i][k]=a[j][k]*t;
        }
    /* now printing the
    upper triangular matrix */
    printf("The upper triangular matrix"
           "is:-\n");
    for (i=0; i<N; i++)
    {
        for (j=0; j<N+1; j++)
            printf("%8.4f",a[i][j]);
        printf("\n");
    }
    /* now performing back substitution */
    for (i=N-1; i>=0; i--)
    {
        s = 0;
        for (j=i+1; j<N; j++)
            s += a[i][j]*x[j];
        x[i] = (a[i][N]-s)/a[i][i];
    }
    /* now printing the results */
    printf("The solution is:- \n");
    for (i=0; i<N; i++)
        printf("x[%3d] = %7.4f\n",i+1,x[i]);
}
/*
Enter the elements of augmented matrix rowwise
10 -7 3 5 6
-6 8 -1 -4 5
3 1 4 11 2
5 -9 -2 4 7
10.000 -7.0000 3.0000 5.0000 6.0000
0.0000 3.8000 0.8000 -1.0000 8.6000
-0.0000 -0.0000 2.4474 10.3158 -6.8158
0.0000 -0.0000 -0.0000 9.9247 9.9247
The solution is:-
X[ 1] = 5.0000
X[ 2] = 4.0000
X[ 3] = -7.0000
X[ 4] = 1.0000
*/
