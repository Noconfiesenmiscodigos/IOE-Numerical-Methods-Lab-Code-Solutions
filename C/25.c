/*Milne predictor corrector*/
#include <stdio.h>
#include <math.h>
float x[5],y[5],h;
float f(int i)
{
    return x[i]-y[i]*y[i];
}
void corect()
{
    y[4] = y[2]+(h/3)*(f(2)+4*f(3)+f(4));
    printf("%23s %8.4f %8.4f \n", "",y[4],f(4));
}
main()
{
    float xr,aerr,yc;
    int i;
    puts("Enter the values of x0,xr,h,"
         "allowed error");
    scanf("%f %f %f %f",
          &x[0],&xr,&h,&aerr);
    puts("Enter the value of y[i], i=0,3");
    for (i=0; i<=3; i++) scanf("%f",&y[i]);
    for (i=1; i<=3; i++) x[i] = x[0]+i*h;
    puts(" x Predicted"
         " Corrected");
    puts(" y f" "y f");
    while (1)
    {
        if(x[3] = xr) return;
        x[4] = x[3]+h;
        y[4] = y[0]+
               (4*h/3)*(2*(f(1)+f(3))-f(2));
        printf("%6.2f %8.4f %8.4f\n",
               x[4],y[4],f(4));
        corect();
        while (1)
        {
            yc = y[4];
            corect();
            if(fabs(yc-y[4]) <= aerr) break;
        }
        for (i=0; i<=3; i++)
        {
            x[i] = x[i+1];
            y[i] = y[i+1];
        }
    }
}
/*
Enter the values of x0, xr, h, allowed error
0 1.2.0001
Enter values of y[i]; i = 0, 3
0.02.0795.1762
x Predicted Corrected
y f y f
0.80 0.3049 0.7070
0.3046 0.7072
0.3046 0.7072
1.00 0.4554 0.7926
0.4556 0.7925
0.4556 0.7925
*/
