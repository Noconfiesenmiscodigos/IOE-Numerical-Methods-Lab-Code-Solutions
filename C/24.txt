/* Runge Kutta Method */
#include <stdio.h>
float f(float x,float y)
{
    return x+y*y;
}
main()
{
    float x0,y0,h,xn,x,y,k1,k2,k3,k4,k;
    printf("Enter the values of x0,y0," "h,xn\n");
    scanf ("%f %f %f %f",&x0,&y0,&h,&xn);
    x = x0;
    y = y0;
    while (1)
    {
        if (x == xn) break;
        k1 = h*f(x,y);
        k2 = h*f(x+h/2,y+k1/2);
        k3 = h*f(x+h/2,y+k2/2);
        k4 = h*f(x+h,y+k3);
        k = (k1+(k2+k3)*2+k4)/6;
        x += h;
        y += k;
        printf("When x = %8.4f"
               "y = %8.4f\n",x,y);
    }
}

/*
Enter the values of x0, y0, h, xn
0.0 1.0 0.2 0.2
When x = 0.1000 y = 1.1165
When x = 0.2000 y = 1.2736
*/
