/*Solution of parabolic equations by Bendre
Schmidt method*/
#include <stdio.h>
#define XEND 8
#define TEND 5
float f(int x)
{
    return 4*x-(x*x)/2.0;
}
main()
{
    float u[XEND+1][TEND+1],h=1.0,k=0.125,
                            csqr,alpha,ust,uet;
    int i,j;
    puts("Enter the square of 'c'");
    scanf("%f",&csqr);
    alpha = (csqr*k)/(h*h);
    puts ("Enter the value of u[0,t]");
    scanf ("%f",&ust);
    printf ("Enter the value of u[%d,t]\n",
            XEND);
    scanf("%f",&uet);
    for (j=0; j<=TEND; j++)
        u[0][j]=u[XEND][j]=ust;
    for (i=1; i<=XEND-1; i++)
        u[i][0]=f(i);
    for (j=0; j<=TEND-1; j++)
        for (i=1; i<=XEND-1; i++)
            u[i][j+1]=
                alpha*u[i-1][j]
                +(1-2*alpha)*u[i][j]
                +alpha*u[i+1][j];
    printf("The value of alpha is %4.2f\n", alpha);
    puts("The values of u[i,j] are:-");
    for (j=0; j<TEND; j++)
    {
        for (i=0; i<XEND; i++)
            printf("%7.4f",u[i][j]);
        printf("\n");
    }
}

/*
Enter the square of 'c'
4
Enter the value of u[0,t]
0
Enter the value of u[8,t]
0
The value of alpha is 0.50
The values of u[i,j] are:-
 0.0000 3.5000 6.0000 7.5000 8.0000 7.5000 6.0000 3.5000
 0.0000 3.0000 5.5000 7.0000 7.5000 7.0000 5.5000 3.0000
 0.0000 2.7500 5.0000 6.5000 7.0000 6.5000 5.0000 2.7500
 0.0000 2.5000 4.6250 6.0000 6.5000 6.0000 4.6250 2.5000
 0.0000 2.3125 4.2500 5.5625 6.0000 5.5625 4.2500 2.3125
*/
