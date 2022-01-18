/* Solution of Hyperbolic equation */
#include <stdio.h>
#define XEND 5
#define TEND 5
float f(int x)
{
    return x*x*(5-x);
}
main()
{
    float u[XEND+1][TEND+1],csqr,ust,uet;
    int i,j;
    puts("Enter the square of 'c'");
    scanf("%d",&csqr);
    printf("Enter the value of u[0][t]\n");
    scanf("%f",&ust);
    printf("Enter the value of u[%d][t]\n",
           XEND);
    scanf("%f",&uet);
    for (j=0; j<=TEND; j++)
    {
        u[0][j] = ust;
        u[XEND][j] = uet;
    }
    for (i=1; i<=XEND-1; i++)
        u[i][1] = u[i][0] = f(i);
    for (j=1; j<=TEND-1; j++)
        for (i=1; i<=XEND-1; i++)
            u[i][j+1] = u[i-1][j]+u[i+1][j]
                        -u[i][j-1];
    puts("The values of u[i][j] are:-");
    for (j=0; j<=TEND; j++)
    {
        for (i=0; i<=XEND; i++)
            printf("%6.1f",u[i][j]);
        printf("\n");
    }
}

/*
Enter the square of 'c'
16
Enter the value of u[0][t]
0
Enter the value of u[5][t]
0
The values of u[i][j] are:-
   0.0   4.0  12.0  18.0  16.0   0.0
   0.0   4.0  12.0  18.0  16.0   0.0
   0.0   8.0  10.0  10.0   2.0   0.0
   0.0   6.0   6.0  -6.0  -6.0   0.0
   0.0  -2.0 -10.0 -10.0  -8.0   0.0
   0.0 -16.0 -18.0 -12.0  -4.0   0.0
*/
