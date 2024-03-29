/*Method of Moments*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int x[10],y[10],i,n,yt=0,x1yt=0;
    float a,b,l1,l2,c1,c2,c3,d,d1,d2,m1,m2,h;
    cout<<"enter the no. of observations"<<endl;
    cin>>n;
    cout<<"enter the different values of x"<<endl;
    for(i=1; i<=n; i++)
    {
        cin>>x[i];
    }
    cout<<"\nenter the corresponding values of y"<<endl;
    for(i=1; i<=n; i++)
    {
        cin>>y[i];
    }
    h=x[2]-x[1];
    for(i=1; i<=n; i++)
    {
        yt+=y[i];
        x1yt+=x[i]*y[i];
    }
    m1=h*yt;
    m2=h*x1yt;
    l1=(-(h/2)+x[1]);
    l2=((h/2)+x[n]);
    c1=(l2-l1);
    c2=((l2*l2)-(l1*l1)/2);
    c3=(l2*l2*l2)-(l1*l1*l1)/3;
    cout<<"The observed equations are"<<endl<<c1<<"a+"<<c2<<"b"<<endl<<"&"<<c2<<"a+"<<c3<<"b";
    d=c2/c1;
    d1=d*c1;
    d2=d*c2;
    m1=d*m1;
    b=(m2-m1)/(c3-d2);
    a=(m1-(d2*b))/d1;
    cout<<"\nOn solving these equations we get a="<<setw(5)<<setprecision(2)<<a<<" & b="<<setw(5)<<setprecision(2)<<b<<endl;
    cout<<"hence the required equation is y="<<setw(5)<<setprecision(2)<<a<<"+"<< setw(5)<<setprecision(2)<<b<<"x";
    getchar();
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
&10.00a+30.33b=227.00
on solving these equations we get a=13.03&b=3.19
hence the required equation is y=13.03+3.19x
*/
