/* Derivatives using forward difference */
#include<stdio.h>
#include<math.h>
#include<conio.h>
void main( )
{
    float *x=NULL, *y=NULL;
    float *tmp=NULL, *tmp1=NULL;
    float xval,h,p,x0,y0,yval,sum;
    int pos,i,k,max;
    int v[]= {0,0,1.0,1.0,11.0/12.0,5.0/6.0,137.0/180.0};
    printf ("Enter the no of comparisons");
    scanf("%d",&max);
    x=(float*) malloc(max);
    x=(float*) malloc(max);
    tmp=(float*) malloc(max);
    printf("Enter the values in cv table for x and y");
    for (i=0; i<max; i++)
    {
        printf("\n value for %d x",i);
        scanf("%f",&x[i]);
    }
    for(i=0; i<max; i++)
    {
        printf("\n value for %d y",i);
        scanf("%f",&y[i]);
    }
    printf("Enter the value of x");
    scanf("%f",&xval);
    for(i=0; i<max; i++)
    {
        if(x[i]>=xval)
        {
            pos=i;
            break;
        }
    }
    x0=x[pos];
    y0=y[pos];
    printf("\n x0 is %f y0 is %f at %d",x0,y0,pos);
    h=x[1]-x[0];
    p=(xval-x0)/h;
    if(pos<(max))
    {
        int fact=1,i,l, j;
// calculating no of elemets in array
        l=max-pos;
        tmp=(float*)malloc(l*l);
        printf("\n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<=l; j++)
            {
                tmp[i*l+j]=0;
            }
            printf("\n");
        }
        printf("\n size of new array %d\n",l);
// copying values of y in array
        for(i=0, j=pos; i<l; i++, j++)
        {
            tmp[i] = y[j];
        }
        printf("\n");
        for(i=1; i<l; i++)
        {
            for(j=0; j<(l-i); j++)
            {
                tmp[i*l+j]=tmp[(i-1)*l+(j+1)] - tmp[(i-1)*l+(j)];
            }
        }
        printf("\nvalues are \n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
            {
                printf("%.3f\t|",tmp[j*l+i]);
            }
            printf("\n");
        }
// appling newtons forward differnation using first derivates
        sum=0;
        k=1;
        for(i=1; i<l; i++)
        {
            sum=sum+((1.0/i)*tmp[i*l+0])*k;
            k=-k;
        }
        printf("\n\n first (dy/dx): %f ",sum/h);
        sum=0;
        fact=1;
        k=1;
        for(i=2; i<l; i++)
        {
            sum=sum+(v[i]*tmp[i*l+0])*k;
            k=-k;
        }
            printf("\n\n second (dy/dx): %f ",sum/pow(h,2.0));
    }
}

/*
value for 0x1.0
value for 0y7.989
value for 1x1.1
value for 1y8.403
value for 2x1.2
value for 2y8.781
value for 3x1.3
value for 3y9.129
value for 4x1.4
value for 4y9.451
value for 5x1.5
value for 5y9.750
value for 6x1.6
value for 6y10.031
Enter the value of x1.1
x0 is 1.1y0 is 8.403 at 1
size of new aray 6
values are
1.1 8.403 |0.378 |–0.03 |0.004 |–0.001 |0.003 |
1.2 8.781 |0.348 |–0.026 |0.003 |0.002 |0 |
1.3 9.129 |0.322 |–0.023 |0.005 |0 |0 |
1.4 9.451 |0.299 |–0.018 |0 |0 |0 |
1.5 9.75 |0.281 |0 |0 |0 |0 |
1.6 10.031 |0 |0 |0 |0 |0 |
first (dy/dx): 3.952
second (dy/dx): –3.74
*/
