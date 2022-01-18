/*Newton’s Divided Difference Formula*/
#include<stdio.h>
#include<conio.h>
void main()
{
    int x[10], y[10], p[10];
    int k,f,n,i,j=1,f1=1,f2=0;
    printf("enter the no. of observations\n");
    scanf("%d",&n);
    printf("enter the different values of x\n");
    for (i=1; i<=n; i++)
    {
        scanf("%d",&x[i]);
    }
    printf("enter the corresponding values of y\n");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&y[i]);
    }
    f=y[1];
    printf("enter the value of 'k' in f(k) you want to evaluate\n");
    scanf("%d",&k);
    do
    {
        for(i=1; i<=n-1; i++)
        {
            p[i]=((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
        }
        f1=1;
        for(i=1; i<=j; i++)
        {
            f1*=(k-x[i]);
        }
        f2+=(y[1]*f1);
        n--;
        j++;
    }
    while(n!=1);
    f+=f2;
    printf("f(%d)=%d",k,f);
    getch();
}

/*
Enter the no. of observations
5
enter the different values of x
5 7 11 13 17
enter the corresponding values of y
150 392 1452 2366 5202
enter the value of 'k' in f(k) you want to evaluate
9
f(9) = 810
*/
