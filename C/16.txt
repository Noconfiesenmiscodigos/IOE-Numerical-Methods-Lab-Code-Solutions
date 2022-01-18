/* Newton's forward interpolation */
#include <stdio.h>
#define MAXN 100
#define ORDER 4
main()
{
    float ax[MAXN+1],ay[MAXN+1],
    diff[MAXN+1][ORDER+1],
    nr=1.0,dr=1.0,x,p,h,yp;
    int n,i,j,k;
    printf("Enter the value of n\n");
    scanf ("%d",&n);
    printf("Enter the values in form x,y\n");
    for (i=0; i<=n; i++)
        scanf("%f %f",&ax[i],&ay[i]);
    printf("Enter the values of x"
           "for which value of y is wanted \n");
    scanf("%f",&x);
    h=ax[1]-ax[0];
    /* now making the diff. table */
    /* calculating the 1st order differences */
    for (i=0; i<=n-1; i++)
        diff[i][1] = ay[i+1]-ay[i];
    /* calculating the second &
    higher order differences.*/
    for (j=2; j<=ORDER; j++)
        for (i=0; i<=n-j; i++)
            diff [i][j] = diff[i+1][j-1]
            -diff[i][j-1];
    /* now finding x0 */
    i=0;
    while (!(ax[i] > x)) i++;
    /* now ax[i] is x0 & ay[i] is y0 */
    i--;
    p = (x-ax[i])/h;
    yp=ay[i];
    /* Now carrying out interpolation */
    for (k=1; k<=ORDER; k++)
    {
        nr *= p-k+1;
        dr *=k;
        yp += (nr/dr)*diff[i][k];
    }
    printf ("when x = %6.1f, y = %6.2f\n"
            ,x,yp);
}

/*
Enter the value of n
6
Enter the values in form x, y
100 10.63
150 13.03
200 15.04
250 16.81
300 18.42
350 19.90
400 21.27
Enter the values of x for which value of y is wanted
218
When x = 218.0, y = 15.70
*/
