/* Gauss jordan method */
#include <stdio.h>
#define N 3
main()
{
    float a[N][N+1],t;
    int i,j,k;
    printf("Enter the elements of the "
           "augmented matrix rowwise\n");
    for (i=0; i<N; i++)
        for (j=0; j<N+1; j++)
            scanf("%f",&a[i][j]);
    /* now calculating the values of x1,x2,....,xN */
    for (j=0; j<N; j++)
        for (i=0; i<N; i++)
            if (i!=j)
            {
                t = a[i][j]/a[j][j];
                for (k=0; k<N+1; k++)
                    a[i][k] -= a[j][k]*t;
            }
    /* now printing the diagonal matrix */
    printf("The diagonal matrix is:-\n");
    for (i=0; i<N; i++)
    {
        for (j=0; j<N+1; j++)
            printf("%9.4f",a[i][j]);
        printf("\n");
    }
    /* now printing the results */
    printf("The solution is:- \n");
    for (i=0; i<N; i++)
        printf("x[%3d] = %7.4f\n",
               i+1,a[i][N]/a[i][i]);
}

/*
Enter elements of augmented matrix rowwise
10 -7 3 5 6
-6 8 -1 -4 5
3 1 4 11 2
5 -9 -2 4 7
The diagonal matrix is:-
10.0000 -0.0000 -0.0000 -0.0000 50.0000
0.0000 3.8000 -0.0000 0.0000 15.2000
-0.0000 0.0000 2.4474 0.0000 -17.1316
0.0000 -0.0000 0.0000 9.9247 9.9247
The solution is:-
X[ 1] = 5.0000
X[ 2] = 4.0000
X[ 3] = -7.0000
X[ 4] = 1.0000
*/
