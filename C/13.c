/* Parabolic fit by least squares */
#include <stdio.h>
main()
{
    float augm[3][4]= {{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    float t,a,b,c,x,y,xsq;
    int i,j,k,n;
    puts("Enter the no. of pairs of"
         "observed values:");
    scanf("%d",&n);
    augm[0][0] = n;
    for (i=0; i<n; i++)
    {
        printf("pair no. %d\n",i+1);
        scanf("%f %f",&x,&y);
        xsq = x*x;
        augm[0][1] += x;
        augm[0][2] += xsq;
        augm[1][2] += x*xsq;
        augm[2][2] += xsq*xsq;
        augm[0][3] += y;
        augm[1][3] += x*y;
        augm[2][3] += xsq*y;
    }
    augm[1][1] = augm[0][2];
    augm[2][1] = augm[1][2];
    augm[1][0] = augm[0][1];
    augm[2][0] = augm[1][1];
    puts("The augmented matrix is:-");
    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
            printf("%9.4f",augm[i][j]);
        printf("\n");
    }
    /* Now solving for a,b,c
    by Gauss Jordan Method */
    for (j=0; j<3; j++)
        for (i=0; i<3; i++)
            if (i!=j)
            {
                t = augm[i][j]/augm[j][j];
                for (k=0; k<4; k++)
                    augm[i][k]
                    -= augm[j][k]*t;
            }
    a = augm[0][3]/augm[0][0];
    b = augm[1][3]/augm[1][1];
    c = augm[2][3]/augm[2][2];
    printf("a = %8.4f b = %8.4f "
           "c = %8.4f\n",a,b,c);
}

/*
Enter the no. of pairs of observed values:
7
Pair No. 1
1 1.1
Pair No. 2
1.5 1.3
Pair No. 3
2 1.6
Pair No. 4
2.5 2
Pair No. 5
3.0 2.7
Pair No. 6
3.5 3.4
Pair No. 7
4.0 4.1
The augmented matrix is:-
7.0000 17.5000 50.7500 16.2000
17.5000 50.7500 161.8750 47.6500
50.7500 161.8750 548.1875 154.4750
a = 1.0357 b = -0.1929 c = 0.2429
*/
