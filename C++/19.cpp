/* derivatives using forward difference*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main( )
{
    float *x=NULL, *y=NULL,max;
    float *tmp = NULL;
    float xval,h,p,x0,y0,yval,sum;
    int pos,i;
    cout<<"enter the no of comparisons";
    cin>>max;
    x=new float[max];
    y=new float[max];
    cout<<"enter the values in cv table for x and y";
    for (i=0; i<max; i++)
    {
        cout<<"\n value for "<<i<<"x";
        cin>>x[i];
        cout<<"\n value for "<<i<<"y";
        cin>>y[i];
    }
    cout<<"enter the value of x";
    cin>>xval;
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
    cout<<"\nx0 is "<<x0<<"y0 is "<<y0<<"at"<<pos;
    h=x[1]-x[0];
    p=(xval-x0)/h;
    if(pos<(max))
    {
        int i,l,j;
// calculating no of elements in array
        l=max-pos;
        tmp= new float [l* l];
        cout<<"\n";
        for(i=0; i<l; i++)
        {
            for(j=0; j<=l; j++)
            {
                tmp[i*l+j]=0;
            }
            cout<<"\n";
        }
        cout<<"\n size of new array" <<l<<"\n";
//copying values of y in array
        for(i=0, j=pos; i<l; i++, j++)
        {
            tmp[i]=y[j];
        }
        cout<<"\n";
        for(i=1; i<l; i++)
        {
            for(j=0; j<l-i; j++)
            {
                tmp[i*l+j]=tmp[(i-1)*l+(j+1)]-tmp[(i-1)*l+(j)];
            }
        }
        cout<<"\nvalues are \n";
        for(i=0; i<l; i++)
        {
            cout<<x[i+pos]<<"\t";
            for(j=0; j<l; j++)
            {
                cout<<setprecision(3)<<tmp[j*l+i]<<"\t|";
            }
            cout<<"\n";
        }
//appling newtons forward diffenation using first derivates
        sum=0;
        int k=1;
        for(i=1; i<l; i++)
        {
            sum=sum+((1.0/i)*tmp[i]*tmp[i*l+0]*k);
                     k=-k;
        }
        cout<<"\n\n first (dy/dx): "<<sum/h;
        int v[]= {0,0,1.0, 1.0, 11.0/12.0,5.0/6.0,137.0/180.0};
        sum=0;
        k=1;
        for(i=2; i<l; i++)
        {
            sum=sum+(v[i]*tmp[i*l+0]*k);
            k=-k;
        }
        cout<<"\n\n second (dy/dx): "<<sum/pow(h,2.0);
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
x0 is 1.1y0 is 8.403at1
size of new array 6
values are
1.1 8.403 |0.378 |-0.03 |0.004 |-0.001 |0.003 |
1.2 8.781 |0.348 |-0.026 |0.003 |0.002 |0 |
1.3 9.129 |0.322 |-0.023 |0.005 |0 |0 |
1.4 9.451 |0.299 |-0.018 |0 |0 |0 |
1.5 9.75 |0.281 |0 |0 |0 |0 |
1.6 10.031 |0 |0 |0 |0 |0 |
First (dy/dx): 3.952
second (dy/dx): -3.74
*/
