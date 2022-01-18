/* Linear programming by simplex method */
#include <stdio.h>
#define ND 2
#define NS 2
#define N (ND+NS)
#define N1 (NS*(N+1))
void init(float x[],int n)
{
    int i=0;
    for (; i<n; i++) x[i] = 0;
}
main()
{
    int i,j,k,kj,ki,bas[NS];
    float a[NS][N+1],c[N],cb[NS],th[NS],
          x[ND],cj,z,t,b,min,max;
    /* Initializing the arrays to zero */
    init(c,N);
    init(cb,NS);
    init(th,NS);
    init(x,ND);
    for (i=0; i<NS; i++) init(a[i],N+1);
    /* Now set coefficients for slack
    Variables equal to one */
    for (i=0; i<NS; i++) a[i][i+ND] = 1.0;
    /* Now put the slack variables in the basis */
    for (i=0; i<NS; i++) bas[i] = ND+i;
    /* Now get the constraints
    and the objective function */
    puts("Enter the constraints");
    for (i=0; i<NS; i++)
    {
        for (j=0; j<ND; j++)
            scanf("%f",&a[i][j]);
        scanf("%f",&a[i][N]);
    }
    puts("Enter the objective function");
    for (j=0; j<ND; j++)
        scanf("%f",&c[j]);
    /* Now calculate cj and identify the incoming variable */
    while (1)
    {
        max = 0;
        kj = 0;
        for (j=0; j<N; j++)
        {
            z = 0;
            for (i=0; i<NS; i++)
                z += cb[i]*a[i][j];
            cj = c[j]-z;
            if(cj > max)
            {
                max = cj;
                kj = j;
            }
        }
        /* Apply the optimality test */
        if(max <= 0) break;
        /* Now calculate thetas */
        max = 0;
        for (i=0; i<NS; i++)
            if(a[i][kj] != 0)
            {
                th[i] = a[i][N]/a[i][kj];
                if(th[i] > max) max=th[i];
            }
        /* Now check for unbounded soln. */
        if(max <= 0)
        {
            puts("Unbounded solution");
            return 2;
        }
        /* Now search for the outgoing variable */
        min = max;
        ki = 0;
        for (i=0; i<NS; i++)
            if ((th[i] < min)&&(th[i] != 0))
            {
                min = th[i];
                ki = i;
            }
        /*Now a[ki][kj] is the key element*/
        t = a[ki][kj];
        /*Divide the key row by key element*/
        for (j=0; j<N+1; j++) a[ki][j] /= t;
        /* Make all other elements of key coloumn zero */
        for (i=0; i<NS; i++)
            if(i != ki)
            {
                b = a[i][kj];
                for (k=0; k<N+1; k++)
                    a[i][k]-=a[ki][k]*b;
            }
        cb[ki] = c[kj];
        bas[ki] = kj;
    }
    /* Now calculating the optimum value */
    for (i=0; i<NS; i++)
        if ((bas[i] >= 0) && (bas[i]<ND))
            x[bas[i]] = a[i][N];
    z = 0;
    for (i=0; i<ND; i++)
        z += c[i]*x[i];
    for (i=0; i<ND; i++)
        printf("x[%3d] = %7.2f\n",i+1,x[i]);
    printf("Optimal value = %7.2f\n",z);
}
/*
Enter the constraints
4 2 80
2 5 180
Enter the objective function
3 4
x[ 1] = 2.50
x[ 2] = 35.00
Optimal value = 147.50
*/

/*
Enter the constraints
2 3 2 440
4 0 3 470
2 5 0 430
Enter the objective function
4 3 6
x[ 1] = 0.00
x[ 2] = 42.22
x[ 3] = 156.67
Optimal value = 1066.67
*/
