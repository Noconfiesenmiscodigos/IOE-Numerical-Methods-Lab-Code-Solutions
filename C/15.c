/*Method of Moments */
#include <stdio.h>
#include <conio.h>
void main()
{
    int x[10],y[10],i,n,yt=0,x1yt=0;
    float a,b,b1,b2,c1,c2,c3,d,d1,d2,m1,m2,h;
    printf("enter the no. of observations\n");
    scanf("%d",&n);
    printf("enter the different values of x");
    for (i=1; i<n; i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\nenter the corresponding values of y\n");
    for (i=1; i<n; i++)
    {
        scanf("%d",&y[i]);
    }
    h=x[2]-x[1];
    for(i=1; i<=n; i++)
    {
        yt+=y[i];
        x1yt+=x[i]*y[i];
    }
    m1=h*yt;
    m2=h*x1yt;
    b1=(-(h/2)+x[1]);
    b2=((h/2)+x[n]);
    c1=(b2-b1);
    c2=((b2*b2)-(b1*b1))/2;
    c3=((b2*b2*b2)-(b1*b1*b1))/3;
    printf("The observed equations are\n");
    printf("%5.2fa+%5.2fb=%5.2f\n%5.2fa+5.2fb=%5.2f",
           c1,c2,m1,c2,c3,m2);
    d=c2/c1;
    d1=d*c1;
    d2=d*c2;
    m1=d*m1;
    b=(m2-m1)/(c3-d2);
    a=(m1-(d2*b))/d1;
    printf("\nOn solving these equations"
           "we get a=%5.2f&b=%5.2f\n",a,b);
    printf("hence the required equation is y=%5.2f+%5.2fx",a,b);
    getch ();
}

/*
Enter the no. of observations
4
enter the different values of x
1 2 3 4
enter the corresponding values of y
16 19 23 26
the observed equations are
4.00a+10.00b=84.00
10.00a+30.33b=227.00
on solving these equations we get a = 13.03&b=3.19
hence the required equation is y=13.03+3.19x
*/
