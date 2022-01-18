/*Adams-Bashforth Method*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main( )
{
    float *x, *y, *f;
    float h;
    int i,size,row;
    cout <<"enter the size ";
    cin>>size;
    x=new float[size+1];
    y=new float[size+1];
    f=new float[size+1];
    for (i=0; i<size; i++)
    {
        cout<<"enter the value for x["<<i<<"] ";
        cin>>x[i];
        cout<<"enter the value for y["<<i<<"] ";
        cin>>y[i];
    }
    h=x[1]-x[0];
// calculating values [f]
    for(i=0; i<4; i++)
    {
        f[i]=pow(x[i],2)*(1.0+y[i]);
    }
    cout<<"\nvalues for (x) (y) and (f) are\n";
    row=16;
    for(i=0; i<4; i++)
    {
        //gotoxy(2,row);
        cout<<"\nx=";
        //gotoxy(6,row);
        cout<<"\t\t"<<x[i];
        //gotoxy(13,row);
        cout<<"\t\t"<<"y"<<"\t\t"<<i-3;
        //gotoxy(16,row);
        cout<<"\t\t"<<"=";
        //gotoxy(18,row);
        cout<<"\t\t"<<y[i];
        //gotoxy(28,row);
        cout<<"\t\t"<<"f"<<"\t\t"<<i-3;
        //gotoxy(32,row);
        cout<<"\t\t"<<"=";
        //gotoxy(35,row);
        cout<<"\t\t"<<f[i];
        row++;
    }
//using predicator
    y[size]=y[size-1]+((h/24)*((55*f[size-1])-(59*f[size-2])+(37*f[size-3])-(9*f[size-4])));
    x[size]=1.4;
    f[size]=pow(x[size],2)*(1.0+y[size]);
    //gotoxy(2,row);
    cout<<"\n\nx=";
    //gotoxy(6,row);
    cout<<"\t\t"<<x[size];
    //gotoxy(13,row);
    cout<<"\t\t"<<"y1";
    //gotoxy(16,row);
    cout<<"\t\t"<<"=";
    //gotoxy(18,row);
    cout<<"\t\t"<<y[size];
    //gotoxy(28,row);
    cout<<"\t\t"<<"f1";
    //gotoxy(32,row);
    cout<<"\t\t"<<"=";
    //gotoxy(35,row);
    cout<<"\t\t"<<f[size];
}
/*
enter the size 4
enter the value for x[0] 1
enter the value for y[0] 1
enter the value for x[1] 1.1
enter the value for y[1] 1.233
enter the value for x[2] 1.2
enter the value for y[2] 1.548
enter the value for x[3] 1.3
enter the value for y[3] 1.979

values for (x) (y) and (f) are

x=              1               y               -3              =               1               f               -3              =               2
x=              1.1             y               -2              =               1.233           f               -2              =               2.70193
x=              1.2             y               -1              =               1.548           f               -1              =               3.66912
x=              1.3             y               0               =               1.979           f               0               =               5.03451

x=              1.4             y1              =               2.5723          f1              =               7.0017
*/
