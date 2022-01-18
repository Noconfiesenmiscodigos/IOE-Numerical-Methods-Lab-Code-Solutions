/* Multiplication of matrices */
#include <stdio.h>
#define MAX 20
typedef float matrix[MAX][MAX];
void getelems(matrix x,int m,int n)
{
    int i,j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&x[i][j]);
}
void printsol(matrix x,int m,int n)
{
    int i,j;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            printf("%5.1f",x[i][j]);
        printf("\n");
    }
}
void matmul(matrix a,matrix b,matrix c,
            int l, int m,int p, int q)
{
    float s;
    int i,j,k;
    printf("Enter the elements of the"
           "first matrix\n");
    getelems(a,l,m);
    printf("Enter the elements of the"
           "second matrix\n");
    getelems(b,p,q);
    for (i=0; i<l; i++)
        for (j=0; j<q; j++)
        {
            s = 0;
            for (k=0; k<m; k++)
                s += a[i][k]*b[k][j];
            c[i][j] = s;
        }
    printf("The solution is \n");
    printsol(c,l,q);
}
main()
{
    matrix a,b,c;
    int l,m,p,q;
    printf("Enter the row, coloumn of the"
           "first matrix\n");
    scanf("%d %d",&l,&m);
    printf("Enter the row, coloumn of the"
           "second matrix\n");
    scanf("%d %d",&p,&q);
    if (m!=p)
        printf("The two matrices cannot"
               "be multiplied\n");
    else
        matmul(a,b,c,l,m,p,q);
}

/*
Enter the row, column of the first matrix
3 3
Enter the row, column of the second matrix
3 2
Enter the elements of the first matrix
0 1 2
1 2 3
2 3 4
Enter the elements of the second matrix
1 -2
-1 0
2 -1
The solution is
3.0 -2.0
5.0 -5.0
7.0 -8.0
*/
