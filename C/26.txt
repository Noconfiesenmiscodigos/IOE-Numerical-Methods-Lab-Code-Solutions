/*Adams-Bashforth Method*/
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<conio.h>
void main( )
{
    float *x, *y, *f, *f1;
    float h;
    int i,size,row;
    printf("enter the size ");
    scanf("%d",&size);
    x=(float*)malloc(size + 1);
    y=(float*)malloc(size+1);
    f1=(float*)malloc(size+1);
    f=(float*)malloc(size + 1);
    for (i=0; i<size; i++)
    {
        printf("enter the value for x[%d] ",i);
        scanf("%f",&x[i]);
    }
    for(i=0; i<size; i++)
    {
        printf("enter the value for y[%d] ",i);
        scanf("%f",&y[i]);
    }
    h=x[1]-x[0];
// calculating values (f)
    for(i=0; i<size; i++)
    {
        float tx,ty,tf;
        fflush(stdin);
        tx=x[i];
        ty=y[i];
        tf=(pow(tx,2)*(1.0+ty));
        f[i]=tf;
    }
    printf("\nvalues for (x) (y) and (f) are\n");
    row = 16;
    for(i=0; i<=3; i++)
    {
        //gotoxy(2,row);
        printf("\nx=");
        //gotoxy(6,row);
        printf("\t\t%.1f",x[i]);
        //gotoxy(13,row);
        printf("\t\ty%d",i-3);
        //gotoxy(16,row);
        printf("\t\t=");
        //gotoxy(18,row);
        printf("\t\t%f",y[i]);
        //gotoxy(28,row);
        printf("\t\tf%d",i-3);
        //gotoxy(32,row);
        printf("\t\t=");
        //gotoxy(35,row);
        printf("\t\t%f",f[i]);
        row++;
    }
//using predicator
    y[size]=y[size-1]+((h/24)*((55*f[size-1])-59*f[size-2])+37*f[size-3])-(9*f[size-4]);
    x[size] = 1.4;
    f[size]=pow(x[size],2)*(1.0+y[size]);
    //gotoxy(2,row);
    printf("\nx=");
    //gotoxy(6,row);
    printf("\t\t%.1f",x[size]);
    //gotoxy(13,row);
    printf("\t\ty1");
    //gotoxy(16,row);
    printf("\t\t=");
    //gotoxy(18,row);
    printf("\t\t%f",y[size]);
    //gotoxy(28,row);
    printf("\t\tf1");
    //gotoxy(32,row);
    printf("\t\t=");
    //gotoxy(35,row);
    printf("\t\t%f",f[size]);
}

/*
enter the size 4
enter the value for x[0] 2
enter the value for x[1] 3
enter the value for x[2] 4
enter the value for x[3] 5
enter the value for y[0] 1
enter the value for y[1] 7
enter the value for y[2] 3
enter the value for y[3] 5

values for (x) (y) and (f) are

x=              2.0             y-3             =               1.000000                f-3             =               8.000000
x=              3.0             y-2             =               7.000000                f-2             =               72.000000
x=              4.0             y-1             =               3.000000                f-1             =               64.000000
x=              5.0             y0              =               5.000000                f0              =               150.000000
x=              1.4             y1              =               2783.416748             f1              =               5457.456543
*/
