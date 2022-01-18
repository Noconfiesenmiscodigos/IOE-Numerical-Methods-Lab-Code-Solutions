/* Modified Euler's Method*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main( )
{
    int i,j;
    float x,y,x1=0.0,y1=0.0,h,ms=0.0,flag=0,y2=0.0,t=0.0;
    cout<<"\nenter the value of x ";
    cin>>x;
    cout<<"enter the value of y ";
    cin>>y;
    cout<<"enter the height ";
    cin>>h;
    i=7;
    j=2;
    cout<<"\nx";
    cout<<"\t\tx+y=y1";
    cout<<"\t\tmean slope";
    //gotoxy(45,i);
    cout<<"\t\told y+.1(mean slope)new y"; while(x1<x)
    {
        i++;
    do
    {
        i++;
        if(flag==0)
        {
            y1=x1+y;
            cout<<"\n"<<x1;
            //gotoxy(10,i);
            cout<<"\t\t"<<y1;
            //gotoxy(28,i);
            cout<<"\t\t"<<ms;
            ms=y1;
            y2=y+h*ms;
            //gotoxy(45,i);
            cout<<"\t\t"<<y2;
            x1=x1+h;
            flag=1;
        }
        else
        {
            ms=(y1+(x1+y2))/2.0;
            t=y+h*ms;
            if(y2==t)
            {
                y2=y+h*ms;
                break;
            }
            //gotoxy(2,i);
            cout<<"\n"<<x1;
            //gotoxy(10,i);
            cout<<"\t\t"<<x1<<"+"<<"\t\t"<<y2;
            y2=y+h*ms;
            //gotoxy(28,i);
            cout<<"\t\t"<<ms;
           //gotoxy(45,i);
            cout<<"\t\t"<<y2;
        }
    }
    while(1);
    y=y2;
    cout<<"\n";
    flag=0;
    }
    getchar( );
}

/*
enter the value of x .3
enter the value of y 1
enter the height .1

x               x+y=y1          mean slope              old y+.1(mean slope)new y
0               1               0               1.1
0.1             0.1+            1.1             1.1             1.11
0.1             0.1+            1.11            1.105           1.1105
0.1             0.1+            1.1105          1.10525         1.11053
0.1             0.1+            1.11053         1.10526         1.11053
0.1             0.1+            1.11053         1.10526         1.11053

0.1             1.21053         1.10526         1.23158
0.2             0.2+            1.23158         1.32105         1.24263
0.2             0.2+            1.24263         1.32658         1.24318
0.2             0.2+            1.24318         1.32686         1.24321
0.2             0.2+            1.24321         1.32687         1.24321
0.2             0.2+            1.24321         1.32687         1.24321

0.2             1.44321         1.32687         1.38753
0.3             0.3+            1.38753         1.56537         1.39975
0.3             0.3+            1.39975         1.57148         1.40036
0.3             0.3+            1.40036         1.57179         1.40039
0.3             0.3+            1.40039         1.5718          1.40039
*/
