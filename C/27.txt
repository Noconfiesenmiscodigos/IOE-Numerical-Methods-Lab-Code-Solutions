/* Laplace's Equation */
#include <stdio.h>
#include <math.h>
#define SQR 4
typedef float array[SQR+1][SQR+1];
void getrow(int i,array u)
{
    int j;
    printf("Enter the values of u[%d,j],"
           "j=1,%d\n",i,SQR);
    for (j=1; j<=SQR; j++)
        scanf("%f",&u[i][j]);
}
void getcol(int j,array u)
{
    int i;
    printf("Enter the values of u[i,%d],"
           "i=2,%d\n",j,SQR-1);
    for (i=2; i<=SQR-1; i++)
        scanf ("%f",&u[i][j]);
}
void printarr(array u,int width,int precision)
{
    int i,j;
    for (i=1; i<=SQR; i++)
    {
        for (j=1; j<=SQR; j++)
            printf("%7.2f%7.2f%7.2f",width,precision, u[i][j]);
        printf("\n");
    }
}
main ()
{
    array u;
    float maxerr,aerr,err,t;
    int i,j,itr,maxitr;
    for (i=1; i<=SQR; i++)
        for(j=1; j<=SQR; j++)
            u[i][j]=0;
    puts ("Enter the boundary conditions");
    getrow(1,u);
    getrow(SQR,u);
    getcol(1,u);
    getcol(SQR,u);
    puts ("Enter allowed error,"
          "maximum iterations");
    scanf ("%f %f",&aerr,&maxitr);
    for (itr=1; itr<=maxitr; itr++)
    {
        maxerr=0;
        for (i=2; i<=SQR-1; i++)
            for(j=2; j<=SQR-1; j++)
            {
                t=(u[i-1][j]+u[i+1][j]+
                   u[i][j+1]+u[i][j-1])/4;
                err=fabs(u[i][j]-t);
                if (err > maxerr)
                    maxerr = err;
                u[i][j]=t;
            }
        printf("Iteration no. %d \n",itr);
        printarr(u,9,2);
        if (maxerr <= aerr)
        {
            printf ("After %d iterations \n"
                    "The solution:-\n",itr);
            printarr(u,8,1);
            return 0;
        }
    }
    puts ("Iterations not sufficient.");
    return 1;
}
/*
Enter the boundary conditions
Enter the values of u[1, j], j = 1, 4
1000 1000 1000 1000
Enter the values of u[4, j], j = 1, 4
1000 500 0 0
Enter the values of u[i, 1], i = 2, 3
2000 2000
Enter the values of u[i, 4], i = 2, 3
500 0
Enter allowed error, maximum iterations
.1 10
Iteration No.1
1000.00 1000.00 1000.00 1000.00
2000.00 750.00 562.50 500.00
2000.00 812.50 343.75 0.00
1000.00 500 0.00 0.00
Iteration No. 2
1000.00 1000.00 1000.00 1000.00
2000.00 1093.75 734.38 500.00
2000.00 984.38 429.69 0.00
1000.00 500.00 0.00 0.00
Iteration No.3
1000.00 1000.00 1000.00 1000.00
2000.00 1179.69 777.34 500.00
2000.00 1027.34 451.17 0.00
1000.00 500.00 0.00 0.00
Iteration No. 4
1000.00 1000.00 1000.00 1000.00
2000.00 1201.17 788.09 500.00
2000.00 1038.09 456.54 0.00
1000.00 500.00 0.00 0.00
Iteration No. 5
1000.00 1000.00 1000.00 1000.00
2000.00 1206.54 790.77 500.00
2000.00 1040.77 457.88 0.00
1000.00 500.00 0.00 0.00
Iteration No. 6
1000.00 1000.00 1000.00 1000.00
2000.00 1207.89 791.44 500.00
2000.00 1041.44 458.22 0.00
1000.00 500.00 0.00 0.00
Iteration No. 7
1000.00 1000.00 1000.00 1000.00
2000.00 1208.22 791.61 500.00
2000.00 1041.61 458.30 0.00
1000.00 500.00 0.00 0.00
Iteration No. 8
1000.00 1000.00 1000.00 1000.00
2000.00 1208.31 791.65 500.00
2000.00 1041.65 458.33 0.00
1000.00 500.00 0.00 0.00
After 8 iterations
The solution:-
1000.0 1000.0 1000.0 1000.0
2000.0 1208.3 791.7 500.0
2000.0 1041.6 458.3 0.0
1000.0 500.0 0.0 0.0
The solution:-
1000.0 1000.0 1000.0 1000.0
2000.0 1208.3 791.7 500.0
2000.0 1041.6 458.3 0.0
1000.0 500.0 0.0 0.0
*/
