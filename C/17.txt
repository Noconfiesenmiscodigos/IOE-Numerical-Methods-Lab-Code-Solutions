/*Lagrange's Interpolation*/
#include <stdio.h>
#define MAX 100
main()
{
    float ax [MAX+1],ay[MAX+1],nr,dr,x,y=0;
    int i,j,n;
    printf ("Enter the value of n\n");
    scanf("%d",&n);
    printf ("Enter the set of values\n");
    for (i=0; i<=n; i++)
        scanf ("%f%f",&ax[i],&ay[i]);
    puts("Enter the value of x for which"
         "value of y is wanted");
    scanf("%f",&x);
    for (i=0; i<=n; i++)
    {
        nr=dr=1;
        for(j=0; j<=n; j++)
            if (j!=i)
            {
                nr *= x-ax[j];
                dr *= ax[i]-ax[j];
            }
        y += (nr/dr)*ay[i];
    }
    printf ("When x=%4.1f y=%7.1f\n",x,y);
}

/*
Enter the value of n
4
Enter the set of values
5 150
7 392
11 1452
13 2366
17 5202
Enter the value of x for which value of y is wanted
9
When x = 9.0 y = 810.0
*/
