/*Euler's Method*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float df(float x,float y)
{
    return x+y;
}
int main()
{
    float x0,y0,h,x,x1,y1;
    cout << "Enter the values of x0,y0,h,x" << endl;
    cin >> x0 >> y0 >> h >> x;
    cout << fixed;
    x1=x0;
    y1=y0;
    while(1)
    {
        if(x1>x) return 0;
        y1 += h*df(x1,y1);
        x1 += h;
        cout << "When x = "
             << setw(3) << setprecision(1)
             << x1 << " y = "
             << setw(4) << setprecision(2)
             << y1 << endl;
    }
}
/*
Enter the values of x0, y0, h, x
0 1.1 1
When x = 0.1 y = 1.10
When x = 0.2 y = 1.22
When x = 0.3 y = 1.36
When x = 0.4 y = 1.53
When x = 0.5 y = 1.72
When x = 0.6 y = 1.94
When x = 0.7 y = 2.20
When x = 0.8 y = 2.49
When x = 0.9 y = 2.82
When x = 1.0 y = 3.19
*/
