/*Method of Group Averages*/
#include<conio.h>
#include<stdio.h>
void main()
{
    int t[10],n,i,ts1=0,ts2=0;
    float a,b,rs1=0,rs2=0,r[10],x1,y1,x2,y2;
    printf("enter the no. of observations\n");
    scanf("%d",&n);
    printf("enter the different values of t\n");
    for (i=1; i<=n; i++)
    {
        scanf("%d",&t[i]);
    }
    printf("\n enter the corresponding values of r\n");
    for (i=1; i<=n; i++)
    {
        scanf("%f",&r[i]);
    }
    for (i=1; i<=(n/2); i++)
    {
        ts1+=t[i];
        rs1+=r[i];
    }
    for (i=((n/2)+1); i<=n; i++)
    {
        ts2+=t[i];
        rs2+=r[i];
    }
    x1=ts1/(n/2);
    y1=rs1/(n/2);
    x2=ts2/(n/2);
    y2=rs2/(n/2);
    b=(y2-y1)/(x2-x1);
    a=y1-(b*x1);
    printf("the value of a&b comes out to be\n");
    printf("a=%6.3f\nb=%6.3f",a,b);
    getch();
}

/*
Enter the no. of observations
8
enter the different values of t
40 50 60 70 80 90 100 110
enter the corresponding values of r
1069.1 1063.6 1058.2 1052.7 1049.3 1041.8 1036.3 1030.8
the values of a&b come out to be
a=1090.256
b=-0.534
*/
